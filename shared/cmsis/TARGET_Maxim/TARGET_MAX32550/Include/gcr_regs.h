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
* $Id: gcr_regs.h 13296 2014-04-29 15:07:56Z jeremy.brodt $
*
********************************************************************************
*/

#ifndef _MXC_GCR_REGS_H_
#define _MXC_GCR_REGS_H_

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
/* TODO determine if SCON needs special name */
typedef struct {
	__IO uint32_t scon;       /* 0x0000    System Control Register */
	__IO uint32_t rstr;       /* 0x0004    Reset Register */
	__IO uint32_t clkcn;      /* 0x0008    Clock Control Register */
	__IO uint32_t pm;         /* 0x000C    Power Management Register */
	__IO uint32_t pll0cn;     /* 0x0010    PLL0 Control Register */
	__IO uint32_t pll1cn;     /* 0x0014    PLL1 Control Register */
	__IO uint32_t pckdiv;     /* 0x0018    Peripheral Clock Divider Register */
	__R  uint32_t rsv1[2];    /* 0x001C    reserved */
	__IO uint32_t perckcn;    /* 0x0024    Peripheral Clock Disable Register */
	__R  uint32_t rsv2;       /* 0x0028    reserved */
	__IO uint32_t memzcn;     /* 0x002C    Memory Zeroize Control Register */
	__R  uint32_t rsv3;       /* 0x0030    reserved */
	__IO uint32_t scck;       /* 0x0034    Smart Card Clock Control Register */
} mxc_gcr_regs_t;

/* Register offsets */
#define MXC_R_GCR_OFFS_SCON     ((uint32_t)0x00000000UL)
#define MXC_R_GCR_OFFS_RSTR     ((uint32_t)0x00000004UL)
#define MXC_R_GCR_OFFS_CLKCN    ((uint32_t)0x00000008UL)
#define MXC_R_GCR_OFFS_PM       ((uint32_t)0x0000000CUL)
#define MXC_R_GCR_OFFS_PLL0CN   ((uint32_t)0x00000010UL)
#define MXC_R_GCR_OFFS_PLL1CN   ((uint32_t)0x00000014UL)
#define MXC_R_GCR_OFFS_PCKDIV   ((uint32_t)0x00000018UL)
#define MXC_R_GCR_OFFS_PERCKCN  ((uint32_t)0x00000024UL)
#define MXC_R_GCR_OFFS_MEMZCN   ((uint32_t)0x0000002CUL)
#define MXC_R_GCR_OFFS_SCCK     ((uint32_t)0x00000034UL)

/* SCON */
/* BSTAPEN */
#define MXC_F_GCR_SCON_BSTAPEN ((uint32_t)0x00000001UL)
#define MXC_F_GCR_SCON_BSTAPEN_POS (0)

/* ONVMAIN */
#define MXC_F_GCR_SCON_ONVMAIN ((uint32_t)0x00000008UL)
#define MXC_F_GCR_SCON_ONVMAIN_POS (3)

/* FLASH_PAGE_FLIP */
#define MXC_F_GCR_SCON_FLASH_PAGE_FLIP ((uint32_t)0x00000010UL)
#define MXC_F_GCR_SCON_FLASH_PAGE_FLIP_POS (4)

/* CCHK */
#define MXC_F_GCR_SCON_CCHK ((uint32_t)0x00002000UL)
#define MXC_F_GCR_SCON_CCHK_POS (13)

/* CHKRD */
#define MXC_F_GCR_SCON_CHKRD ((uint32_t)0x00004000UL)
#define MXC_F_GCR_SCON_CHKRD_POS (14)

/* CHKRES */
#define MXC_F_GCR_SCON_CHKRES ((uint32_t)0x00008000UL)
#define MXC_F_GCR_SCON_CHKRES_POS (15)

/* DMA */
#define MXC_F_GCR_RSTR_DMA ((uint32_t)0x00000001UL)
#define MXC_F_GCR_RSTR_DMA_POS (0)

