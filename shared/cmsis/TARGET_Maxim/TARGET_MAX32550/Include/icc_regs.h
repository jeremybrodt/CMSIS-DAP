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
* $Id: icc_regs.h 12919 2014-03-25 22:28:09Z jeremy.brodt $
*
********************************************************************************
*/

#ifndef _MXC_ICC_REGS_H_
#define _MXC_ICC_REGS_H_

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

/*                             Offset    Description
                               ====================== */
typedef struct {
	__IO uint32_t id;         /* 0x0000    Cache ID Register */
	__IO uint32_t cfg;        /* 0x0004    Memory Configuration Register */
	__R  uint32_t rsv1[62];   /* 0x0008    reserved */
	__IO uint32_t ctrlstat;   /* 0x0100    Cache Control and Status Register */
	__R  uint32_t rsv2[383];  /* 0x0104    reserved */
	__IO uint32_t inv;        /* 0x0700    Invalidate All Register */
} mxc_icc_regs_t;

/* Register offsets */
#define MXC_R_ICC_OFFS_ID        ((uint32_t)0x00000000UL)
#define MXC_R_ICC_OFFS_CFG       ((uint32_t)0x00000004UL)
#define MXC_R_ICC_OFFS_CTRLSTAT  ((uint32_t)0x00000100UL)
#define MXC_R_ICC_OFFS_INV       ((uint32_t)0x00000700UL)

/*  CN  ********************************************************************  */
#define MXC_F_ICC_ID_RELEASE_POS (0)
#define MXC_F_ICC_ID_RELEASE     (0x0000003FUL << MXC_F_ICC_ID_RELEASE_POS)
#define MXC_F_ICC_ID_PART_POS    (6)
#define MXC_F_ICC_ID_PART        (0x0000000FUL << MXC_F_ICC_ID_PART_POS)
#define MXC_F_ICC_ID_CID_POS     (10)
#define MXC_F_ICC_ID_CID         (0x0000001FUL << MXC_F_ICC_ID_CID_POS)

/*  CFG  *******************************************************************  */
#define MXC_F_ICC_CFG_CACHE_SIZE_POS (0)
#define MXC_F_ICC_CFG_CACHE_SIZE     (0x000000FFUL << MXC_F_ICC_CFG_CACHE_SIZE_POS)
#define MXC_F_ICC_CFG_MEM_SIZE_POS   (16)
#define MXC_F_ICC_CFG_MEM_SIZE       (0x000000FFUL << MXC_F_ICC_CFG_MEM_SIZE_POS)

/*  CTRLSTAT  **************************************************************  */
#define MXC_F_ICC_CTRLSTAT_EN_POS  (0)
#define MXC_F_ICC_CTRLSTAT_EN      (0x00000001UL << MXC_F_ICC_CTRLSTAT_EN_POS)
#define MXC_F_ICC_CTRLSTAT_RDY_POS (16)
#define MXC_F_ICC_CTRLSTAT_RDY     (0x00000001UL << MXC_F_ICC_CTRLSTAT_RDY_POS)

#ifdef __cplusplus
}
#endif

#endif /* _MXC_ICC_REGS_H_ */
