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
* $Id: flc_regs.h 12919 2014-03-25 22:28:09Z jeremy.brodt $
*
********************************************************************************
*/

#ifndef _MXC_FLC_REGS_H_
#define _MXC_FLC_REGS_H_

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
	__IO uint32_t addr;       /* 0x0000    Flash Address Register */
	__IO uint32_t clkdiv;     /* 0x0004    Clock Divide Register */
	__IO uint32_t cn;         /* 0x0008    Control Register */
	__IO uint32_t pr1e;       /* 0x000C    Protected Region 1 End Address Register */
	__IO uint32_t pr2s;       /* 0x0010    Protected Region 2 Start Address Register */
	__IO uint32_t pr2e;       /* 0x0014    Protected Region 2 End Address Register */
	__IO uint32_t pr3s;       /* 0x0018    Protected Region 3 Start Address Register */
	__IO uint32_t pr3e;       /* 0x001C    Protected Region 3 End Address Register */
	__IO uint32_t md;         /* 0x0020    Mode Register */
	__IO uint32_t intr;       /* 0x0024    Interrupt Register */
	__R  uint32_t rsv[2];     /* 0x0028    reserved */
	__IO uint32_t data0;      /* 0x0030    Data Register 0 */
	__IO uint32_t data1;      /* 0x0034    Data Register 1 */
	__IO uint32_t data2;      /* 0x0038    Data Register 2 */
	__IO uint32_t data3;      /* 0x003C    Data Register 3 */
	__IO uint32_t sspi_cn;    /* 0x0040    Slave SPI Control Register */
} mxc_flc_regs_t;

/* Register offsets */
#define MXC_R_FLC_OFFS_ADDR     ((uint32_t)0x00000000UL)
#define MXC_R_FLC_OFFS_CLKDIV   ((uint32_t)0x00000004UL)
#define MXC_R_FLC_OFFS_CN       ((uint32_t)0x00000008UL)
#define MXC_R_FLC_OFFS_PR1E     ((uint32_t)0x0000000CUL)
#define MXC_R_FLC_OFFS_PR2S     ((uint32_t)0x00000010UL)
#define MXC_R_FLC_OFFS_PR2E     ((uint32_t)0x00000014UL)
#define MXC_R_FLC_OFFS_PR3S     ((uint32_t)0x00000018UL)
#define MXC_R_FLC_OFFS_PR3E     ((uint32_t)0x0000001CUL)
#define MXC_R_FLC_OFFS_MD       ((uint32_t)0x00000020UL)
#define MXC_R_FLC_OFFS_INT      ((uint32_t)0x00000024UL)
#define MXC_R_FLC_OFFS_DATA0    ((uint32_t)0x00000030UL)
#define MXC_R_FLC_OFFS_DATA1    ((uint32_t)0x00000034UL)
#define MXC_R_FLC_OFFS_DATA2    ((uint32_t)0x00000038UL)
#define MXC_R_FLC_OFFS_DATA3    ((uint32_t)0x0000003CUL)
#define MXC_R_FLC_OFFS_SSPI_CN  ((uint32_t)0x00000040UL)

/*  CN  ******************************************************************  */