/* WDT */
#define MXC_F_GCR_RSTR_WDT ((uint32_t)0x00000002UL)
#define MXC_F_GCR_RSTR_WDT_POS (1)

/* GPIO0 */
#define MXC_F_GCR_RSTR_GPIO0 ((uint32_t)0x00000004UL)
#define MXC_F_GCR_RSTR_GPIO0_POS (2)

/* GPIO1 */
#define MXC_F_GCR_RSTR_GPIO1 ((uint32_t)0x00000008UL)
#define MXC_F_GCR_RSTR_GPIO1_POS (3)

/* GPIO2 */
#define MXC_F_GCR_RSTR_GPIO2 ((uint32_t)0x00000010UL)
#define MXC_F_GCR_RSTR_GPIO2_POS (4)

/* TIMER0 */
#define MXC_F_GCR_RSTR_TIMER0 ((uint32_t)0x00000020UL)
#define MXC_F_GCR_RSTR_TIMER0_POS (5)

/* TIMER1 */
#define MXC_F_GCR_RSTR_TIMER1 ((uint32_t)0x00000040UL)
#define MXC_F_GCR_RSTR_TIMER1_POS (6)

/* TIMER2 */
#define MXC_F_GCR_RSTR_TIMER2 ((uint32_t)0x00000080UL)
#define MXC_F_GCR_RSTR_TIMER2_POS (7)

/* TIMER3 */
#define MXC_F_GCR_RSTR_TIMER3 ((uint32_t)0x00000100UL)
#define MXC_F_GCR_RSTR_TIMER3_POS (8)

/* TIMER4 */
#define MXC_F_GCR_RSTR_TIMER4 ((uint32_t)0x00000200UL)
#define MXC_F_GCR_RSTR_TIMER4_POS (9)

/* TIMER5 */
#define MXC_F_GCR_RSTR_TIMER5 ((uint32_t)0x00000400UL)
#define MXC_F_GCR_RSTR_TIMER5_POS (10)

/* UART0 */
#define MXC_F_GCR_RSTR_UART0 ((uint32_t)0x00000800UL)
#define MXC_F_GCR_RSTR_UART0_POS (11)

/* UART1 */
#define MXC_F_GCR_RSTR_UART1 ((uint32_t)0x00001000UL)
#define MXC_F_GCR_RSTR_UART1_POS (12)

/* SPI0 */
#define MXC_F_GCR_RSTR_SPI0 ((uint32_t)0x00002000UL)
#define MXC_F_GCR_RSTR_SPI0_POS (13)

/* SPI1 */
#define MXC_F_GCR_RSTR_SPI1 ((uint32_t)0x00004000UL)
#define MXC_F_GCR_RSTR_SPI1_POS (14)

/* SPI2 */
#define MXC_F_GCR_RSTR_SPI2 ((uint32_t)0x00008000UL)
#define MXC_F_GCR_RSTR_SPI2_POS (15)

/* I2C */
#define MXC_F_GCR_RSTR_I2C ((uint32_t)0x00010000UL)
#define MXC_F_GCR_RSTR_I2C_POS (16)

/* RTC */
#define MXC_F_GCR_RSTR_RTC ((uint32_t)0x00020000UL)
#define MXC_F_GCR_RSTR_RTC_POS (17)

/* CRYPTO */
#define MXC_F_GCR_RSTR_CRYPTO ((uint32_t)0x00040000UL)
#define MXC_F_GCR_RSTR_CRYPTO_POS (18)

/* MAGDSP */
#define MXC_F_GCR_RSTR_MAGDSP ((uint32_t)0x00080000UL)
#define MXC_F_GCR_RSTR_MAGDSP_POS (19)

/* SC */
#define MXC_F_GCR_RSTR_SC ((uint32_t)0x00100000UL)
#define MXC_F_GCR_RSTR_SC_POS (20)

/* KBD */
#define MXC_F_GCR_RSTR_KBD ((uint32_t)0x00200000UL)
#define MXC_F_GCR_RSTR_KBD_POS (21)

