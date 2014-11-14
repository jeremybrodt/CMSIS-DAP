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

#include "../FlashOS.H"        // FlashOS Structures
#include "flc_regs.h"
#include "device_cfg.h"

#define FLC_CN_UNLOCK_VALUE   0x20000000UL

// Allocate space for the device config and fill it with some dummy values so the compiler keeps it.
volatile const device_cfg_t device_cfg = {
  0x11111111,
  0x22222222,
  0x33333333,
  0x44444444,
};

/******************************************************************************/
/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */
int Init(unsigned long adr, unsigned long clk, unsigned long fnc)
{
  mxc_flc_regs_t *flc = (mxc_flc_regs_t*)device_cfg.flc_base;

  /* Check if the flash controller is busy */
  if (flc->cn & MXC_F_FLC_CN_PEND) {
    return 1;
  }

  // Set flash clock divider to generate a 1MHz clock from the APB clock
  flc->clkdiv = device_cfg.clkdiv_value;

  return  0;  // Finished without Errors
}

/******************************************************************************/
/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */
int UnInit(unsigned long fnc)
{
  mxc_flc_regs_t *flc = (mxc_flc_regs_t*)device_cfg.flc_base;

  /* Lock flash */
  flc->cn &= ~MXC_F_FLC_CN_UNLOCK;

  return  0;  // Finished without Errors
}

/******************************************************************************/
static int PrepareFLC(void)
{
  mxc_flc_regs_t *flc = (mxc_flc_regs_t*)device_cfg.flc_base;

  /* Check if the flash controller is busy */
  if (flc->cn & MXC_F_FLC_CN_PEND) {
    return 1;
  }

  /* Clear stale errors and disable interrupts */
  if (flc->intr != 0) {
    flc->intr = 0;
    if (flc->intr != 0) {
      flc->intr = MXC_F_FLC_INTR_AF;
      if (flc->intr != 0) {
        return 1;
      }
    }
  }

  /* Unlock flash */
  flc->cn = (flc->cn & ~MXC_F_FLC_CN_UNLOCK) | FLC_CN_UNLOCK_VALUE;

  return 0;
}

/******************************************************************************/
/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */
int EraseChip(void)
{
  mxc_flc_regs_t *flc = (mxc_flc_regs_t*)device_cfg.flc_base;

  /* Prepare for the flash operation */
  if (PrepareFLC() != 0) {
    return 1; // Operation failed
  }

  /* Write mass erase code */
  flc->cn = (flc->cn & ~MXC_F_FLC_CN_ERASE_CODE) | MXC_S_FLC_CN_CODE_MASS_ERASE;

  /* Issue mass erase command */
  flc->cn |= MXC_F_FLC_CN_ME;

  /* Wait until flash operation is complete */
  while (flc->cn & MXC_F_FLC_CN_PEND);

  /* Lock flash */
  flc->cn &= ~MXC_F_FLC_CN_UNLOCK;

  /* Check access violations */
  if (flc->intr & MXC_F_FLC_INTR_AF) {
    return 1; // Operation failed
  }

  return  0;  // Finished without Errors
}

/******************************************************************************/
/*
 *  Erase Sector in Flash Memory
 *    Parameter:      address:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */
int EraseSector(unsigned long address)
{
  mxc_flc_regs_t *flc = (mxc_flc_regs_t*)device_cfg.flc_base;

  /* Prepare for the flash operation */
  if (PrepareFLC() != 0) {
    return 1; // Operation failed
  }

  /* Write page erase code */
  flc->cn = (flc->cn & ~MXC_F_FLC_CN_ERASE_CODE) | MXC_S_FLC_CN_CODE_PAGE_ERASE;

  /* Issue page erase command */
  flc->addr = address;
  flc->cn |= MXC_F_FLC_CN_PGE;

  /* Wait until flash operation is complete */
  while (flc->cn & MXC_F_FLC_CN_PEND);

  /* Lock flash */
  flc->cn &= ~MXC_F_FLC_CN_UNLOCK;

  /* Check access violations */
  if (flc->intr & MXC_F_FLC_INTR_AF) {
    return 1; // Operation failed
  }

  return  0;  // Finished without Errors
}

/******************************************************************************/
/*
 *  Program Page in Flash Memory
 *    Parameter:      address:  Page Start Address
 *                    size:     Page Size
 *                    buffer:   Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */
int ProgramPage(unsigned long address, unsigned long size, unsigned char *buffer8)
{
  mxc_flc_regs_t *flc = (mxc_flc_regs_t*)device_cfg.flc_base;
  unsigned long remaining = size;
  unsigned long *buffer = (unsigned long *)buffer8;

  // Only accept 32-bit aligned pointers
  if ((unsigned long)buffer8 & 0x3) {
    return 1;
  }
  buffer = (unsigned long *)buffer8;

  /* Prepare for the flash operation */
  if (PrepareFLC() != 0) {
    return 1; // Operation failed
  }

  // write in 32-bit units until we are 128-bit aligned
  flc->cn &= ~MXC_F_FLC_CN_BRST;
  flc->cn |= MXC_F_FLC_CN_WDTH;

  while ( (remaining >= 4) && ((address & 0x1F) != 0) ) {
    flc->addr = address;
    flc->data0 = *buffer++;
    flc->cn |= MXC_F_FLC_CN_WR;

    /* Wait until flash operation is complete */
    while (flc->cn & MXC_F_FLC_CN_PEND);

    address += 4;
    remaining -= 4;
  }

  if ( (device_cfg.burst_size == 128) && (remaining >= 16) ) {

    // write in 128-bit bursts while we can
    flc->cn &= ~MXC_F_FLC_CN_WDTH;
    flc->cn |= MXC_F_FLC_CN_BRST;

    while (remaining >= 16) {
      flc->addr = address;
      flc->data0 = *buffer++;
      flc->data1 = *buffer++;
      flc->data2 = *buffer++;
      flc->data3 = *buffer++;
      flc->cn |= MXC_F_FLC_CN_WR;

      /* Wait until flash operation is complete */
      while (flc->cn & MXC_F_FLC_CN_PEND);

      address += 16;
      remaining -= 16;
    }
  }

  if (remaining >= 4) {
    // write in 32-bit units while we can
    flc->cn &= ~MXC_F_FLC_CN_BRST;
    flc->cn |= MXC_F_FLC_CN_WDTH;

    while (remaining >= 4) {
      flc->addr = address;
      flc->data0 = *buffer++;
      flc->cn |= MXC_F_FLC_CN_WR;

      /* Wait until flash operation is complete */
      while (flc->cn & MXC_F_FLC_CN_PEND);

      address += 4;
      remaining -= 4;
    }
  }

  if (remaining > 0) {
    uint32_t last_word;
    uint32_t mask;

    // write remaining bytes in a 32-bit unit
    flc->cn &= ~MXC_F_FLC_CN_BRST;
    flc->cn |= MXC_F_FLC_CN_WDTH;

    last_word = 0xffffffff;
    mask = 0xff;

    while (remaining > 0) {
      last_word &= (*buffer | ~mask);
      mask <<= 8;
      remaining--;
    }

    flc->addr = address;
    flc->data0 = last_word;
    flc->cn |= MXC_F_FLC_CN_WR;

    /* Wait until flash operation is complete */
    while (flc->cn & MXC_F_FLC_CN_PEND);
  }

  /* Lock flash */
  flc->cn &= ~MXC_F_FLC_CN_UNLOCK;

  /* Check access violations */
  if (flc->intr & MXC_F_FLC_INTR_AF) {
    return 1; // Operation failed
  }

  return  0;  // Finished without Errors
}
