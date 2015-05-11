/* CMSIS-DAP Interface Firmware
 * Copyright (c) 2009-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>
#include <RTL.h>
#include <rl_usb.h>
#include <absacc.h>

#include "max32550.h"
#include "gpio_regs.h"
#include "usb_regs.h"

#define __NO_USB_LIB_C
#include "usb_config.c"

#define EPNUM_MASK  (~USB_ENDPOINT_DIRECTION_MASK)

#define INIT_INTS     (MXC_F_USB_DEV_INTEN_BRST | MXC_F_USB_DEV_INTFL_BRST_DN | MXC_F_USB_DEV_INTEN_VBUS | MXC_F_USB_DEV_INTFL_NO_VBUS)
#define CONNECT_INTS  (MXC_F_USB_DEV_INTEN_SETUP | MXC_F_USB_DEV_INTEN_EP_IN | MXC_F_USB_DEV_INTEN_EP_OUT | MXC_F_USB_DEV_INTEN_DMA_ERR)

typedef struct {
	volatile uint32_t buf0_desc;
	volatile uint32_t buf0_address;
	volatile uint32_t buf1_desc;
	volatile uint32_t buf1_address;
} ep_buffer_t;

typedef struct {
	ep_buffer_t out_buffer;
	ep_buffer_t in_buffer;
} ep0_buffer_t;

typedef struct {
	ep0_buffer_t ep0;
	ep_buffer_t ep[MXC_USB_NUM_EP - 1];
} ep_buffer_descriptor_t;

typedef struct {
  U8 type;
  U16 len;
} ep_info_t;

/* static storage for endpoint buffer descriptor table, must be 512 byte alligned for DMA */
__attribute__ ((aligned (512))) 
ep_buffer_descriptor_t ep_buffer_descriptor;

static uint32_t ep_buffer[MXC_USB_NUM_EP][MXC_USB_MAX_PACKET / sizeof(uint32_t)];
static ep_info_t ep_info[MXC_USB_NUM_EP];
static volatile int suspended;
static volatile int setup_waiting;
static volatile int ep0_expect_zlp;

/******************************************************************************/
static ep_buffer_t *get_desc(U32 EPNum)
{
  ep_buffer_t *desc;

  if (EPNum == 0x80) {
    desc = &ep_buffer_descriptor.ep0.in_buffer;
  } else if (EPNum == 0x00) {
    desc = &ep_buffer_descriptor.ep0.out_buffer;
  } else {
    desc = &ep_buffer_descriptor.ep[(EPNum & EPNUM_MASK) - 1];
  }

  return desc;
}

/******************************************************************************/
/*
 *  Usb interrupt enable/disable
 *    Parameters:      ena: enable/disable
 *                       0: disable interrupt
 *                       1: enable interrupt
 */
#ifdef __RTX
void __svc(1) USBD_Intr (int ena);
void __SVC_1            (int ena)
{
  if (ena) {
    NVIC_EnableIRQ(USB_IRQn);           /* Enable USB interrupt               */
  } else {
    NVIC_DisableIRQ(USB_IRQn);          /* Disable USB interrupt              */
  }
}
#endif

/******************************************************************************/
static void reset_state(void)
{
  unsigned int ep;

  suspended = 0;
  setup_waiting = 0;
  ep0_expect_zlp = 0;
  memset(ep_info, 0, sizeof(ep_info));

  MXC_USB->ep[0] |= (MXC_S_USB_EP_DIR_CONTROL | MXC_F_USB_EP_INT_EN | MXC_F_USB_EP_DT);
  for (ep = 1; ep < MXC_USB_NUM_EP; ep++) {
    MXC_USB->ep[ep] = MXC_F_USB_EP_DT;
  }
}

/*
 *  USB Device Initialize Function
 *   Called by the User to initialize USB Device
 *    Return Value:    None
 */