/* LCD_TFT */
#define MXC_F_GCR_RSTR_LCD_TFT ((uint32_t)0x00400000UL)
#define MXC_F_GCR_RSTR_LCD_TFT_POS (22)

/* USB */
#define MXC_F_GCR_RSTR_USB ((uint32_t)0x00800000UL)
#define MXC_F_GCR_RSTR_USB_POS (23)

/* ADC */
#define MXC_F_GCR_RSTR_ADC ((uint32_t)0x02000000UL)
#define MXC_F_GCR_RSTR_ADC_POS (25)

/* DAC */
#define MXC_F_GCR_RSTR_DAC ((uint32_t)0x01000000UL)
#define MXC_F_GCR_RSTR_DAC_POS (26)

/* SRST */
#define MXC_F_GCR_RSTR_SRST ((uint32_t)0x20000000UL)
#define MXC_F_GCR_RSTR_SRST_POS (29)

/* PRST */
#define MXC_F_GCR_RSTR_PRST ((uint32_t)0x40000000UL)
#define MXC_F_GCR_RSTR_PRST_POS (30)

/* SYSTEM */
#define MXC_F_GCR_RSTR_SYSTEM ((uint32_t)0x80000000UL)
#define MXC_F_GCR_RSTR_SYSTEM_POS (31)

/* PSC */
#define MXC_F_GCR_CLKCN_PSC_POS       (6)
#define MXC_F_GCR_CLKCN_PSC           ((uint32_t)(0x00000007UL << MXC_F_GCR_CLKCN_PSC_POS))

#define MXC_V_GCR_CLKCN_PSC_DIV_1     ((uint32_t)0x00000000UL)
#define MXC_V_GCR_CLKCN_PSC_DIV_2     ((uint32_t)0x00000001UL)
#define MXC_V_GCR_CLKCN_PSC_DIV_4     ((uint32_t)0x00000002UL)
#define MXC_V_GCR_CLKCN_PSC_DIV_8     ((uint32_t)0x00000003UL)
#define MXC_V_GCR_CLKCN_PSC_DIV_16    ((uint32_t)0x00000004UL)
#define MXC_V_GCR_CLKCN_PSC_DIV_32    ((uint32_t)0x00000005UL)
#define MXC_V_GCR_CLKCN_PSC_DIV_64    ((uint32_t)0x00000006UL)
#define MXC_V_GCR_CLKCN_PSC_DIV_128   ((uint32_t)0x00000007UL)

#define MXC_S_GCR_CLKCN_PSC_DIV_1     (MXC_V_GCR_CLKCN_PSC_DIV_1 << MXC_F_GCR_CLKCN_PSC_POS)
#define MXC_S_GCR_CLKCN_PSC_DIV_2     (MXC_V_GCR_CLKCN_PSC_DIV_2 << MXC_F_GCR_CLKCN_PSC_POS)
#define MXC_S_GCR_CLKCN_PSC_DIV_4     (MXC_V_GCR_CLKCN_PSC_DIV_4 << MXC_F_GCR_CLKCN_PSC_POS)
#define MXC_S_GCR_CLKCN_PSC_DIV_8     (MXC_V_GCR_CLKCN_PSC_DIV_8 << MXC_F_GCR_CLKCN_PSC_POS)
#define MXC_S_GCR_CLKCN_PSC_DIV_16    (MXC_V_GCR_CLKCN_PSC_DIV_16 << MXC_F_GCR_CLKCN_PSC_POS)
#define MXC_S_GCR_CLKCN_PSC_DIV_32    (MXC_V_GCR_CLKCN_PSC_DIV_32 << MXC_F_GCR_CLKCN_PSC_POS)
#define MXC_S_GCR_CLKCN_PSC_DIV_64    (MXC_V_GCR_CLKCN_PSC_DIV_64 << MXC_F_GCR_CLKCN_PSC_POS)
#define MXC_S_GCR_CLKCN_PSC_DIV_128   (MXC_V_GCR_CLKCN_PSC_DIV_128 << MXC_F_GCR_CLKCN_PSC_POS)

