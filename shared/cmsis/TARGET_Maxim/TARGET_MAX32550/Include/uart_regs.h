/*******************************************************************************
* Copyright (C) 2014 Maxim Integrated Products, Inc., All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
*
* $Id: uart_regs.h 15272 2014-09-22 15:39:14Z jeremy.brodt $
*
********************************************************************************
*/

#ifndef _MXC_UART_REGS_H_
#define _MXC_UART_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*
    If types are not defined elsewhere (CMSIS) define them here
*/
#ifndef __IO
#define __IO volatile
#endif
#ifndef __I
#define __I  volatile const
#endif
#ifndef __O
#define __O  volatile
#endif
#ifndef __R
#define __R  volatile const
#endif

/* CTRL */
typedef struct {
  uint32_t rxthd   :4;
  uint32_t paren   :1;
  uint32_t pareo   :1;
  uint32_t parmd   :1;
  uint32_t rsv1    :1;
  uint32_t txflush :1;
  uint32_t rxflush :1;
  uint32_t size    :2;
  uint32_t stop    :1;
  uint32_t rtsctsf :1;
  uint32_t rsv2    :17;
} mxc_uart_ctrl_t;

/* STAT */
typedef struct {
  uint32_t txbusy  :1;
  uint32_t rxbusy  :1;
  uint32_t rsv1    :2;
  uint32_t rxempty :1;
  uint32_t rxfull  :1;
  uint32_t txempty :1;
  uint32_t txfull  :1;
  uint32_t rxelt   :4;
  uint32_t txelt   :4;
  uint32_t rsv2    :16;
} mxc_uart_stat_t;

/* INT_EN */
typedef struct {
  uint32_t framie   :1;
  uint32_t parityie :1;
  uint32_t signalie :1;
  uint32_t overie   :1;
  uint32_t ffrxie   :1;
  uint32_t fftxoie  :1;
  uint32_t fftxhie  :1;
  uint32_t rsv      :24;
} mxc_uart_int_en_t;

/* INT_STAT */
typedef struct {
  uint32_t framis   :1;
  uint32_t parityis :1;
  uint32_t signalis :1;
  uint32_t overis   :1;
  uint32_t ffrxis   :1;
  uint32_t fftxois  :1;
  uint32_t fftxhis  :1;
  uint32_t rsv      :24;
} mxc_uart_int_stat_t;

/* BAUD0 */
typedef struct {
  uint32_t idiv :12;
  uint32_t rsv  :20;
} mxc_uart_baud0_t;

/* BAUD1 */
typedef struct {
  uint32_t ddiv :7;
  uint32_t rsv  :25;
} mxc_uart_baud1_t;

/* PIN */
typedef struct {
  uint32_t cts :1;
  uint32_t rts :1;
  uint32_t rsv :30;
} mxc_uart_pin_t;

/* DATA */
typedef struct {
  uint32_t data   :8;
  uint32_t parity :1;
  uint32_t rsv    :23;
} mxc_uart_data_t;

/* DMA */
typedef struct {
  uint32_t txcnt :4;
  uint32_t txen  :1;
  uint32_t rxcnt :4;
  uint32_t rxen  :1;
  uint32_t rsv   :22;
} mxc_uart_dma_t;

/*                             Offset    Description
                               ====================== */
#pragma anon_unions
typedef struct {
  union {                   /* 0x0000    Control Register */
    __IO uint32_t ctrl;
    __IO mxc_uart_ctrl_t ctrl_f;
  };
  union {                   /* 0x0004    Status Register */
    __I  uint32_t stat;
    __I  mxc_uart_stat_t stat_f;
  };
  union {                   /* 0x0008    Interrupt Enable Register */
    __IO uint32_t int_en;
    __IO mxc_uart_int_en_t int_en_f;
  };
  union {                   /* 0x000C    Interrupt Status Register */
    __IO uint32_t int_stat;
    __IO mxc_uart_int_stat_t int_stat_f;
  };
  union {                   /* 0x0010    Baud Rate Register 0 */
    __IO uint32_t baud0;
    __IO mxc_uart_baud0_t baud0_f;
  };
  union {                   /* 0x0014    Baud Rate Register 1 */
    __IO uint32_t baud1;
    __IO mxc_uart_baud1_t baud1_f;
  };
  __IO uint32_t txr;        /* 0x0018    TX FIFO Output Register */
  union {                   /* 0x001C    Pin Control Register */
    __IO uint32_t pin;
    __IO mxc_uart_pin_t pin_f;
  };
  union {                   /* 0x0020    Data Buffer Register */
    __IO uint32_t data;
    __IO mxc_uart_data_t data_f;
  };
  __R  uint32_t rsv[3];     /* 0x0024    reserved */
  union {                   /* 0x0030    DMA Register */
    __IO uint32_t dma;
    __IO mxc_uart_dma_t dma_f;
  };
} mxc_uart_regs_t;