void USBD_Init (void)
{
  // Configure VBUS detect pin
  MXC_GPIO2->en_clr = (0x1UL << 0);
  MXC_GPIO2->en1_clr = (0x1UL << 0);

  MXC_USB->cn = 0;
  MXC_USB->cn = MXC_F_USB_CN_EN;
  MXC_USB->dev_inten = 0;
  MXC_USB->dev_intfl = 0xFFFF;  // clear interrupts
  MXC_USB->dev_cn = 0;
  MXC_USB->dev_cn |= MXC_F_USB_DEV_CN_URST;
  MXC_USB->dev_cn = 0;

  reset_state();

  /* set the descriptor location */
  MXC_USB->ep_base = (uint32_t)&ep_buffer_descriptor;

  /* enable some interrupts */
  MXC_USB->dev_inten = INIT_INTS;
  NVIC_EnableIRQ(USB_IRQn);
}

/*
 *  USB Device Connect Function
 *   Called by the User to Connect/Disconnect USB Device
 *    Parameters:      con:   Connect/Disconnect
 *    Return Value:    None
 */
void USBD_Connect (BOOL con)
{
  if (con) {
    MXC_USB->dev_intfl = 0xFFFF;  // clear interrupts
    MXC_USB->dev_inten |= CONNECT_INTS;
    MXC_USB->ep[0] |= MXC_F_USB_EP_INT_EN;
    MXC_USB->dev_cn |= (MXC_F_USB_DEV_CN_CONNECT | MXC_F_USB_DEV_CN_FIFO_MODE);
  } else {
    MXC_USB->dev_inten &= ~CONNECT_INTS;
    MXC_USB->ep[0] &= ~MXC_F_USB_EP_INT_EN;
    MXC_USB->dev_cn &= ~MXC_F_USB_DEV_CN_CONNECT;
  }
}

/*
 *  USB Device Remote Wakeup Configuration Function
 *    Parameters:      cfg:   Device Enable/Disable
 *    Return Value:    None
 */
void USBD_WakeUpCfg (BOOL cfg)
{
}

/*
 *  USB Device Set Address Function
 *    Parameters:      adr:   USB Device Address
 *    Return Value:    None
 */
void USBD_SetAddress (U32 adr, U32 setup)
{
  /* Performed by Hardware */
}

/*
 *  USB Device Configure Function
 *    Parameters:      cfg:   Device Configure/Deconfigure
 *    Return Value:    None
 */
void USBD_Configure (BOOL cfg)
{
}

/*
 *  Configure USB Device Endpoint according to Descriptor
 *    Parameters:      pEPD:  Pointer to Device Endpoint Descriptor
 *    Return Value:    None
 */
void USBD_ConfigEP (USB_ENDPOINT_DESCRIPTOR *pEPD)
{
  U32 EPNum;

  EPNum = pEPD->bEndpointAddress & EPNUM_MASK;

  if (EPNum < MXC_USB_NUM_EP) {

    // Clear existing configurations
    MXC_USB->ep[EPNum] = MXC_F_USB_EP_DT;

    if (pEPD->bEndpointAddress & USB_ENDPOINT_DIRECTION_MASK) {
      ep_info[EPNum].type = MXC_S_USB_EP_DIR_IN;
    } else {
      ep_info[EPNum].type = MXC_S_USB_EP_DIR_OUT;
    }

    ep_info[EPNum].len = pEPD->wMaxPacketSize;
  }
}

/*
 *  Set Direction for USB Device Control Endpoint
 *    Parameters:      dir:   Out (dir == 0), In (dir <> 0)
 *    Return Value:    None
 */
void USBD_DirCtrlEP (U32 dir)
{
  /* Not needed */
}

/*
 *  Enable USB Device Endpoint
 *    Parameters:      EPNum: Device Endpoint Number
 *                       EPNum.0..3: Address
 *                       EPNum.7:    Dir
 *    Return Value:    None
 */
void USBD_EnableEP (U32 EPNum)
{
  ep_buffer_t *desc = get_desc(EPNum);

  EPNum &= EPNUM_MASK;
  MXC_USB->ep[EPNum] |= (MXC_F_USB_EP_INT_EN | ep_info[EPNum].type | MXC_F_USB_EP_DT);

  if (ep_info[EPNum].type == MXC_S_USB_EP_DIR_OUT) {
    // This is an OUT endpoint. Go ahead and register a request.
    desc = get_desc(EPNum);
    desc->buf0_address = (uint32_t)ep_buffer[EPNum];
    desc->buf0_desc = sizeof(ep_buffer[EPNum]);
    MXC_USB->out_owner = (1 << EPNum);
  }
}