/* CLKSEL */
#define MXC_F_GCR_CLKCN_CLKSEL_POS    (9)
#define MXC_F_GCR_CLKCN_CLKSEL        ((uint32_t)(0x00000007UL << MXC_F_GCR_CLKCN_CLKSEL_POS))

#define MXC_V_GCR_CLKCN_CLKSEL_CRYPTO ((uint32_t)0x00000000UL)
#define MXC_V_GCR_CLKCN_CLKSEL_PLL0   ((uint32_t)0x00000001UL)
#define MXC_V_GCR_CLKCN_CLKSEL_HFXIN  ((uint32_t)0x00000002UL)
#define MXC_V_GCR_CLKCN_CLKSEL_RING   ((uint32_t)0x00000003UL)

#define MXC_S_GCR_CLKCN_CLKSEL_CRYPTO (MXC_V_GCR_CLKCN_CLKSEL_CRYPTO << MXC_F_GCR_CLKCN_CLKSEL_POS)
#define MXC_S_GCR_CLKCN_CLKSEL_PLL0   (MXC_V_GCR_CLKCN_CLKSEL_PLL0 << MXC_F_GCR_CLKCN_CLKSEL_POS)
#define MXC_S_GCR_CLKCN_CLKSEL_HFXIN  (MXC_V_GCR_CLKCN_CLKSEL_HFXIN << MXC_F_GCR_CLKCN_CLKSEL_POS)
#define MXC_S_GCR_CLKCN_CLKSEL_RING   (MXC_V_GCR_CLKCN_CLKSEL_RING << MXC_F_GCR_CLKCN_CLKSEL_POS)

/* CKRDY */
#define MXC_F_GCR_CLKCN_CKRDY ((uint32_t)0x00002000UL)
#define MXC_F_GCR_CLKCN_CKRDY_POS (13)

/* MODE */
#define MXC_F_GCR_PM_MODE ((uint32_t)0x00000003UL)
#define MXC_F_GCR_PM_MODE_POS (0)

/* GPIOWKEN */
#define MXC_F_GCR_PM_GPIOWKEN ((uint32_t)0x00000010UL)
#define MXC_F_GCR_PM_GPIOWKEN_POS (4)

/* RTCWKEN */
#define MXC_F_GCR_PM_RTCWKEN ((uint32_t)0x00000020UL)
#define MXC_F_GCR_PM_RTCWKEN_POS (5)

/* USBWKEN */
#define MXC_F_GCR_PM_USBWKEN ((uint32_t)0x00000040UL)
#define MXC_F_GCR_PM_USBWKEN_POS (6)

/* SCWKEN */
#define MXC_F_GCR_PM_SCWKEN ((uint32_t)0x00000080UL)
#define MXC_F_GCR_PM_SCWKEN_POS (7)

/* OSCPD */
#define MXC_F_GCR_PM_OSCPD ((uint32_t)0x00001000UL)
#define MXC_F_GCR_PM_OSCPD_POS (12)

/* PLL01PD */
#define MXC_F_GCR_PM_PLL01PD ((uint32_t)0x00002000UL)
#define MXC_F_GCR_PM_PLL01PD_POS (13)

/* COPD */
#define MXC_F_GCR_PM_COPD ((uint32_t)0x00004000UL)
#define MXC_F_GCR_PM_COPD_POS (14)

/* CM3PMUEN */
#define MXC_F_GCR_PM_CM3PMUEN ((uint32_t)0x00010000UL)
#define MXC_F_GCR_PM_CM3PMUEN_POS (16)

/* CM3WICACK */
#define MXC_F_GCR_PM_CM3WICACK ((uint32_t)0x00020000UL)
#define MXC_F_GCR_PM_CM3WICACK_POS (17)

/* PLL0EN */
#define MXC_F_GCR_PLL0CN_PLLEN ((uint32_t)0x00000001UL)
#define MXC_F_GCR_PLL0CN_PLLEN_POS (0)