/* Register offsets */
#define MXC_R_UART_OFFS_CTRL     ((uint32_t)0x00000000UL)
#define MXC_R_UART_OFFS_STAT     ((uint32_t)0x00000004UL)
#define MXC_R_UART_OFFS_INT_EN   ((uint32_t)0x00000008UL)
#define MXC_R_UART_OFFS_INT_STAT ((uint32_t)0x0000000CUL)
#define MXC_R_UART_OFFS_BAUD0    ((uint32_t)0x00000010UL)
#define MXC_R_UART_OFFS_BAUD1    ((uint32_t)0x00000014UL)
#define MXC_R_UART_OFFS_TXR      ((uint32_t)0x00000018UL)
#define MXC_R_UART_OFFS_PIN      ((uint32_t)0x0000001CUL)
#define MXC_R_UART_OFFS_DATA     ((uint32_t)0x00000020UL)
#define MXC_R_UART_OFFS_DMA      ((uint32_t)0x00000030UL)

/* RXTHD */
#define MXC_F_UART_CTRL_RXTHD ((uint32_t)0x0000000FUL)
#define MXC_F_UART_CTRL_RXTHD_POS (0)

/* PAREN */
#define MXC_F_UART_CTRL_PAREN ((uint32_t)0x00000010UL)
#define MXC_F_UART_CTRL_PAREN_POS (4)

/* PAREO */
#define MXC_F_UART_CTRL_PAREO ((uint32_t)0x00000020UL)
#define MXC_F_UART_CTRL_PAREO_POS (5)

/* PARMD */
#define MXC_F_UART_CTRL_PARMD ((uint32_t)0x00000040UL)
#define MXC_F_UART_CTRL_PARMD_POS (6)

/* TXFLUSH */
#define MXC_F_UART_CTRL_TXFLUSH ((uint32_t)0x00000100UL)
#define MXC_F_UART_CTRL_TXFLUSH_POS (8)

/* RXFLUSH */
#define MXC_F_UART_CTRL_RXFLUSH ((uint32_t)0x00000200UL)
#define MXC_F_UART_CTRL_RXFLUSH_POS (9)

/* SIZE */
#define MXC_F_UART_CTRL_SIZE ((uint32_t)0x00000C00UL)
#define MXC_F_UART_CTRL_SIZE_POS (10)

#define MXC_S_UART_CTRL_SIZE_5 ((uint32_t)0x000UL)
#define MXC_S_UART_CTRL_SIZE_6 ((uint32_t)0x400UL)
#define MXC_S_UART_CTRL_SIZE_7 ((uint32_t)0x800UL)
#define MXC_S_UART_CTRL_SIZE_8 ((uint32_t)0xC00UL)

/* STOP */
#define MXC_F_UART_CTRL_STOP ((uint32_t)0x00001000UL)
#define MXC_F_UART_CTRL_STOP_POS (12)

/* RTSCTSF */
#define MXC_F_UART_CTRL_RTSCTSF ((uint32_t)0x00002000UL)
#define MXC_F_UART_CTRL_RTSCTSF_POS (13)

/* TXBUSY */
#define MXC_F_UART_STAT_TXBUSY ((uint32_t)0x00000001UL)
#define MXC_F_UART_STAT_TXBUSY_POS (0)

/* RXBUSY */
#define MXC_F_UART_STAT_RXBUSY ((uint32_t)0x00000002UL)
#define MXC_F_UART_STAT_RXBUSY_POS (1)

/* RXEMPTY */
#define MXC_F_UART_STAT_RXEMPTY ((uint32_t)0x00000010UL)
#define MXC_F_UART_STAT_RXEMPTY_POS (4)

/* RXFULL */
#define MXC_F_UART_STAT_RXFULL ((uint32_t)0x00000020UL)
#define MXC_F_UART_STAT_RXFULL_POS (5)

/* TXEMPTY */
#define MXC_F_UART_STAT_TXEMPTY ((uint32_t)0x00000040UL)
#define MXC_F_UART_STAT_TXEMPTY_POS (6)

/* TXFULL */
#define MXC_F_UART_STAT_TXFULL ((uint32_t)0x00000080UL)
#define MXC_F_UART_STAT_TXFULL_POS (7)

/* RXELT */
#define MXC_F_UART_STAT_RXELT ((uint32_t)0x00000F00UL)
#define MXC_F_UART_STAT_RXELT_POS (8)

/* TXELT */
#define MXC_F_UART_STAT_TXELT ((uint32_t)0x0000F000UL)
#define MXC_F_UART_STAT_TXELT_POS (12)

/* FRAMIE */
#define MXC_F_UART_INTEN_FRAMIE ((uint32_t)0x00000001UL)
#define MXC_F_UART_INTEN_FRAMIE_POS (0)