/*
 *  Disable USB Device Endpoint
 *    Parameters:      EPNum: Device Endpoint Number
 *                       EPNum.0..3: Address
 *                       EPNum.7:    Dir
 *    Return Value:    None
 */
void USBD_DisableEP (U32 EPNum)
{
  EPNum &= EPNUM_MASK;
  MXC_USB->ep[EPNum] = 0;
}

/*
 *  Reset USB Device Endpoint
 *    Parameters:      EPNum: Device Endpoint Number
 *                       EPNum.0..3: Address
 *                       EPNum.7:    Dir
 *    Return Value:    None
 */
void USBD_ResetEP (U32 EPNum)
{
  ep_buffer_t *desc = get_desc(EPNum);

  EPNum &= EPNUM_MASK;
  MXC_USB->ep[EPNum] |= MXC_F_USB_EP_DT;

  if (ep_info[EPNum].type == MXC_S_USB_EP_DIR_OUT) {
    // This is an OUT endpoint. Go ahead and register a request.
    desc = get_desc(EPNum);
    desc->buf0_address = (uint32_t)ep_buffer[EPNum];
    desc->buf0_desc = sizeof(ep_buffer[EPNum]);
    MXC_USB->out_owner = (1 << EPNum);
  }
}

/*
 *  Set Stall for USB Device Endpoint
 *    Parameters:      EPNum: Device Endpoint Number
 *                       EPNum.0..3: Address
 *                       EPNum.7:    Dir
 *    Return Value:    None
 */
void USBD_SetStallEP (U32 EPNum)
{
  EPNum &= EPNUM_MASK;

  if (EPNum == 0) {
    MXC_USB->ep[0] |= (MXC_F_USB_EP_ST_STALL | MXC_F_USB_EP_STALL);
  } else {
    MXC_USB->ep[EPNum] |= MXC_F_USB_EP_STALL;
  }
}

/*
 *  Clear Stall for USB Device Endpoint
 *    Parameters:      EPNum: Device Endpoint Number
 *                       EPNum.0..3: Address
 *                       EPNum.7:    Dir
 *    Return Value:    None
 */
void USBD_ClrStallEP (U32 EPNum)
{
  USBD_ResetEP(EPNum);
  MXC_USB->ep[EPNum & EPNUM_MASK] &= ~MXC_F_USB_EP_STALL;
}

/*
 *  Read USB Device Endpoint Data
 *    Parameters:      EPNum: Device Endpoint Number
 *                       EPNum.0..3: Address
 *                       EPNum.7:    Dir
 *                     pData: Pointer to Data Buffer
 *    Return Value:    Number of bytes read
 */
U32 USBD_ReadEP (U32 EPNum, U8 *pData)
{
  ep_buffer_t *desc = get_desc(EPNum);
  U32 cnt = 0;
  USB_SETUP_PACKET *sup;

  EPNum &= EPNUM_MASK;

  if ((EPNum == 0) && setup_waiting) {
    setup_waiting = 0;
    cnt = 8; /* setup packet is fixed at 8 bytes */
    memcpy(pData, (void*)&MXC_USB->setup0, cnt);
    sup = (USB_SETUP_PACKET*)pData;

    if ( (sup->bmRequestType.Dir == REQUEST_HOST_TO_DEVICE) && (sup->wLength > 0) ) {
      // There is an OUT stage for this setup packet. Register a request.
      if (!(MXC_USB->out_owner & 1)) {
        desc = &ep_buffer_descriptor.ep0.out_buffer;
        desc->buf0_address = (uint32_t)ep_buffer[0];
        desc->buf0_desc = sup->wLength;
        MXC_USB->out_owner = 1;
      }
    }
  } else {
    cnt = desc->buf0_desc;
    memcpy(pData, ep_buffer[EPNum], cnt);

    if (EPNum != 0) {
      // Register the next request.
      desc->buf0_address = (uint32_t)ep_buffer[EPNum];
      desc->buf0_desc = sizeof(ep_buffer[EPNum]);
      MXC_USB->out_owner = (1 << EPNum);
    }
  }

  return cnt;
}

/*
 *  Write USB Device Endpoint Data
 *    Parameters:      EPNum: Endpoint Number
 *                       EPNum.0..3: Address
 *                       EPNum.7:    Dir
 *                     pData: Pointer to Data Buffer
 *                     cnt:   Number of bytes to write
 *    Return Value:    Number of bytes written
 */