/* PLL0LOCK */
#define MXC_F_GCR_PLL0CN_PLLLOCK ((uint32_t)0x00000002UL)
#define MXC_F_GCR_PLL0CN_PLLLOCK_POS (1)

/* PLL1EN */
#define MXC_F_GCR_PLL1CN_PLLEN ((uint32_t)0x00000001UL)
#define MXC_F_GCR_PLL1CN_PLLEN_POS (0)

/* PLL1LOCK */
#define MXC_F_GCR_PLL1CN_PLLLOCK ((uint32_t)0x00000002UL)
#define MXC_F_GCR_PLL1CN_PLLLOCK_POS (1)

/* PCF */
#define MXC_F_GCR_PCKDIV_PCF ((uint32_t)0x00000007UL)
#define MXC_F_GCR_PCKDIV_PCF_POS (0)

/* GPIO0D */
#define MXC_F_GCR_PERCKCN_GPIO0D ((uint32_t)0x00000001UL)
#define MXC_F_GCR_PERCKCN_GPIO0D_POS (0)

/* GPIO1D */
#define MXC_F_GCR_PERCKCN_GPIO1D ((uint32_t)0x00000002UL)
#define MXC_F_GCR_PERCKCN_GPIO1D_POS (1)

/* GPIO2D */
#define MXC_F_GCR_PERCKCN_GPIO2D ((uint32_t)0x00000004UL)
#define MXC_F_GCR_PERCKCN_GPIO2D_POS (2)

/* USBD */
#define MXC_F_GCR_PERCKCN_USBD ((uint32_t)0x00000008UL)
#define MXC_F_GCR_PERCKCN_USBD_POS (3)

/* CLCD */
#define MXC_F_GCR_PERCKCN_CLCD ((uint32_t)0x00000010UL)
#define MXC_F_GCR_PERCKCN_CLCD_POS (4)

/* DMAD */
#define MXC_F_GCR_PERCKCN_DMAD ((uint32_t)0x00000020UL)
#define MXC_F_GCR_PERCKCN_DMAD_POS (5)

/* SPI0D */
#define MXC_F_GCR_PERCKCN_SPI0D ((uint32_t)0x00000040UL)
#define MXC_F_GCR_PERCKCN_SPI0D_POS (6)

/* SPI1D */
#define MXC_F_GCR_PERCKCN_SPI1D ((uint32_t)0x00000080UL)
#define MXC_F_GCR_PERCKCN_SPI1D_POS (7)

/* SPI2D */
#define MXC_F_GCR_PERCKCN_SPI2D ((uint32_t)0x00000100UL)
#define MXC_F_GCR_PERCKCN_SPI2D_POS (8)

/* UART0D */
#define MXC_F_GCR_PERCKCN_UART0D ((uint32_t)0x00000200UL)
#define MXC_F_GCR_PERCKCN_UART0D_POS (9)

/* UART1D */
#define MXC_F_GCR_PERCKCN_UART1D ((uint32_t)0x00000400UL)
#define MXC_F_GCR_PERCKCN_UART1D_POS (10)

/* MAGDSPD */
#define MXC_F_GCR_PERCKCN_MAGDSPD ((uint32_t)0x00000800UL)
#define MXC_F_GCR_PERCKCN_MAGDSPD_POS (11)

/* SCD */
#define MXC_F_GCR_PERCKCN_SCD ((uint32_t)0x00001000UL)
#define MXC_F_GCR_PERCKCN_SCD_POS (12)

/* I2CD */
#define MXC_F_GCR_PERCKCN_I2CD ((uint32_t)0x00002000UL)
#define MXC_F_GCR_PERCKCN_I2CD_POS (13)

/* CRYPTOD */
#define MXC_F_GCR_PERCKCN_CRYPTOD ((uint32_t)0x00004000UL)
#define MXC_F_GCR_PERCKCN_CRYPTOD_POS (14)

/* T0D */
#define MXC_F_GCR_PERCKCN_T0D ((uint32_t)0x00008000UL)
#define MXC_F_GCR_PERCKCN_T0D_POS (15)