#define MXC_F_FLC_CN_WR_POS     (0)
#define MXC_F_FLC_CN_WR         (0x00000001UL << MXC_F_FLC_CN_WR_POS)
#define MXC_F_FLC_CN_ME_POS     (1)
#define MXC_F_FLC_CN_ME         (0x00000001UL << MXC_F_FLC_CN_ME_POS)
#define MXC_F_FLC_CN_PGE_POS    (2)
#define MXC_F_FLC_CN_PGE        (0x00000001UL << MXC_F_FLC_CN_PGE_POS)
#define MXC_F_FLC_CN_RCL_POS    (3)
#define MXC_F_FLC_CN_RCL        (0x00000001UL << MXC_F_FLC_CN_RCL_POS)
#define MXC_F_FLC_CN_WDTH_POS   (4)
#define MXC_F_FLC_CN_WDTH       (0x00000001UL << MXC_F_FLC_CN_WDTH_POS)
#define MXC_F_FLC_CN_ERASE_CODE_POS   (8)
#define MXC_F_FLC_CN_ERASE_CODE       (0x000000FFUL << MXC_F_FLC_CN_ERASE_CODE_POS)
#define MXC_S_FLC_CN_CODE_PAGE_ERASE  (0x00000055UL << MXC_F_FLC_CN_ERASE_CODE_POS)
#define MXC_S_FLC_CN_CODE_MASS_ERASE  (0x000000AAUL << MXC_F_FLC_CN_ERASE_CODE_POS)
#define MXC_F_FLC_CN_M3_FUWEN_POS   (16)
#define MXC_F_FLC_CN_M3_FUWEN       (0x00000001UL << MXC_F_FLC_CN_M3_FUWEN_POS)
#define MXC_F_FLC_CN_M3_FLWEN_POS   (17)
#define MXC_F_FLC_CN_M3_FLWEN       (0x00000001UL << MXC_F_FLC_CN_M3_FLWEN_POS)
#define MXC_F_FLC_CN_M3_FLREN_POS   (18)
#define MXC_F_FLC_CN_M3_FLREN       (0x00000001UL << MXC_F_FLC_CN_M3_FLREN_POS)
#define MXC_F_FLC_CN_SPI_FUWEN_POS  (20)
#define MXC_F_FLC_CN_SPI_FUWEN      (0x00000001UL << MXC_F_FLC_CN_SPI_FUWEN_POS)
#define MXC_F_FLC_CN_SPI_FLWEN_POS  (21)
#define MXC_F_FLC_CN_SPI_FLWEN      (0x00000001UL << MXC_F_FLC_CN_SPI_FLWEN_POS)
#define MXC_F_FLC_CN_SPI_FLREN_POS  (22)
#define MXC_F_FLC_CN_SPI_FLREN      (0x00000001UL << MXC_F_FLC_CN_SPI_FLREN_POS)
#define MXC_F_FLC_CN_PEND_POS     (24)
#define MXC_F_FLC_CN_PEND         (0x00000001UL << MXC_F_FLC_CN_PEND_POS)
#define MXC_F_FLC_CN_PREBOOT_POS  (26)
#define MXC_F_FLC_CN_PREBOOT      (0x00000001UL << MXC_F_FLC_CN_PREBOOT_POS)
#define MXC_F_FLC_CN_BRST_POS     (27)
#define MXC_F_FLC_CN_BRST         (0x00000001UL << MXC_F_FLC_CN_BRST_POS)
#define MXC_F_FLC_CN_UNLOCK_POS   (28)
#define MXC_F_FLC_CN_UNLOCK       (0x0000000FUL << MXC_F_FLC_CN_UNLOCK_POS)


/*  MODE  ************************************************************  */

#define MXC_F_FLC_MODE_SECURE_POS (0)
#define MXC_F_FLC_MODE_SECURE     (0x00000001UL << MXC_F_FLC_MODE_SECURE_POS)

/*  INT  ************************************************************  */

#define MXC_F_FLC_INTR_DONE_POS   (0)
#define MXC_F_FLC_INTR_DONE       (0x00000001UL << MXC_F_FLC_INTR_DONE_POS)
#define MXC_F_FLC_INTR_AF_POS     (1)
#define MXC_F_FLC_INTR_AF         (0x00000001UL << MXC_F_FLC_INTR_AF_POS)
#define MXC_F_FLC_INTR_DONEIE_POS (8)
#define MXC_F_FLC_INTR_DONEIE     (0x00000001UL << MXC_F_FLC_INTR_DONEIE_POS)
#define MXC_F_FLC_INTR_AFIE_POS   (9)
#define MXC_F_FLC_INTR_AFIE       (0x00000001UL << MXC_F_FLC_INTR_AFIE_POS)

#ifdef __cplusplus
}
#endif

#endif /* _MXC_FLC_REGS_H_ */