U32 USBD_WriteEP (U32 EPNum, U8 *pData, U32 cnt)
{
  ep_buffer_t *desc = get_desc(EPNum);
  uint32_t mask;

  EPNum &= EPNUM_MASK;
  mask = (1 << EPNum);

  if (MXC_USB->in_owner & mask) {
    return 0;
  }

  if (EPNum == 0) {
    // Prepare to ACK the status stage.
    MXC_USB->ep[0] |= MXC_F_USB_EP_ST_ACK;

    if ((cnt == 0) && !ep0_expect_zlp) {
      // This is a status stage ACK. Handled in hardware.
      return 0;
    } else if (cnt == USBD_MAX_PACKET0) {
      ep0_expect_zlp = 1;
    } else {
      ep0_expect_zlp = 0;
    }
  }

  if (cnt > MXC_USB_MAX_PACKET) {
    cnt = MXC_USB_MAX_PACKET;
  }

  /* prepare data to be sent */
  memcpy(ep_buffer[EPNum], pData, cnt);
  desc->buf0_address = (uint32_t)ep_buffer[EPNum];
  desc->buf0_desc = cnt;

  /* start the transaction */
  MXC_USB->in_owner = mask;

  return cnt;
}

/*
 *  USB Device Interrupt Service Routine
 */
void USB_IRQHandler (void)
{
  mxc_usb_dev_intfl_t irq_flags;
  unsigned int ep;
  uint32_t ep_int, mask;

  // Read and clear interrupts
  irq_flags = MXC_USB->dev_intfl_f;
  MXC_USB->dev_intfl_f = irq_flags;

  /* reset interrupt */
  if (irq_flags.brst) {
    if (suspended) {
      suspended = 0;
      if (USBD_RTX_DevTask) { isr_evt_set(USBD_EVT_RESUME, USBD_RTX_DevTask); }
    }

    reset_state();
    usbd_reset_core();

    if (USBD_RTX_DevTask) { isr_evt_set(USBD_EVT_RESET, USBD_RTX_DevTask); }

  }

  /* reset done interrupt */
  if (irq_flags.brst_dn) {
    reset_state();
  }

  /* suspend interrupt */
  if (irq_flags.susp) {
    suspended = 1;
    if (USBD_RTX_DevTask) { isr_evt_set(USBD_EVT_SUSPEND, USBD_RTX_DevTask); }
  }

  if (irq_flags.vbus) {
    if (USBD_RTX_DevTask) { isr_evt_set(USBD_EVT_POWER_ON,  USBD_RTX_DevTask); }
  }

  if (irq_flags.no_vbus) {
    if (USBD_RTX_DevTask) { isr_evt_set(USBD_EVT_POWER_OFF, USBD_RTX_DevTask); }
  }

  if (irq_flags.setup) {
    setup_waiting = 1;
    if (USBD_RTX_EPTask[0]) { isr_evt_set(USBD_EVT_SETUP, USBD_RTX_EPTask[0]); }
  }

  if (irq_flags.ep_in) {

    // Read and clear endpoint interrupts
    ep_int = MXC_USB->in_int;
    MXC_USB->in_int = ep_int;

    mask = 1;
    for (ep = 0; ep < MXC_USB_NUM_EP; ep++) {
      if (ep_int & mask) {
        if (USBD_RTX_EPTask[ep]) { isr_evt_set(USBD_EVT_IN,  USBD_RTX_EPTask[ep]); }
      }

      mask <<= 1;
    }
  }

  if (irq_flags.ep_out) {

    // Read and clear endpoint interrupts
    ep_int = MXC_USB->out_int;
    MXC_USB->out_int = ep_int;

    mask = 1;
    for (ep = 0; ep < MXC_USB_NUM_EP; ep++) {
      if (ep_int & mask) {
        if (USBD_RTX_EPTask[ep]) { isr_evt_set(USBD_EVT_OUT, USBD_RTX_EPTask[ep]); }
      }

      mask <<= 1;
    }
  }

  if (irq_flags.dma_err) {
    // Read and clear endpoint interrupts
    ep_int = MXC_USB->dma_err_int;
    MXC_USB->dma_err_int = ep_int;
    while(1); // not recoverable
  }
}