/* T1D */
#define MXC_F_GCR_PERCKCN_T1D ((uint32_t)0x00010000UL)
#define MXC_F_GCR_PERCKCN_T1D_POS (16)

/* T2D */
#define MXC_F_GCR_PERCKCN_T2D ((uint32_t)0x00020000UL)
#define MXC_F_GCR_PERCKCN_T2D_POS (17)

/* T3D */
#define MXC_F_GCR_PERCKCN_T3D ((uint32_t)0x00040000UL)
#define MXC_F_GCR_PERCKCN_T3D_POS (18)

/* T4D */
#define MXC_F_GCR_PERCKCN_T4D ((uint32_t)0x00080000UL)
#define MXC_F_GCR_PERCKCN_T4D_POS (19)

/* T5D */
#define MXC_F_GCR_PERCKCN_T5D ((uint32_t)0x00100000UL)
#define MXC_F_GCR_PERCKCN_T5D_POS (20)

/* MLCDD */
#define MXC_F_GCR_PERCKCN_MLCDD ((uint32_t)0x00200000UL)
#define MXC_F_GCR_PERCKCN_MLCDD_POS (21)

/* KBDD */
#define MXC_F_GCR_PERCKCN_KBDD ((uint32_t)0x00400000UL)
#define MXC_F_GCR_PERCKCN_KBDD_POS (22)

/* ADCD */
#define MXC_F_GCR_PERCKCN_ADCD ((uint32_t)0x00800000UL)
#define MXC_F_GCR_PERCKCN_ADCD_POS (23)

/* DACD */
#define MXC_F_GCR_PERCKCN_DACD ((uint32_t)0x01000000UL)
#define MXC_F_GCR_PERCKCN_DACD_POS (24)

/* SRAM0 */
#define MXC_F_GCR_MEMZCN_SRAM0 ((uint32_t)0x00000001UL)
#define MXC_F_GCR_MEMZCN_SRAM0_POS (0)

/* SRAM1 */
#define MXC_F_GCR_MEMZCN_SRAM1 ((uint32_t)0x00000002UL)
#define MXC_F_GCR_MEMZCN_SRAM1_POS (1)

/* VNSRAM */
#define MXC_F_GCR_MEMZCN_NVSRAM ((uint32_t)0x00000004UL)
#define MXC_F_GCR_MEMZCN_NVSRAM_POS (2)

/* ICAHCE */
#define MXC_F_GCR_MEMZCN_ICACHE ((uint32_t)0x00000008UL)
#define MXC_F_GCR_MEMZCN_ICACHE_POS (4)

/* CRYPTO */
#define MXC_F_GCR_MEMZCN_CRYPTO ((uint32_t)0x00000020UL)
#define MXC_F_GCR_MEMZCN_CRYPTO_POS (5)

/* SC0FRQ */
#define MXC_F_GCR_SCCK_SC0FRQ     ((uint32_t)0x0000001FUL)
#define MXC_F_GCR_SCCK_SC0FRQ_POS (0)
/* Only valid for 12MHz input clock to PLL1 and x8 multiplication */
#define MXC_V_GCR_SCONFRQ_96000000 ((uint32_t)0x00000001)
#define MXC_V_GCR_SCONFRQ_48000000 ((uint32_t)0x00000002)
#define MXC_V_GCR_SCONFRQ_32000000 ((uint32_t)0x00000003)
#define MXC_V_GCR_SCONFRQ_24000000 ((uint32_t)0x00000004)
/* Yikes, 127 of these. */
#define MXC_V_GCR_SCONFRQ_1600000 ((uint32_t)0x0000003C)
#define MXC_V_GCR_SCONFRQ_1573770 ((uint32_t)0x0000003D)
#define MXC_V_GCR_SCONFRQ_1548387 ((uint32_t)0x0000003E)
#define MXC_V_GCR_SCONFRQ_1523810 ((uint32_t)0x0000003F)

/* TODO bit band access */

/* TODO SC0FRQ assertion */

#ifdef __cplusplus
}
#endif

#endif /* _MXC_GCR_REGS_H_ */