/* PARITYIE */
#define MXC_F_UART_INTEN_PARITYIE ((uint32_t)0x00000002UL)
#define MXC_F_UART_INTEN_PARITYIE_POS (1)

/* SIGNALIE */
#define MXC_F_UART_INTEN_SIGNALIE ((uint32_t)0x00000004UL)
#define MXC_F_UART_INTEN_SIGNALIE_POS (2)

/* OVERIE */
#define MXC_F_UART_INTEN_OVERIE ((uint32_t)0x00000008UL)
#define MXC_F_UART_INTEN_OVERIE_POS (3)

/* FFRXIE */
#define MXC_F_UART_INTEN_FFRXIE ((uint32_t)0x00000010UL)
#define MXC_F_UART_INTEN_FFRXIE_POS (4)

/* FFTXOIE */
#define MXC_F_UART_INTEN_FFTXOIE ((uint32_t)0x00000020UL)
#define MXC_F_UART_INTEN_FFTXOIE_POS (5)

/* FFTXHIE */
#define MXC_F_UART_INTEN_FFTXHIE ((uint32_t)0x00000040UL)
#define MXC_F_UART_INTEN_FFTXHIE_POS (6)

/* FRAMIS */
#define MXC_F_UART_INTSTAT_FRAMIS ((uint32_t)0x00000001UL)
#define MXC_F_UART_INTSTAT_FRAMIS_POS (0)

/* PARITYIS */
#define MXC_F_UART_INTSTAT_PARITYIS ((uint32_t)0x00000002UL)
#define MXC_F_UART_INTSTAT_PARITYIS_POS (1)

/* SIGNALIS */
#define MXC_F_UART_INTSTAT_SIGNALIS ((uint32_t)0x00000004UL)
#define MXC_F_UART_INTSTAT_SIGNALIS_POS (2)

/* OVERIS */
#define MXC_F_UART_INTSTAT_OVERIS ((uint32_t)0x00000008UL)
#define MXC_F_UART_INTSTAT_OVERIS_POS (3)

/* FFRXIS */
#define MXC_F_UART_INTSTAT_FFRXIS ((uint32_t)0x00000010UL)
#define MXC_F_UART_INTSTAT_FFRXIS_POS (4)

/* FFTXOIS */
#define MXC_F_UART_INTSTAT_FFTXOIS ((uint32_t)0x00000020UL)
#define MXC_F_UART_INTSTAT_FFTXOIS_POS (5)

/* FFTXHIS */
#define MXC_F_UART_INTSTAT_FFTXHIS ((uint32_t)0x00000040UL)
#define MXC_F_UART_INTSTAT_FFTXHIS_POS (6)

/* RTS */
#define MXC_F_UART_PIN_RTS ((uint32_t)0x00000001UL)
#define MXC_F_UART_PIN_RTS_POS (0)

/* CTS */
#define MXC_F_UART_PIN_CTS ((uint32_t)0x00000002UL)
#define MXC_F_UART_PIN_CTS_POS (1)

/* PARITY */
#define MXC_F_UART_DATA_PARITY ((uint32_t)0x00000100UL)
#define MXC_F_UART_DATA_PARITY_POS (8)

/* TXCNT */
#define MXC_F_UART_DMA_TXCNT ((uint32_t)0x0000000FUL)
#define MXC_F_UART_DMA_TCNT_POS (0)

/* TXEN */
#define MXC_F_UART_DMA_TXEN ((uint32_t)0x00000010UL)
#define MXC_F_UART_DMA_TXEN_POS (4)

/* RXCNT */
#define MXC_F_UART_DMA_RXCNT ((uint32_t)0x000001E0UL)
#define MXC_F_UART_DMA_RXCNT_POS (5)

/* RXEN */
#define MXC_F_UART_DMA_RXEN ((uint32_t)0x00000200UL)
#define MXC_F_UART_DMA_RXEN_POS (9)

/* BAUD calculation */
#define MXC_UART_BAUD0(baudrate)   (NOM_FREQ / ((baudrate) << 7))
#define MXC_UART_BAUD1(baudrate)   ((NOM_FREQ / (baudrate)) - (MXC_UART_BAUD0(baudrate) << 7))


/* UART parameter checking */
#define MXC_UART_VALID_SIZE(P) (((P) == MXC_S_UART_SIZE_5) || \
                                ((P) == MXC_S_UART_SIZE_6) || \
                                ((P) == MXC_S_UART_SIZE_7) || \
                                ((P) == MXC_S_UART_SIZE_8))

/* UART FIFO Depth in bytes */
#define MXC_UART_FIFO_DEPTH     (8)

#ifdef __cplusplus
}
#endif

#endif /* _MXC_UART_REGS_H_ */
