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
* $Id: gpio_regs.h 14674 2014-08-15 14:45:13Z jeremy.brodt $
*
********************************************************************************
*/

#ifndef _MXC_GPIO_REGS_H_
#define _MXC_GPIO_REGS_H_

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

typedef struct {
    __IO uint32_t en;
    __IO uint32_t en_set;
    __IO uint32_t en_clr;
    __IO uint32_t out_en;
    __IO uint32_t out_en_set;
    __IO uint32_t out_en_clr;
    __IO uint32_t out;
    __IO uint32_t out_set;
    __IO uint32_t out_clr;
    __I  uint32_t in;
    __IO uint32_t int_mod;
    __IO uint32_t int_pol;
    __R  uint32_t rsv1;
    __IO uint32_t int_en;
    __IO uint32_t int_en_set;
    __IO uint32_t int_en_clr;
    __I  uint32_t int_stat;
    __R  uint32_t rsv2;
    __IO uint32_t int_clr;
    __IO uint32_t wake_en;
    __R  uint32_t rsv3;
    __R  uint32_t rsv4;
    __IO uint32_t open_drain_en;
    __IO uint32_t int_dual_edge;
    __IO uint32_t pad_cfg1;
    __IO uint32_t pad_cfg2;
    __IO uint32_t en1;
    __IO uint32_t en1_set;
    __IO uint32_t en1_clr;
    __R  uint32_t rsv5;
    __IO uint32_t ds;
} mxc_gpio_regs_t;

/* Register offsets */
#define MXC_R_GPIO_OFFS_EN            ((uint32_t)0x00000000UL)
#define MXC_R_GPIO_OFFS_EN_SET        ((uint32_t)0x00000004UL)
#define MXC_R_GPIO_OFFS_EN_CLR        ((uint32_t)0x00000008UL)
#define MXC_R_GPIO_OFFS_OUT_EN        ((uint32_t)0x0000000CUL)
#define MXC_R_GPIO_OFFS_OUT_EN_SET    ((uint32_t)0x00000010UL)
#define MXC_R_GPIO_OFFS_OUT_EN_CLR    ((uint32_t)0x00000014UL)
#define MXC_R_GPIO_OFFS_OUT           ((uint32_t)0x00000018UL)
#define MXC_R_GPIO_OFFS_OUT_SET       ((uint32_t)0x0000001CUL)
#define MXC_R_GPIO_OFFS_OUT_CLR       ((uint32_t)0x00000020UL)
#define MXC_R_GPIO_OFFS_IN            ((uint32_t)0x00000024UL)
#define MXC_R_GPIO_OFFS_INT_MOD       ((uint32_t)0x00000028UL)
#define MXC_R_GPIO_OFFS_INT_POL       ((uint32_t)0x0000002CUL)
#define MXC_R_GPIO_OFFS_INT_EN        ((uint32_t)0x00000034UL)
#define MXC_R_GPIO_OFFS_INT_EN_SET    ((uint32_t)0x00000038UL)
#define MXC_R_GPIO_OFFS_INT_EN_CLR    ((uint32_t)0x0000003CUL)
#define MXC_R_GPIO_OFFS_INT_STAT      ((uint32_t)0x00000040UL)
#define MXC_R_GPIO_OFFS_INT_CLR       ((uint32_t)0x00000048UL)
#define MXC_R_GPIO_OFFS_WAKE_EN       ((uint32_t)0x0000004CUL)
#define MXC_R_GPIO_OFFS_INT_DUAL_EDGE ((uint32_t)0x0000005CUL)
#define MXC_R_GPIO_OFFS_PAD_CFG1      ((uint32_t)0x00000060UL)
#define MXC_R_GPIO_OFFS_PAD_CFG2      ((uint32_t)0x00000064UL)
#define MXC_R_GPIO_OFFS_EN1           ((uint32_t)0x00000068UL)
#define MXC_R_GPIO_OFFS_EN1_SET       ((uint32_t)0x0000006CUL)
#define MXC_R_GPIO_OFFS_EN1_CLR       ((uint32_t)0x00000070UL)
#define MXC_R_GPIO_OFFS_DS            ((uint32_t)0x000000B0UL)

/* EN 00 */
#define MXC_F_GPIO_EN_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_EN_00_POS (0)

/* EN 01 */
#define MXC_F_GPIO_EN_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_EN_01_POS (1)

/* EN 02 */
#define MXC_F_GPIO_EN_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_EN_02_POS (2)

/* EN 03 */
#define MXC_F_GPIO_EN_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_EN_03_POS (3)

/* EN 04 */
#define MXC_F_GPIO_EN_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_EN_04_POS (4)

/* EN 05 */
#define MXC_F_GPIO_EN_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_EN_05_POS (5)

/* EN 06 */
#define MXC_F_GPIO_EN_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_EN_06_POS (6)

/* EN 07 */
#define MXC_F_GPIO_EN_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_EN_07_POS (7)

/* EN 08 */
#define MXC_F_GPIO_EN_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_EN_08_POS (8)

/* EN 09 */
#define MXC_F_GPIO_EN_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_EN_09_POS (9)

/* EN 10 */
#define MXC_F_GPIO_EN_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_EN_10_POS (10)

/* EN 11 */
#define MXC_F_GPIO_EN_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_EN_11_POS (11)

/* EN 12 */
#define MXC_F_GPIO_EN_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_EN_12_POS (12)

/* EN 13 */
#define MXC_F_GPIO_EN_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_EN_13_POS (13)

/* EN 14 */
#define MXC_F_GPIO_EN_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_EN_14_POS (14)

/* EN 15 */
#define MXC_F_GPIO_EN_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_EN_15_POS (15)

/* EN 16 */
#define MXC_F_GPIO_EN_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_EN_16_POS (16)

/* EN 17 */
#define MXC_F_GPIO_EN_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_EN_17_POS (17)

/* EN 18 */
#define MXC_F_GPIO_EN_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_EN_18_POS (18)

/* EN 19 */
#define MXC_F_GPIO_EN_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_EN_19_POS (19)

/* EN 20 */
#define MXC_F_GPIO_EN_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_EN_20_POS (20)

/* EN 21 */
#define MXC_F_GPIO_EN_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_EN_21_POS (21)

/* EN 22 */
#define MXC_F_GPIO_EN_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_EN_22_POS (22)

/* EN 23 */
#define MXC_F_GPIO_EN_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_EN_23_POS (23)

/* EN 24 */
#define MXC_F_GPIO_EN_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_EN_24_POS (24)

/* EN 25 */
#define MXC_F_GPIO_EN_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_EN_25_POS (25)

/* EN 26 */
#define MXC_F_GPIO_EN_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_EN_26_POS (26)

/* EN 27 */
#define MXC_F_GPIO_EN_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_EN_27_POS (27)

/* EN 28 */
#define MXC_F_GPIO_EN_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_EN_28_POS (28)

/* EN 29 */
#define MXC_F_GPIO_EN_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_EN_29_POS (29)

/* EN 30 */
#define MXC_F_GPIO_EN_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_EN_30_POS (30)

/* EN 31 */
#define MXC_F_GPIO_EN_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_EN_31_POS (31)

/* OUT_EN 00 */
#define MXC_F_GPIO_OUT_EN_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_OUT_EN_00_POS (0)

/* OUT_EN 01 */
#define MXC_F_GPIO_OUT_EN_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_OUT_EN_01_POS (1)

/* OUT_EN 02 */
#define MXC_F_GPIO_OUT_EN_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_OUT_EN_02_POS (2)

/* OUT_EN 03 */
#define MXC_F_GPIO_OUT_EN_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_OUT_EN_03_POS (3)

/* OUT_EN 04 */
#define MXC_F_GPIO_OUT_EN_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_OUT_EN_04_POS (4)

/* OUT_EN 05 */
#define MXC_F_GPIO_OUT_EN_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_OUT_EN_05_POS (5)

/* OUT_EN 06 */
#define MXC_F_GPIO_OUT_EN_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_OUT_EN_06_POS (6)

/* OUT_EN 07 */
#define MXC_F_GPIO_OUT_EN_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_OUT_EN_07_POS (7)

/* OUT_EN 08 */
#define MXC_F_GPIO_OUT_EN_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_OUT_EN_08_POS (8)

/* OUT_EN 09 */
#define MXC_F_GPIO_OUT_EN_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_OUT_EN_09_POS (9)

/* OUT_EN 10 */
#define MXC_F_GPIO_OUT_EN_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_OUT_EN_10_POS (10)

/* OUT_EN 11 */
#define MXC_F_GPIO_OUT_EN_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_OUT_EN_11_POS (11)

/* OUT_EN 12 */
#define MXC_F_GPIO_OUT_EN_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_OUT_EN_12_POS (12)

/* OUT_EN 13 */
#define MXC_F_GPIO_OUT_EN_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_OUT_EN_13_POS (13)

/* OUT_EN 14 */
#define MXC_F_GPIO_OUT_EN_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_OUT_EN_14_POS (14)

/* OUT_EN 15 */
#define MXC_F_GPIO_OUT_EN_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_OUT_EN_15_POS (15)

/* OUT_EN 16 */
#define MXC_F_GPIO_OUT_EN_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_OUT_EN_16_POS (16)

/* OUT_EN 17 */
#define MXC_F_GPIO_OUT_EN_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_OUT_EN_17_POS (17)

/* OUT_EN 18 */
#define MXC_F_GPIO_OUT_EN_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_OUT_EN_18_POS (18)

/* OUT_EN 19 */
#define MXC_F_GPIO_OUT_EN_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_OUT_EN_19_POS (19)

/* OUT_EN 20 */
#define MXC_F_GPIO_OUT_EN_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_OUT_EN_20_POS (20)

/* OUT_EN 21 */
#define MXC_F_GPIO_OUT_EN_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_OUT_EN_21_POS (21)

/* OUT_EN 22 */
#define MXC_F_GPIO_OUT_EN_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_OUT_EN_22_POS (22)

/* OUT_EN 23 */
#define MXC_F_GPIO_OUT_EN_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_OUT_EN_23_POS (23)

/* OUT_EN 24 */
#define MXC_F_GPIO_OUT_EN_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_OUT_EN_24_POS (24)

/* OUT_EN 25 */
#define MXC_F_GPIO_OUT_EN_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_OUT_EN_25_POS (25)

/* OUT_EN 26 */
#define MXC_F_GPIO_OUT_EN_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_OUT_EN_26_POS (26)

/* OUT_EN 27 */
#define MXC_F_GPIO_OUT_EN_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_OUT_EN_27_POS (27)

/* OUT_EN 28 */
#define MXC_F_GPIO_OUT_EN_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_OUT_EN_28_POS (28)

/* OUT_EN 29 */
#define MXC_F_GPIO_OUT_EN_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_OUT_EN_29_POS (29)

/* OUT_EN 30 */
#define MXC_F_GPIO_OUT_EN_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_OUT_EN_30_POS (30)

/* OUT_EN 31 */
#define MXC_F_GPIO_OUT_EN_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_OUT_EN_31_POS (31)

/* OUT 00 */
#define MXC_F_GPIO_OUT_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_OUT_00_POS (0)

/* OUT 01 */
#define MXC_F_GPIO_OUT_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_OUT_01_POS (1)

/* OUT 02 */
#define MXC_F_GPIO_OUT_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_OUT_02_POS (2)

/* OUT 03 */
#define MXC_F_GPIO_OUT_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_OUT_03_POS (3)

/* OUT 04 */
#define MXC_F_GPIO_OUT_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_OUT_04_POS (4)

/* OUT 05 */
#define MXC_F_GPIO_OUT_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_OUT_05_POS (5)

/* OUT 06 */
#define MXC_F_GPIO_OUT_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_OUT_06_POS (6)

/* OUT 07 */
#define MXC_F_GPIO_OUT_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_OUT_07_POS (7)

/* OUT 08 */
#define MXC_F_GPIO_OUT_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_OUT_08_POS (8)

/* OUT 09 */
#define MXC_F_GPIO_OUT_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_OUT_09_POS (9)

/* OUT 10 */
#define MXC_F_GPIO_OUT_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_OUT_10_POS (10)

/* OUT 11 */
#define MXC_F_GPIO_OUT_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_OUT_11_POS (11)

/* OUT 12 */
#define MXC_F_GPIO_OUT_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_OUT_12_POS (12)

/* OUT 13 */
#define MXC_F_GPIO_OUT_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_OUT_13_POS (13)

/* OUT 14 */
#define MXC_F_GPIO_OUT_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_OUT_14_POS (14)

/* OUT 15 */
#define MXC_F_GPIO_OUT_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_OUT_15_POS (15)

/* OUT 16 */
#define MXC_F_GPIO_OUT_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_OUT_16_POS (16)

/* OUT 17 */
#define MXC_F_GPIO_OUT_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_OUT_17_POS (17)

/* OUT 18 */
#define MXC_F_GPIO_OUT_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_OUT_18_POS (18)

/* OUT 19 */
#define MXC_F_GPIO_OUT_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_OUT_19_POS (19)

/* OUT 20 */
#define MXC_F_GPIO_OUT_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_OUT_20_POS (20)

/* OUT 21 */
#define MXC_F_GPIO_OUT_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_OUT_21_POS (21)

/* OUT 22 */
#define MXC_F_GPIO_OUT_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_OUT_22_POS (22)

/* OUT 23 */
#define MXC_F_GPIO_OUT_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_OUT_23_POS (23)

/* OUT 24 */
#define MXC_F_GPIO_OUT_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_OUT_24_POS (24)

/* OUT 25 */
#define MXC_F_GPIO_OUT_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_OUT_25_POS (25)

/* OUT 26 */
#define MXC_F_GPIO_OUT_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_OUT_26_POS (26)

/* OUT 27 */
#define MXC_F_GPIO_OUT_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_OUT_27_POS (27)

/* OUT 28 */
#define MXC_F_GPIO_OUT_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_OUT_28_POS (28)

/* OUT 29 */
#define MXC_F_GPIO_OUT_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_OUT_29_POS (29)

/* OUT 30 */
#define MXC_F_GPIO_OUT_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_OUT_30_POS (30)

/* OUT 31 */
#define MXC_F_GPIO_OUT_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_OUT_31_POS (31)

/* OUT_SET 00 */
#define MXC_F_GPIO_OUT_SET_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_OUT_SET_00_POS (0)

/* OUT_SET 01 */
#define MXC_F_GPIO_OUT_SET_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_OUT_SET_01_POS (1)

/* OUT_SET 02 */
#define MXC_F_GPIO_OUT_SET_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_OUT_SET_02_POS (2)

/* OUT_SET 03 */
#define MXC_F_GPIO_OUT_SET_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_OUT_SET_03_POS (3)

/* OUT_SET 04 */
#define MXC_F_GPIO_OUT_SET_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_OUT_SET_04_POS (4)

/* OUT_SET 05 */
#define MXC_F_GPIO_OUT_SET_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_OUT_SET_05_POS (5)

/* OUT_SET 06 */
#define MXC_F_GPIO_OUT_SET_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_OUT_SET_06_POS (6)

/* OUT_SET 07 */
#define MXC_F_GPIO_OUT_SET_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_OUT_SET_07_POS (7)

/* OUT_SET 08 */
#define MXC_F_GPIO_OUT_SET_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_OUT_SET_08_POS (8)

/* OUT_SET 09 */
#define MXC_F_GPIO_OUT_SET_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_OUT_SET_09_POS (9)

/* OUT_SET 10 */
#define MXC_F_GPIO_OUT_SET_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_OUT_SET_10_POS (10)

/* OUT_SET 11 */
#define MXC_F_GPIO_OUT_SET_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_OUT_SET_11_POS (11)

/* OUT_SET 12 */
#define MXC_F_GPIO_OUT_SET_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_OUT_SET_12_POS (12)

/* OUT_SET 13 */
#define MXC_F_GPIO_OUT_SET_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_OUT_SET_13_POS (13)

/* OUT_SET 14 */
#define MXC_F_GPIO_OUT_SET_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_OUT_SET_14_POS (14)

/* OUT_SET 15 */
#define MXC_F_GPIO_OUT_SET_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_OUT_SET_15_POS (15)

/* OUT_SET 16 */
#define MXC_F_GPIO_OUT_SET_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_OUT_SET_16_POS (16)

/* OUT_SET 17 */
#define MXC_F_GPIO_OUT_SET_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_OUT_SET_17_POS (17)

/* OUT_SET 18 */
#define MXC_F_GPIO_OUT_SET_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_OUT_SET_18_POS (18)

/* OUT_SET 19 */
#define MXC_F_GPIO_OUT_SET_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_OUT_SET_19_POS (19)

/* OUT_SET 20 */
#define MXC_F_GPIO_OUT_SET_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_OUT_SET_20_POS (20)

/* OUT_SET 21 */
#define MXC_F_GPIO_OUT_SET_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_OUT_SET_21_POS (21)

/* OUT_SET 22 */
#define MXC_F_GPIO_OUT_SET_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_OUT_SET_22_POS (22)

/* OUT_SET 23 */
#define MXC_F_GPIO_OUT_SET_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_OUT_SET_23_POS (23)

/* OUT_SET 24 */
#define MXC_F_GPIO_OUT_SET_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_OUT_SET_24_POS (24)

/* OUT_SET 25 */
#define MXC_F_GPIO_OUT_SET_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_OUT_SET_25_POS (25)

/* OUT_SET 26 */
#define MXC_F_GPIO_OUT_SET_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_OUT_SET_26_POS (26)

/* OUT_SET 27 */
#define MXC_F_GPIO_OUT_SET_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_OUT_SET_27_POS (27)

/* OUT_SET 28 */
#define MXC_F_GPIO_OUT_SET_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_OUT_SET_28_POS (28)

/* OUT_SET 29 */
#define MXC_F_GPIO_OUT_SET_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_OUT_SET_29_POS (29)

/* OUT_SET 30 */
#define MXC_F_GPIO_OUT_SET_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_OUT_SET_30_POS (30)

/* OUT_SET 31 */
#define MXC_F_GPIO_OUT_SET_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_OUT_SET_31_POS (31)

/* OUT_CLR 00 */
#define MXC_F_GPIO_OUT_CLR_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_OUT_CLR_00_POS (0)

/* OUT_CLR 01 */
#define MXC_F_GPIO_OUT_CLR_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_OUT_CLR_01_POS (1)

/* OUT_CLR 02 */
#define MXC_F_GPIO_OUT_CLR_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_OUT_CLR_02_POS (2)

/* OUT_CLR 03 */
#define MXC_F_GPIO_OUT_CLR_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_OUT_CLR_03_POS (3)

/* OUT_CLR 04 */
#define MXC_F_GPIO_OUT_CLR_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_OUT_CLR_04_POS (4)

/* OUT_CLR 05 */
#define MXC_F_GPIO_OUT_CLR_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_OUT_CLR_05_POS (5)

/* OUT_CLR 06 */
#define MXC_F_GPIO_OUT_CLR_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_OUT_CLR_06_POS (6)

/* OUT_CLR 07 */
#define MXC_F_GPIO_OUT_CLR_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_OUT_CLR_07_POS (7)

/* OUT_CLR 08 */
#define MXC_F_GPIO_OUT_CLR_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_OUT_CLR_08_POS (8)

/* OUT_CLR 09 */
#define MXC_F_GPIO_OUT_CLR_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_OUT_CLR_09_POS (9)

/* OUT_CLR 10 */
#define MXC_F_GPIO_OUT_CLR_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_OUT_CLR_10_POS (10)

/* OUT_CLR 11 */
#define MXC_F_GPIO_OUT_CLR_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_OUT_CLR_11_POS (11)

/* OUT_CLR 12 */
#define MXC_F_GPIO_OUT_CLR_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_OUT_CLR_12_POS (12)

/* OUT_CLR 13 */
#define MXC_F_GPIO_OUT_CLR_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_OUT_CLR_13_POS (13)

/* OUT_CLR 14 */
#define MXC_F_GPIO_OUT_CLR_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_OUT_CLR_14_POS (14)

/* OUT_CLR 15 */
#define MXC_F_GPIO_OUT_CLR_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_OUT_CLR_15_POS (15)

/* OUT_CLR 16 */
#define MXC_F_GPIO_OUT_CLR_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_OUT_CLR_16_POS (16)

/* OUT_CLR 17 */
#define MXC_F_GPIO_OUT_CLR_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_OUT_CLR_17_POS (17)

/* OUT_CLR 18 */
#define MXC_F_GPIO_OUT_CLR_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_OUT_CLR_18_POS (18)

/* OUT_CLR 19 */
#define MXC_F_GPIO_OUT_CLR_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_OUT_CLR_19_POS (19)

/* OUT_CLR 20 */
#define MXC_F_GPIO_OUT_CLR_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_OUT_CLR_20_POS (20)

/* OUT_CLR 21 */
#define MXC_F_GPIO_OUT_CLR_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_OUT_CLR_21_POS (21)

/* OUT_CLR 22 */
#define MXC_F_GPIO_OUT_CLR_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_OUT_CLR_22_POS (22)

/* OUT_CLR 23 */
#define MXC_F_GPIO_OUT_CLR_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_OUT_CLR_23_POS (23)

/* OUT_CLR 24 */
#define MXC_F_GPIO_OUT_CLR_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_OUT_CLR_24_POS (24)

/* OUT_CLR 25 */
#define MXC_F_GPIO_OUT_CLR_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_OUT_CLR_25_POS (25)

/* OUT_CLR 26 */
#define MXC_F_GPIO_OUT_CLR_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_OUT_CLR_26_POS (26)

/* OUT_CLR 27 */
#define MXC_F_GPIO_OUT_CLR_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_OUT_CLR_27_POS (27)

/* OUT_CLR 28 */
#define MXC_F_GPIO_OUT_CLR_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_OUT_CLR_28_POS (28)

/* OUT_CLR 29 */
#define MXC_F_GPIO_OUT_CLR_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_OUT_CLR_29_POS (29)

/* OUT_CLR 30 */
#define MXC_F_GPIO_OUT_CLR_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_OUT_CLR_30_POS (30)

/* OUT_CLR 31 */
#define MXC_F_GPIO_OUT_CLR_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_OUT_CLR_31_POS (31)

/* IN 00 */
#define MXC_F_GPIO_IN_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_IN_00_POS (0)

/* IN 01 */
#define MXC_F_GPIO_IN_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_IN_01_POS (1)

/* IN 02 */
#define MXC_F_GPIO_IN_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_IN_02_POS (2)

/* IN 03 */
#define MXC_F_GPIO_IN_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_IN_03_POS (3)

/* IN 04 */
#define MXC_F_GPIO_IN_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_IN_04_POS (4)

/* IN 05 */
#define MXC_F_GPIO_IN_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_IN_05_POS (5)

/* IN 06 */
#define MXC_F_GPIO_IN_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_IN_06_POS (6)

/* IN 07 */
#define MXC_F_GPIO_IN_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_IN_07_POS (7)

/* IN 08 */
#define MXC_F_GPIO_IN_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_IN_08_POS (8)

/* IN 09 */
#define MXC_F_GPIO_IN_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_IN_09_POS (9)

/* IN 10 */
#define MXC_F_GPIO_IN_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_IN_10_POS (10)

/* IN 11 */
#define MXC_F_GPIO_IN_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_IN_11_POS (11)

/* IN 12 */
#define MXC_F_GPIO_IN_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_IN_12_POS (12)

/* IN 13 */
#define MXC_F_GPIO_IN_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_IN_13_POS (13)

/* IN 14 */
#define MXC_F_GPIO_IN_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_IN_14_POS (14)

/* IN 15 */
#define MXC_F_GPIO_IN_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_IN_15_POS (15)

/* IN 16 */
#define MXC_F_GPIO_IN_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_IN_16_POS (16)

/* IN 17 */
#define MXC_F_GPIO_IN_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_IN_17_POS (17)

/* IN 18 */
#define MXC_F_GPIO_IN_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_IN_18_POS (18)

/* IN 19 */
#define MXC_F_GPIO_IN_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_IN_19_POS (19)

/* IN 20 */
#define MXC_F_GPIO_IN_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_IN_20_POS (20)

/* IN 21 */
#define MXC_F_GPIO_IN_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_IN_21_POS (21)

/* IN 22 */
#define MXC_F_GPIO_IN_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_IN_22_POS (22)

/* IN 23 */
#define MXC_F_GPIO_IN_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_IN_23_POS (23)

/* IN 24 */
#define MXC_F_GPIO_IN_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_IN_24_POS (24)

/* IN 25 */
#define MXC_F_GPIO_IN_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_IN_25_POS (25)

/* IN 26 */
#define MXC_F_GPIO_IN_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_IN_26_POS (26)

/* IN 27 */
#define MXC_F_GPIO_IN_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_IN_27_POS (27)

/* IN 28 */
#define MXC_F_GPIO_IN_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_IN_28_POS (28)

/* IN 29 */
#define MXC_F_GPIO_IN_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_IN_29_POS (29)

/* IN 30 */
#define MXC_F_GPIO_IN_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_IN_30_POS (30)

/* IN 31 */
#define MXC_F_GPIO_IN_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_IN_31_POS (31)

/* INT_MOD 00 */
#define MXC_F_GPIO_INT_MOD_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_INT_MOD_00_POS (0)

/* INT_MOD 01 */
#define MXC_F_GPIO_INT_MOD_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_INT_MOD_01_POS (1)

/* INT_MOD 02 */
#define MXC_F_GPIO_INT_MOD_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_INT_MOD_02_POS (2)

/* INT_MOD 03 */
#define MXC_F_GPIO_INT_MOD_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_INT_MOD_03_POS (3)

/* INT_MOD 04 */
#define MXC_F_GPIO_INT_MOD_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_INT_MOD_04_POS (4)

/* INT_MOD 05 */
#define MXC_F_GPIO_INT_MOD_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_INT_MOD_05_POS (5)

/* INT_MOD 06 */
#define MXC_F_GPIO_INT_MOD_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_INT_MOD_06_POS (6)

/* INT_MOD 07 */
#define MXC_F_GPIO_INT_MOD_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_INT_MOD_07_POS (7)

/* INT_MOD 08 */
#define MXC_F_GPIO_INT_MOD_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_INT_MOD_08_POS (8)

/* INT_MOD 09 */
#define MXC_F_GPIO_INT_MOD_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_INT_MOD_09_POS (9)

/* INT_MOD 10 */
#define MXC_F_GPIO_INT_MOD_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_INT_MOD_10_POS (10)

/* INT_MOD 11 */
#define MXC_F_GPIO_INT_MOD_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_INT_MOD_11_POS (11)

/* INT_MOD 12 */
#define MXC_F_GPIO_INT_MOD_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_INT_MOD_12_POS (12)

/* INT_MOD 13 */
#define MXC_F_GPIO_INT_MOD_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_INT_MOD_13_POS (13)

/* INT_MOD 14 */
#define MXC_F_GPIO_INT_MOD_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_INT_MOD_14_POS (14)

/* INT_MOD 15 */
#define MXC_F_GPIO_INT_MOD_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_INT_MOD_15_POS (15)

/* INT_MOD 16 */
#define MXC_F_GPIO_INT_MOD_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_INT_MOD_16_POS (16)

/* INT_MOD 17 */
#define MXC_F_GPIO_INT_MOD_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_INT_MOD_17_POS (17)

/* INT_MOD 18 */
#define MXC_F_GPIO_INT_MOD_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_INT_MOD_18_POS (18)

/* INT_MOD 19 */
#define MXC_F_GPIO_INT_MOD_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_INT_MOD_19_POS (19)

/* INT_MOD 20 */
#define MXC_F_GPIO_INT_MOD_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_INT_MOD_20_POS (20)

/* INT_MOD 21 */
#define MXC_F_GPIO_INT_MOD_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_INT_MOD_21_POS (21)

/* INT_MOD 22 */
#define MXC_F_GPIO_INT_MOD_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_INT_MOD_22_POS (22)

/* INT_MOD 23 */
#define MXC_F_GPIO_INT_MOD_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_INT_MOD_23_POS (23)

/* INT_MOD 24 */
#define MXC_F_GPIO_INT_MOD_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_INT_MOD_24_POS (24)

/* INT_MOD 25 */
#define MXC_F_GPIO_INT_MOD_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_INT_MOD_25_POS (25)

/* INT_MOD 26 */
#define MXC_F_GPIO_INT_MOD_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_INT_MOD_26_POS (26)

/* INT_MOD 27 */
#define MXC_F_GPIO_INT_MOD_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_INT_MOD_27_POS (27)

/* INT_MOD 28 */
#define MXC_F_GPIO_INT_MOD_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_INT_MOD_28_POS (28)

/* INT_MOD 29 */
#define MXC_F_GPIO_INT_MOD_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_INT_MOD_29_POS (29)

/* INT_MOD 30 */
#define MXC_F_GPIO_INT_MOD_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_INT_MOD_30_POS (30)

/* INT_MOD 31 */
#define MXC_F_GPIO_INT_MOD_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_INT_MOD_31_POS (31)

/* INT_POL 00 */
#define MXC_F_GPIO_INT_POL_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_INT_POL_00_POS (0)

/* INT_POL 01 */
#define MXC_F_GPIO_INT_POL_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_INT_POL_01_POS (1)

/* INT_POL 02 */
#define MXC_F_GPIO_INT_POL_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_INT_POL_02_POS (2)

/* INT_POL 03 */
#define MXC_F_GPIO_INT_POL_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_INT_POL_03_POS (3)

/* INT_POL 04 */
#define MXC_F_GPIO_INT_POL_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_INT_POL_04_POS (4)

/* INT_POL 05 */
#define MXC_F_GPIO_INT_POL_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_INT_POL_05_POS (5)

/* INT_POL 06 */
#define MXC_F_GPIO_INT_POL_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_INT_POL_06_POS (6)

/* INT_POL 07 */
#define MXC_F_GPIO_INT_POL_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_INT_POL_07_POS (7)

/* INT_POL 08 */
#define MXC_F_GPIO_INT_POL_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_INT_POL_08_POS (8)

/* INT_POL 09 */
#define MXC_F_GPIO_INT_POL_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_INT_POL_09_POS (9)

/* INT_POL 10 */
#define MXC_F_GPIO_INT_POL_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_INT_POL_10_POS (10)

/* INT_POL 11 */
#define MXC_F_GPIO_INT_POL_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_INT_POL_11_POS (11)

/* INT_POL 12 */
#define MXC_F_GPIO_INT_POL_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_INT_POL_12_POS (12)

/* INT_POL 13 */
#define MXC_F_GPIO_INT_POL_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_INT_POL_13_POS (13)

/* INT_POL 14 */
#define MXC_F_GPIO_INT_POL_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_INT_POL_14_POS (14)

/* INT_POL 15 */
#define MXC_F_GPIO_INT_POL_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_INT_POL_15_POS (15)

/* INT_POL 16 */
#define MXC_F_GPIO_INT_POL_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_INT_POL_16_POS (16)

/* INT_POL 17 */
#define MXC_F_GPIO_INT_POL_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_INT_POL_17_POS (17)

/* INT_POL 18 */
#define MXC_F_GPIO_INT_POL_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_INT_POL_18_POS (18)

/* INT_POL 19 */
#define MXC_F_GPIO_INT_POL_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_INT_POL_19_POS (19)

/* INT_POL 20 */
#define MXC_F_GPIO_INT_POL_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_INT_POL_20_POS (20)

/* INT_POL 21 */
#define MXC_F_GPIO_INT_POL_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_INT_POL_21_POS (21)

/* INT_POL 22 */
#define MXC_F_GPIO_INT_POL_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_INT_POL_22_POS (22)

/* INT_POL 23 */
#define MXC_F_GPIO_INT_POL_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_INT_POL_23_POS (23)

/* INT_POL 24 */
#define MXC_F_GPIO_INT_POL_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_INT_POL_24_POS (24)

/* INT_POL 25 */
#define MXC_F_GPIO_INT_POL_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_INT_POL_25_POS (25)

/* INT_POL 26 */
#define MXC_F_GPIO_INT_POL_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_INT_POL_26_POS (26)

/* INT_POL 27 */
#define MXC_F_GPIO_INT_POL_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_INT_POL_27_POS (27)

/* INT_POL 28 */
#define MXC_F_GPIO_INT_POL_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_INT_POL_28_POS (28)

/* INT_POL 29 */
#define MXC_F_GPIO_INT_POL_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_INT_POL_29_POS (29)

/* INT_POL 30 */
#define MXC_F_GPIO_INT_POL_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_INT_POL_30_POS (30)

/* INT_POL 31 */
#define MXC_F_GPIO_INT_POL_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_INT_POL_31_POS (31)

/* INT_EN 00 */
#define MXC_F_GPIO_INT_EN_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_INT_EN_00_POS (0)

/* INT_EN 01 */
#define MXC_F_GPIO_INT_EN_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_INT_EN_01_POS (1)

/* INT_EN 02 */
#define MXC_F_GPIO_INT_EN_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_INT_EN_02_POS (2)

/* INT_EN 03 */
#define MXC_F_GPIO_INT_EN_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_INT_EN_03_POS (3)

/* INT_EN 04 */
#define MXC_F_GPIO_INT_EN_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_INT_EN_04_POS (4)

/* INT_EN 05 */
#define MXC_F_GPIO_INT_EN_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_INT_EN_05_POS (5)

/* INT_EN 06 */
#define MXC_F_GPIO_INT_EN_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_INT_EN_06_POS (6)

/* INT_EN 07 */
#define MXC_F_GPIO_INT_EN_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_INT_EN_07_POS (7)

/* INT_EN 08 */
#define MXC_F_GPIO_INT_EN_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_INT_EN_08_POS (8)

/* INT_EN 09 */
#define MXC_F_GPIO_INT_EN_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_INT_EN_09_POS (9)

/* INT_EN 10 */
#define MXC_F_GPIO_INT_EN_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_INT_EN_10_POS (10)

/* INT_EN 11 */
#define MXC_F_GPIO_INT_EN_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_INT_EN_11_POS (11)

/* INT_EN 12 */
#define MXC_F_GPIO_INT_EN_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_INT_EN_12_POS (12)

/* INT_EN 13 */
#define MXC_F_GPIO_INT_EN_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_INT_EN_13_POS (13)

/* INT_EN 14 */
#define MXC_F_GPIO_INT_EN_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_INT_EN_14_POS (14)

/* INT_EN 15 */
#define MXC_F_GPIO_INT_EN_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_INT_EN_15_POS (15)

/* INT_EN 16 */
#define MXC_F_GPIO_INT_EN_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_INT_EN_16_POS (16)

/* INT_EN 17 */
#define MXC_F_GPIO_INT_EN_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_INT_EN_17_POS (17)

/* INT_EN 18 */
#define MXC_F_GPIO_INT_EN_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_INT_EN_18_POS (18)

/* INT_EN 19 */
#define MXC_F_GPIO_INT_EN_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_INT_EN_19_POS (19)

/* INT_EN 20 */
#define MXC_F_GPIO_INT_EN_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_INT_EN_20_POS (20)

/* INT_EN 21 */
#define MXC_F_GPIO_INT_EN_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_INT_EN_21_POS (21)

/* INT_EN 22 */
#define MXC_F_GPIO_INT_EN_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_INT_EN_22_POS (22)

/* INT_EN 23 */
#define MXC_F_GPIO_INT_EN_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_INT_EN_23_POS (23)

/* INT_EN 24 */
#define MXC_F_GPIO_INT_EN_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_INT_EN_24_POS (24)

/* INT_EN 25 */
#define MXC_F_GPIO_INT_EN_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_INT_EN_25_POS (25)

/* INT_EN 26 */
#define MXC_F_GPIO_INT_EN_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_INT_EN_26_POS (26)

/* INT_EN 27 */
#define MXC_F_GPIO_INT_EN_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_INT_EN_27_POS (27)

/* INT_EN 28 */
#define MXC_F_GPIO_INT_EN_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_INT_EN_28_POS (28)

/* INT_EN 29 */
#define MXC_F_GPIO_INT_EN_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_INT_EN_29_POS (29)

/* INT_EN 30 */
#define MXC_F_GPIO_INT_EN_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_INT_EN_30_POS (30)

/* INT_EN 31 */
#define MXC_F_GPIO_INT_EN_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_INT_EN_31_POS (31)

/* INT_EN_SET 00 */
#define MXC_F_GPIO_INT_EN_SET_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_INT_EN_SET_00_POS (0)

/* INT_EN_SET 01 */
#define MXC_F_GPIO_INT_EN_SET_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_INT_EN_SET_01_POS (1)

/* INT_EN_SET 02 */
#define MXC_F_GPIO_INT_EN_SET_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_INT_EN_SET_02_POS (2)

/* INT_EN_SET 03 */
#define MXC_F_GPIO_INT_EN_SET_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_INT_EN_SET_03_POS (3)

/* INT_EN_SET 04 */
#define MXC_F_GPIO_INT_EN_SET_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_INT_EN_SET_04_POS (4)

/* INT_EN_SET 05 */
#define MXC_F_GPIO_INT_EN_SET_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_INT_EN_SET_05_POS (5)

/* INT_EN_SET 06 */
#define MXC_F_GPIO_INT_EN_SET_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_INT_EN_SET_06_POS (6)

/* INT_EN_SET 07 */
#define MXC_F_GPIO_INT_EN_SET_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_INT_EN_SET_07_POS (7)

/* INT_EN_SET 08 */
#define MXC_F_GPIO_INT_EN_SET_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_INT_EN_SET_08_POS (8)

/* INT_EN_SET 09 */
#define MXC_F_GPIO_INT_EN_SET_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_INT_EN_SET_09_POS (9)

/* INT_EN_SET 10 */
#define MXC_F_GPIO_INT_EN_SET_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_INT_EN_SET_10_POS (10)

/* INT_EN_SET 11 */
#define MXC_F_GPIO_INT_EN_SET_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_INT_EN_SET_11_POS (11)

/* INT_EN_SET 12 */
#define MXC_F_GPIO_INT_EN_SET_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_INT_EN_SET_12_POS (12)

/* INT_EN_SET 13 */
#define MXC_F_GPIO_INT_EN_SET_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_INT_EN_SET_13_POS (13)

/* INT_EN_SET 14 */
#define MXC_F_GPIO_INT_EN_SET_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_INT_EN_SET_14_POS (14)

/* INT_EN_SET 15 */
#define MXC_F_GPIO_INT_EN_SET_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_INT_EN_SET_15_POS (15)

/* INT_EN_SET 16 */
#define MXC_F_GPIO_INT_EN_SET_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_INT_EN_SET_16_POS (16)

/* INT_EN_SET 17 */
#define MXC_F_GPIO_INT_EN_SET_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_INT_EN_SET_17_POS (17)

/* INT_EN_SET 18 */
#define MXC_F_GPIO_INT_EN_SET_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_INT_EN_SET_18_POS (18)

/* INT_EN_SET 19 */
#define MXC_F_GPIO_INT_EN_SET_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_INT_EN_SET_19_POS (19)

/* INT_EN_SET 20 */
#define MXC_F_GPIO_INT_EN_SET_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_INT_EN_SET_20_POS (20)

/* INT_EN_SET 21 */
#define MXC_F_GPIO_INT_EN_SET_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_INT_EN_SET_21_POS (21)

/* INT_EN_SET 22 */
#define MXC_F_GPIO_INT_EN_SET_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_INT_EN_SET_22_POS (22)

/* INT_EN_SET 23 */
#define MXC_F_GPIO_INT_EN_SET_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_INT_EN_SET_23_POS (23)

/* INT_EN_SET 24 */
#define MXC_F_GPIO_INT_EN_SET_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_INT_EN_SET_24_POS (24)

/* INT_EN_SET 25 */
#define MXC_F_GPIO_INT_EN_SET_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_INT_EN_SET_25_POS (25)

/* INT_EN_SET 26 */
#define MXC_F_GPIO_INT_EN_SET_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_INT_EN_SET_26_POS (26)

/* INT_EN_SET 27 */
#define MXC_F_GPIO_INT_EN_SET_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_INT_EN_SET_27_POS (27)

/* INT_EN_SET 28 */
#define MXC_F_GPIO_INT_EN_SET_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_INT_EN_SET_28_POS (28)

/* INT_EN_SET 29 */
#define MXC_F_GPIO_INT_EN_SET_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_INT_EN_SET_29_POS (29)

/* INT_EN_SET 30 */
#define MXC_F_GPIO_INT_EN_SET_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_INT_EN_SET_30_POS (30)

/* INT_EN_SET 31 */
#define MXC_F_GPIO_INT_EN_SET_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_INT_EN_SET_31_POS (31)

/* INT_EN_CLR 00 */
#define MXC_F_GPIO_INT_EN_CLR_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_INT_EN_CLR_00_POS (0)

/* INT_EN_CLR 01 */
#define MXC_F_GPIO_INT_EN_CLR_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_INT_EN_CLR_01_POS (1)

/* INT_EN_CLR 02 */
#define MXC_F_GPIO_INT_EN_CLR_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_INT_EN_CLR_02_POS (2)

/* INT_EN_CLR 03 */
#define MXC_F_GPIO_INT_EN_CLR_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_INT_EN_CLR_03_POS (3)

/* INT_EN_CLR 04 */
#define MXC_F_GPIO_INT_EN_CLR_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_INT_EN_CLR_04_POS (4)

/* INT_EN_CLR 05 */
#define MXC_F_GPIO_INT_EN_CLR_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_INT_EN_CLR_05_POS (5)

/* INT_EN_CLR 06 */
#define MXC_F_GPIO_INT_EN_CLR_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_INT_EN_CLR_06_POS (6)

/* INT_EN_CLR 07 */
#define MXC_F_GPIO_INT_EN_CLR_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_INT_EN_CLR_07_POS (7)

/* INT_EN_CLR 08 */
#define MXC_F_GPIO_INT_EN_CLR_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_INT_EN_CLR_08_POS (8)

/* INT_EN_CLR 09 */
#define MXC_F_GPIO_INT_EN_CLR_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_INT_EN_CLR_09_POS (9)

/* INT_EN_CLR 10 */
#define MXC_F_GPIO_INT_EN_CLR_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_INT_EN_CLR_10_POS (10)

/* INT_EN_CLR 11 */
#define MXC_F_GPIO_INT_EN_CLR_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_INT_EN_CLR_11_POS (11)

/* INT_EN_CLR 12 */
#define MXC_F_GPIO_INT_EN_CLR_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_INT_EN_CLR_12_POS (12)

/* INT_EN_CLR 13 */
#define MXC_F_GPIO_INT_EN_CLR_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_INT_EN_CLR_13_POS (13)

/* INT_EN_CLR 14 */
#define MXC_F_GPIO_INT_EN_CLR_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_INT_EN_CLR_14_POS (14)

/* INT_EN_CLR 15 */
#define MXC_F_GPIO_INT_EN_CLR_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_INT_EN_CLR_15_POS (15)

/* INT_EN_CLR 16 */
#define MXC_F_GPIO_INT_EN_CLR_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_INT_EN_CLR_16_POS (16)

/* INT_EN_CLR 17 */
#define MXC_F_GPIO_INT_EN_CLR_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_INT_EN_CLR_17_POS (17)

/* INT_EN_CLR 18 */
#define MXC_F_GPIO_INT_EN_CLR_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_INT_EN_CLR_18_POS (18)

/* INT_EN_CLR 19 */
#define MXC_F_GPIO_INT_EN_CLR_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_INT_EN_CLR_19_POS (19)

/* INT_EN_CLR 20 */
#define MXC_F_GPIO_INT_EN_CLR_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_INT_EN_CLR_20_POS (20)

/* INT_EN_CLR 21 */
#define MXC_F_GPIO_INT_EN_CLR_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_INT_EN_CLR_21_POS (21)

/* INT_EN_CLR 22 */
#define MXC_F_GPIO_INT_EN_CLR_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_INT_EN_CLR_22_POS (22)

/* INT_EN_CLR 23 */
#define MXC_F_GPIO_INT_EN_CLR_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_INT_EN_CLR_23_POS (23)

/* INT_EN_CLR 24 */
#define MXC_F_GPIO_INT_EN_CLR_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_INT_EN_CLR_24_POS (24)

/* INT_EN_CLR 25 */
#define MXC_F_GPIO_INT_EN_CLR_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_INT_EN_CLR_25_POS (25)

/* INT_EN_CLR 26 */
#define MXC_F_GPIO_INT_EN_CLR_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_INT_EN_CLR_26_POS (26)

/* INT_EN_CLR 27 */
#define MXC_F_GPIO_INT_EN_CLR_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_INT_EN_CLR_27_POS (27)

/* INT_EN_CLR 28 */
#define MXC_F_GPIO_INT_EN_CLR_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_INT_EN_CLR_28_POS (28)

/* INT_EN_CLR 29 */
#define MXC_F_GPIO_INT_EN_CLR_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_INT_EN_CLR_29_POS (29)

/* INT_EN_CLR 30 */
#define MXC_F_GPIO_INT_EN_CLR_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_INT_EN_CLR_30_POS (30)

/* INT_EN_CLR 31 */
#define MXC_F_GPIO_INT_EN_CLR_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_INT_EN_CLR_31_POS (31)

/* INT_STAT 00 */
#define MXC_F_GPIO_INT_STAT_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_INT_STAT_00_POS (0)

/* INT_STAT 01 */
#define MXC_F_GPIO_INT_STAT_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_INT_STAT_01_POS (1)

/* INT_STAT 02 */
#define MXC_F_GPIO_INT_STAT_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_INT_STAT_02_POS (2)

/* INT_STAT 03 */
#define MXC_F_GPIO_INT_STAT_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_INT_STAT_03_POS (3)

/* INT_STAT 04 */
#define MXC_F_GPIO_INT_STAT_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_INT_STAT_04_POS (4)

/* INT_STAT 05 */
#define MXC_F_GPIO_INT_STAT_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_INT_STAT_05_POS (5)

/* INT_STAT 06 */
#define MXC_F_GPIO_INT_STAT_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_INT_STAT_06_POS (6)

/* INT_STAT 07 */
#define MXC_F_GPIO_INT_STAT_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_INT_STAT_07_POS (7)

/* INT_STAT 08 */
#define MXC_F_GPIO_INT_STAT_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_INT_STAT_08_POS (8)

/* INT_STAT 09 */
#define MXC_F_GPIO_INT_STAT_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_INT_STAT_09_POS (9)

/* INT_STAT 10 */
#define MXC_F_GPIO_INT_STAT_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_INT_STAT_10_POS (10)

/* INT_STAT 11 */
#define MXC_F_GPIO_INT_STAT_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_INT_STAT_11_POS (11)

/* INT_STAT 12 */
#define MXC_F_GPIO_INT_STAT_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_INT_STAT_12_POS (12)

/* INT_STAT 13 */
#define MXC_F_GPIO_INT_STAT_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_INT_STAT_13_POS (13)

/* INT_STAT 14 */
#define MXC_F_GPIO_INT_STAT_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_INT_STAT_14_POS (14)

/* INT_STAT 15 */
#define MXC_F_GPIO_INT_STAT_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_INT_STAT_15_POS (15)

/* INT_STAT 16 */
#define MXC_F_GPIO_INT_STAT_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_INT_STAT_16_POS (16)

/* INT_STAT 17 */
#define MXC_F_GPIO_INT_STAT_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_INT_STAT_17_POS (17)

/* INT_STAT 18 */
#define MXC_F_GPIO_INT_STAT_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_INT_STAT_18_POS (18)

/* INT_STAT 19 */
#define MXC_F_GPIO_INT_STAT_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_INT_STAT_19_POS (19)

/* INT_STAT 20 */
#define MXC_F_GPIO_INT_STAT_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_INT_STAT_20_POS (20)

/* INT_STAT 21 */
#define MXC_F_GPIO_INT_STAT_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_INT_STAT_21_POS (21)

/* INT_STAT 22 */
#define MXC_F_GPIO_INT_STAT_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_INT_STAT_22_POS (22)

/* INT_STAT 23 */
#define MXC_F_GPIO_INT_STAT_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_INT_STAT_23_POS (23)

/* INT_STAT 24 */
#define MXC_F_GPIO_INT_STAT_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_INT_STAT_24_POS (24)

/* INT_STAT 25 */
#define MXC_F_GPIO_INT_STAT_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_INT_STAT_25_POS (25)

/* INT_STAT 26 */
#define MXC_F_GPIO_INT_STAT_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_INT_STAT_26_POS (26)

/* INT_STAT 27 */
#define MXC_F_GPIO_INT_STAT_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_INT_STAT_27_POS (27)

/* INT_STAT 28 */
#define MXC_F_GPIO_INT_STAT_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_INT_STAT_28_POS (28)

/* INT_STAT 29 */
#define MXC_F_GPIO_INT_STAT_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_INT_STAT_29_POS (29)

/* INT_STAT 30 */
#define MXC_F_GPIO_INT_STAT_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_INT_STAT_30_POS (30)

/* INT_STAT 31 */
#define MXC_F_GPIO_INT_STAT_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_INT_STAT_31_POS (31)

/* INT_CLR 00 */
#define MXC_F_GPIO_INT_CLR_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_INT_CLR_00_POS (0)

/* INT_CLR 01 */
#define MXC_F_GPIO_INT_CLR_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_INT_CLR_01_POS (1)

/* INT_CLR 02 */
#define MXC_F_GPIO_INT_CLR_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_INT_CLR_02_POS (2)

/* INT_CLR 03 */
#define MXC_F_GPIO_INT_CLR_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_INT_CLR_03_POS (3)

/* INT_CLR 04 */
#define MXC_F_GPIO_INT_CLR_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_INT_CLR_04_POS (4)

/* INT_CLR 05 */
#define MXC_F_GPIO_INT_CLR_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_INT_CLR_05_POS (5)

/* INT_CLR 06 */
#define MXC_F_GPIO_INT_CLR_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_INT_CLR_06_POS (6)

/* INT_CLR 07 */
#define MXC_F_GPIO_INT_CLR_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_INT_CLR_07_POS (7)

/* INT_CLR 08 */
#define MXC_F_GPIO_INT_CLR_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_INT_CLR_08_POS (8)

/* INT_CLR 09 */
#define MXC_F_GPIO_INT_CLR_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_INT_CLR_09_POS (9)

/* INT_CLR 10 */
#define MXC_F_GPIO_INT_CLR_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_INT_CLR_10_POS (10)

/* INT_CLR 11 */
#define MXC_F_GPIO_INT_CLR_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_INT_CLR_11_POS (11)

/* INT_CLR 12 */
#define MXC_F_GPIO_INT_CLR_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_INT_CLR_12_POS (12)

/* INT_CLR 13 */
#define MXC_F_GPIO_INT_CLR_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_INT_CLR_13_POS (13)

/* INT_CLR 14 */
#define MXC_F_GPIO_INT_CLR_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_INT_CLR_14_POS (14)

/* INT_CLR 15 */
#define MXC_F_GPIO_INT_CLR_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_INT_CLR_15_POS (15)

/* INT_CLR 16 */
#define MXC_F_GPIO_INT_CLR_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_INT_CLR_16_POS (16)

/* INT_CLR 17 */
#define MXC_F_GPIO_INT_CLR_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_INT_CLR_17_POS (17)

/* INT_CLR 18 */
#define MXC_F_GPIO_INT_CLR_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_INT_CLR_18_POS (18)

/* INT_CLR 19 */
#define MXC_F_GPIO_INT_CLR_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_INT_CLR_19_POS (19)

/* INT_CLR 20 */
#define MXC_F_GPIO_INT_CLR_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_INT_CLR_20_POS (20)

/* INT_CLR 21 */
#define MXC_F_GPIO_INT_CLR_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_INT_CLR_21_POS (21)

/* INT_CLR 22 */
#define MXC_F_GPIO_INT_CLR_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_INT_CLR_22_POS (22)

/* INT_CLR 23 */
#define MXC_F_GPIO_INT_CLR_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_INT_CLR_23_POS (23)

/* INT_CLR 24 */
#define MXC_F_GPIO_INT_CLR_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_INT_CLR_24_POS (24)

/* INT_CLR 25 */
#define MXC_F_GPIO_INT_CLR_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_INT_CLR_25_POS (25)

/* INT_CLR 26 */
#define MXC_F_GPIO_INT_CLR_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_INT_CLR_26_POS (26)

/* INT_CLR 27 */
#define MXC_F_GPIO_INT_CLR_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_INT_CLR_27_POS (27)

/* INT_CLR 28 */
#define MXC_F_GPIO_INT_CLR_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_INT_CLR_28_POS (28)

/* INT_CLR 29 */
#define MXC_F_GPIO_INT_CLR_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_INT_CLR_29_POS (29)

/* INT_CLR 30 */
#define MXC_F_GPIO_INT_CLR_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_INT_CLR_30_POS (30)

/* INT_CLR 31 */
#define MXC_F_GPIO_INT_CLR_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_INT_CLR_31_POS (31)

/* WAKE_EN 00 */
#define MXC_F_GPIO_WAKE_EN_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_WAKE_EN_00_POS (0)

/* WAKE_EN 01 */
#define MXC_F_GPIO_WAKE_EN_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_WAKE_EN_01_POS (1)

/* WAKE_EN 02 */
#define MXC_F_GPIO_WAKE_EN_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_WAKE_EN_02_POS (2)

/* WAKE_EN 03 */
#define MXC_F_GPIO_WAKE_EN_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_WAKE_EN_03_POS (3)

/* WAKE_EN 04 */
#define MXC_F_GPIO_WAKE_EN_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_WAKE_EN_04_POS (4)

/* WAKE_EN 05 */
#define MXC_F_GPIO_WAKE_EN_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_WAKE_EN_05_POS (5)

/* WAKE_EN 06 */
#define MXC_F_GPIO_WAKE_EN_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_WAKE_EN_06_POS (6)

/* WAKE_EN 07 */
#define MXC_F_GPIO_WAKE_EN_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_WAKE_EN_07_POS (7)

/* WAKE_EN 08 */
#define MXC_F_GPIO_WAKE_EN_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_WAKE_EN_08_POS (8)

/* WAKE_EN 09 */
#define MXC_F_GPIO_WAKE_EN_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_WAKE_EN_09_POS (9)

/* WAKE_EN 10 */
#define MXC_F_GPIO_WAKE_EN_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_WAKE_EN_10_POS (10)

/* WAKE_EN 11 */
#define MXC_F_GPIO_WAKE_EN_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_WAKE_EN_11_POS (11)

/* WAKE_EN 12 */
#define MXC_F_GPIO_WAKE_EN_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_WAKE_EN_12_POS (12)

/* WAKE_EN 13 */
#define MXC_F_GPIO_WAKE_EN_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_WAKE_EN_13_POS (13)

/* WAKE_EN 14 */
#define MXC_F_GPIO_WAKE_EN_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_WAKE_EN_14_POS (14)

/* WAKE_EN 15 */
#define MXC_F_GPIO_WAKE_EN_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_WAKE_EN_15_POS (15)

/* WAKE_EN 16 */
#define MXC_F_GPIO_WAKE_EN_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_WAKE_EN_16_POS (16)

/* WAKE_EN 17 */
#define MXC_F_GPIO_WAKE_EN_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_WAKE_EN_17_POS (17)

/* WAKE_EN 18 */
#define MXC_F_GPIO_WAKE_EN_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_WAKE_EN_18_POS (18)

/* WAKE_EN 19 */
#define MXC_F_GPIO_WAKE_EN_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_WAKE_EN_19_POS (19)

/* WAKE_EN 20 */
#define MXC_F_GPIO_WAKE_EN_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_WAKE_EN_20_POS (20)

/* WAKE_EN 21 */
#define MXC_F_GPIO_WAKE_EN_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_WAKE_EN_21_POS (21)

/* WAKE_EN 22 */
#define MXC_F_GPIO_WAKE_EN_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_WAKE_EN_22_POS (22)

/* WAKE_EN 23 */
#define MXC_F_GPIO_WAKE_EN_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_WAKE_EN_23_POS (23)

/* WAKE_EN 24 */
#define MXC_F_GPIO_WAKE_EN_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_WAKE_EN_24_POS (24)

/* WAKE_EN 25 */
#define MXC_F_GPIO_WAKE_EN_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_WAKE_EN_25_POS (25)

/* WAKE_EN 26 */
#define MXC_F_GPIO_WAKE_EN_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_WAKE_EN_26_POS (26)

/* WAKE_EN 27 */
#define MXC_F_GPIO_WAKE_EN_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_WAKE_EN_27_POS (27)

/* WAKE_EN 28 */
#define MXC_F_GPIO_WAKE_EN_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_WAKE_EN_28_POS (28)

/* WAKE_EN 29 */
#define MXC_F_GPIO_WAKE_EN_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_WAKE_EN_29_POS (29)

/* WAKE_EN 30 */
#define MXC_F_GPIO_WAKE_EN_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_WAKE_EN_30_POS (30)

/* WAKE_EN 31 */
#define MXC_F_GPIO_WAKE_EN_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_WAKE_EN_31_POS (31)

/* INT_DUAL_EDGE 00 */
#define MXC_F_GPIO_INT_DUAL_EDGE_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_00_POS (0)

/* INT_DUAL_EDGE 01 */
#define MXC_F_GPIO_INT_DUAL_EDGE_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_01_POS (1)

/* INT_DUAL_EDGE 02 */
#define MXC_F_GPIO_INT_DUAL_EDGE_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_02_POS (2)

/* INT_DUAL_EDGE 03 */
#define MXC_F_GPIO_INT_DUAL_EDGE_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_03_POS (3)

/* INT_DUAL_EDGE 04 */
#define MXC_F_GPIO_INT_DUAL_EDGE_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_04_POS (4)

/* INT_DUAL_EDGE 05 */
#define MXC_F_GPIO_INT_DUAL_EDGE_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_05_POS (5)

/* INT_DUAL_EDGE 06 */
#define MXC_F_GPIO_INT_DUAL_EDGE_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_06_POS (6)

/* INT_DUAL_EDGE 07 */
#define MXC_F_GPIO_INT_DUAL_EDGE_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_07_POS (7)

/* INT_DUAL_EDGE 08 */
#define MXC_F_GPIO_INT_DUAL_EDGE_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_08_POS (8)

/* INT_DUAL_EDGE 09 */
#define MXC_F_GPIO_INT_DUAL_EDGE_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_09_POS (9)

/* INT_DUAL_EDGE 10 */
#define MXC_F_GPIO_INT_DUAL_EDGE_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_10_POS (10)

/* INT_DUAL_EDGE 11 */
#define MXC_F_GPIO_INT_DUAL_EDGE_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_11_POS (11)

/* INT_DUAL_EDGE 12 */
#define MXC_F_GPIO_INT_DUAL_EDGE_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_12_POS (12)

/* INT_DUAL_EDGE 13 */
#define MXC_F_GPIO_INT_DUAL_EDGE_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_13_POS (13)

/* INT_DUAL_EDGE 14 */
#define MXC_F_GPIO_INT_DUAL_EDGE_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_14_POS (14)

/* INT_DUAL_EDGE 15 */
#define MXC_F_GPIO_INT_DUAL_EDGE_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_15_POS (15)

/* INT_DUAL_EDGE 16 */
#define MXC_F_GPIO_INT_DUAL_EDGE_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_16_POS (16)

/* INT_DUAL_EDGE 17 */
#define MXC_F_GPIO_INT_DUAL_EDGE_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_17_POS (17)

/* INT_DUAL_EDGE 18 */
#define MXC_F_GPIO_INT_DUAL_EDGE_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_18_POS (18)

/* INT_DUAL_EDGE 19 */
#define MXC_F_GPIO_INT_DUAL_EDGE_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_19_POS (19)

/* INT_DUAL_EDGE 20 */
#define MXC_F_GPIO_INT_DUAL_EDGE_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_20_POS (20)

/* INT_DUAL_EDGE 21 */
#define MXC_F_GPIO_INT_DUAL_EDGE_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_21_POS (21)

/* INT_DUAL_EDGE 22 */
#define MXC_F_GPIO_INT_DUAL_EDGE_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_22_POS (22)

/* INT_DUAL_EDGE 23 */
#define MXC_F_GPIO_INT_DUAL_EDGE_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_23_POS (23)

/* INT_DUAL_EDGE 24 */
#define MXC_F_GPIO_INT_DUAL_EDGE_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_24_POS (24)

/* INT_DUAL_EDGE 25 */
#define MXC_F_GPIO_INT_DUAL_EDGE_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_25_POS (25)

/* INT_DUAL_EDGE 26 */
#define MXC_F_GPIO_INT_DUAL_EDGE_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_26_POS (26)

/* INT_DUAL_EDGE 27 */
#define MXC_F_GPIO_INT_DUAL_EDGE_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_27_POS (27)

/* INT_DUAL_EDGE 28 */
#define MXC_F_GPIO_INT_DUAL_EDGE_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_28_POS (28)

/* INT_DUAL_EDGE 29 */
#define MXC_F_GPIO_INT_DUAL_EDGE_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_29_POS (29)

/* INT_DUAL_EDGE 30 */
#define MXC_F_GPIO_INT_DUAL_EDGE_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_30_POS (30)

/* INT_DUAL_EDGE 31 */
#define MXC_F_GPIO_INT_DUAL_EDGE_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_INT_DUAL_EDGE_31_POS (31)

/* PAD_CFG1 00 */
#define MXC_F_GPIO_PAD_CFG1_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_PAD_CFG1_00_POS (0)

/* PAD_CFG1 01 */
#define MXC_F_GPIO_PAD_CFG1_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_PAD_CFG1_01_POS (1)

/* PAD_CFG1 02 */
#define MXC_F_GPIO_PAD_CFG1_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_PAD_CFG1_02_POS (2)

/* PAD_CFG1 03 */
#define MXC_F_GPIO_PAD_CFG1_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_PAD_CFG1_03_POS (3)

/* PAD_CFG1 04 */
#define MXC_F_GPIO_PAD_CFG1_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_PAD_CFG1_04_POS (4)

/* PAD_CFG1 05 */
#define MXC_F_GPIO_PAD_CFG1_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_PAD_CFG1_05_POS (5)

/* PAD_CFG1 06 */
#define MXC_F_GPIO_PAD_CFG1_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_PAD_CFG1_06_POS (6)

/* PAD_CFG1 07 */
#define MXC_F_GPIO_PAD_CFG1_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_PAD_CFG1_07_POS (7)

/* PAD_CFG1 08 */
#define MXC_F_GPIO_PAD_CFG1_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_PAD_CFG1_08_POS (8)

/* PAD_CFG1 09 */
#define MXC_F_GPIO_PAD_CFG1_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_PAD_CFG1_09_POS (9)

/* PAD_CFG1 10 */
#define MXC_F_GPIO_PAD_CFG1_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_PAD_CFG1_10_POS (10)

/* PAD_CFG1 11 */
#define MXC_F_GPIO_PAD_CFG1_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_PAD_CFG1_11_POS (11)

/* PAD_CFG1 12 */
#define MXC_F_GPIO_PAD_CFG1_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_PAD_CFG1_12_POS (12)

/* PAD_CFG1 13 */
#define MXC_F_GPIO_PAD_CFG1_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_PAD_CFG1_13_POS (13)

/* PAD_CFG1 14 */
#define MXC_F_GPIO_PAD_CFG1_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_PAD_CFG1_14_POS (14)

/* PAD_CFG1 15 */
#define MXC_F_GPIO_PAD_CFG1_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_PAD_CFG1_15_POS (15)

/* PAD_CFG1 16 */
#define MXC_F_GPIO_PAD_CFG1_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_PAD_CFG1_16_POS (16)

/* PAD_CFG1 17 */
#define MXC_F_GPIO_PAD_CFG1_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_PAD_CFG1_17_POS (17)

/* PAD_CFG1 18 */
#define MXC_F_GPIO_PAD_CFG1_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_PAD_CFG1_18_POS (18)

/* PAD_CFG1 19 */
#define MXC_F_GPIO_PAD_CFG1_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_PAD_CFG1_19_POS (19)

/* PAD_CFG1 20 */
#define MXC_F_GPIO_PAD_CFG1_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_PAD_CFG1_20_POS (20)

/* PAD_CFG1 21 */
#define MXC_F_GPIO_PAD_CFG1_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_PAD_CFG1_21_POS (21)

/* PAD_CFG1 22 */
#define MXC_F_GPIO_PAD_CFG1_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_PAD_CFG1_22_POS (22)

/* PAD_CFG1 23 */
#define MXC_F_GPIO_PAD_CFG1_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_PAD_CFG1_23_POS (23)

/* PAD_CFG1 24 */
#define MXC_F_GPIO_PAD_CFG1_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_PAD_CFG1_24_POS (24)

/* PAD_CFG1 25 */
#define MXC_F_GPIO_PAD_CFG1_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_PAD_CFG1_25_POS (25)

/* PAD_CFG1 26 */
#define MXC_F_GPIO_PAD_CFG1_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_PAD_CFG1_26_POS (26)

/* PAD_CFG1 27 */
#define MXC_F_GPIO_PAD_CFG1_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_PAD_CFG1_27_POS (27)

/* PAD_CFG1 28 */
#define MXC_F_GPIO_PAD_CFG1_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_PAD_CFG1_28_POS (28)

/* PAD_CFG1 29 */
#define MXC_F_GPIO_PAD_CFG1_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_PAD_CFG1_29_POS (29)

/* PAD_CFG1 30 */
#define MXC_F_GPIO_PAD_CFG1_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_PAD_CFG1_30_POS (30)

/* PAD_CFG1 31 */
#define MXC_F_GPIO_PAD_CFG1_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_PAD_CFG1_31_POS (31)

/* PAD_CFG2 00 */
#define MXC_F_GPIO_PAD_CFG2_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_PAD_CFG2_00_POS (0)

/* PAD_CFG2 01 */
#define MXC_F_GPIO_PAD_CFG2_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_PAD_CFG2_01_POS (1)

/* PAD_CFG2 02 */
#define MXC_F_GPIO_PAD_CFG2_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_PAD_CFG2_02_POS (2)

/* PAD_CFG2 03 */
#define MXC_F_GPIO_PAD_CFG2_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_PAD_CFG2_03_POS (3)

/* PAD_CFG2 04 */
#define MXC_F_GPIO_PAD_CFG2_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_PAD_CFG2_04_POS (4)

/* PAD_CFG2 05 */
#define MXC_F_GPIO_PAD_CFG2_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_PAD_CFG2_05_POS (5)

/* PAD_CFG2 06 */
#define MXC_F_GPIO_PAD_CFG2_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_PAD_CFG2_06_POS (6)

/* PAD_CFG2 07 */
#define MXC_F_GPIO_PAD_CFG2_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_PAD_CFG2_07_POS (7)

/* PAD_CFG2 08 */
#define MXC_F_GPIO_PAD_CFG2_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_PAD_CFG2_08_POS (8)

/* PAD_CFG2 09 */
#define MXC_F_GPIO_PAD_CFG2_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_PAD_CFG2_09_POS (9)

/* PAD_CFG2 10 */
#define MXC_F_GPIO_PAD_CFG2_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_PAD_CFG2_10_POS (10)

/* PAD_CFG2 11 */
#define MXC_F_GPIO_PAD_CFG2_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_PAD_CFG2_11_POS (11)

/* PAD_CFG2 12 */
#define MXC_F_GPIO_PAD_CFG2_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_PAD_CFG2_12_POS (12)

/* PAD_CFG2 13 */
#define MXC_F_GPIO_PAD_CFG2_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_PAD_CFG2_13_POS (13)

/* PAD_CFG2 14 */
#define MXC_F_GPIO_PAD_CFG2_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_PAD_CFG2_14_POS (14)

/* PAD_CFG2 15 */
#define MXC_F_GPIO_PAD_CFG2_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_PAD_CFG2_15_POS (15)

/* PAD_CFG2 16 */
#define MXC_F_GPIO_PAD_CFG2_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_PAD_CFG2_16_POS (16)

/* PAD_CFG2 17 */
#define MXC_F_GPIO_PAD_CFG2_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_PAD_CFG2_17_POS (17)

/* PAD_CFG2 18 */
#define MXC_F_GPIO_PAD_CFG2_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_PAD_CFG2_18_POS (18)

/* PAD_CFG2 19 */
#define MXC_F_GPIO_PAD_CFG2_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_PAD_CFG2_19_POS (19)

/* PAD_CFG2 20 */
#define MXC_F_GPIO_PAD_CFG2_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_PAD_CFG2_20_POS (20)

/* PAD_CFG2 21 */
#define MXC_F_GPIO_PAD_CFG2_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_PAD_CFG2_21_POS (21)

/* PAD_CFG2 22 */
#define MXC_F_GPIO_PAD_CFG2_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_PAD_CFG2_22_POS (22)

/* PAD_CFG2 23 */
#define MXC_F_GPIO_PAD_CFG2_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_PAD_CFG2_23_POS (23)

/* PAD_CFG2 24 */
#define MXC_F_GPIO_PAD_CFG2_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_PAD_CFG2_24_POS (24)

/* PAD_CFG2 25 */
#define MXC_F_GPIO_PAD_CFG2_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_PAD_CFG2_25_POS (25)

/* PAD_CFG2 26 */
#define MXC_F_GPIO_PAD_CFG2_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_PAD_CFG2_26_POS (26)

/* PAD_CFG2 27 */
#define MXC_F_GPIO_PAD_CFG2_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_PAD_CFG2_27_POS (27)

/* PAD_CFG2 28 */
#define MXC_F_GPIO_PAD_CFG2_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_PAD_CFG2_28_POS (28)

/* PAD_CFG2 29 */
#define MXC_F_GPIO_PAD_CFG2_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_PAD_CFG2_29_POS (29)

/* PAD_CFG2 30 */
#define MXC_F_GPIO_PAD_CFG2_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_PAD_CFG2_30_POS (30)

/* PAD_CFG2 31 */
#define MXC_F_GPIO_PAD_CFG2_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_PAD_CFG2_31_POS (31)

/* EN1 00 */
#define MXC_F_GPIO_EN1_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_EN1_00_POS (0)

/* EN1 01 */
#define MXC_F_GPIO_EN1_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_EN1_01_POS (1)

/* EN1 02 */
#define MXC_F_GPIO_EN1_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_EN1_02_POS (2)

/* EN1 03 */
#define MXC_F_GPIO_EN1_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_EN1_03_POS (3)

/* EN1 04 */
#define MXC_F_GPIO_EN1_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_EN1_04_POS (4)

/* EN1 05 */
#define MXC_F_GPIO_EN1_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_EN1_05_POS (5)

/* EN1 06 */
#define MXC_F_GPIO_EN1_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_EN1_06_POS (6)

/* EN1 07 */
#define MXC_F_GPIO_EN1_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_EN1_07_POS (7)

/* EN1 08 */
#define MXC_F_GPIO_EN1_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_EN1_08_POS (8)

/* EN1 09 */
#define MXC_F_GPIO_EN1_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_EN1_09_POS (9)

/* EN1 10 */
#define MXC_F_GPIO_EN1_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_EN1_10_POS (10)

/* EN1 11 */
#define MXC_F_GPIO_EN1_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_EN1_11_POS (11)

/* EN1 12 */
#define MXC_F_GPIO_EN1_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_EN1_12_POS (12)

/* EN1 13 */
#define MXC_F_GPIO_EN1_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_EN1_13_POS (13)

/* EN1 14 */
#define MXC_F_GPIO_EN1_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_EN1_14_POS (14)

/* EN1 15 */
#define MXC_F_GPIO_EN1_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_EN1_15_POS (15)

/* EN1 16 */
#define MXC_F_GPIO_EN1_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_EN1_16_POS (16)

/* EN1 17 */
#define MXC_F_GPIO_EN1_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_EN1_17_POS (17)

/* EN1 18 */
#define MXC_F_GPIO_EN1_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_EN1_18_POS (18)

/* EN1 19 */
#define MXC_F_GPIO_EN1_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_EN1_19_POS (19)

/* EN1 20 */
#define MXC_F_GPIO_EN1_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_EN1_20_POS (20)

/* EN1 21 */
#define MXC_F_GPIO_EN1_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_EN1_21_POS (21)

/* EN1 22 */
#define MXC_F_GPIO_EN1_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_EN1_22_POS (22)

/* EN1 23 */
#define MXC_F_GPIO_EN1_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_EN1_23_POS (23)

/* EN1 24 */
#define MXC_F_GPIO_EN1_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_EN1_24_POS (24)

/* EN1 25 */
#define MXC_F_GPIO_EN1_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_EN1_25_POS (25)

/* EN1 26 */
#define MXC_F_GPIO_EN1_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_EN1_26_POS (26)

/* EN1 27 */
#define MXC_F_GPIO_EN1_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_EN1_27_POS (27)

/* EN1 28 */
#define MXC_F_GPIO_EN1_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_EN1_28_POS (28)

/* EN1 29 */
#define MXC_F_GPIO_EN1_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_EN1_29_POS (29)

/* EN1 30 */
#define MXC_F_GPIO_EN1_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_EN1_30_POS (30)

/* EN1 31 */
#define MXC_F_GPIO_EN1_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_EN1_31_POS (31)

/* RSV 00 */
#define MXC_F_GPIO_RSV_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_RSV_00_POS (0)

/* RSV 01 */
#define MXC_F_GPIO_RSV_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_RSV_01_POS (1)

/* RSV 02 */
#define MXC_F_GPIO_RSV_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_RSV_02_POS (2)

/* RSV 03 */
#define MXC_F_GPIO_RSV_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_RSV_03_POS (3)

/* RSV 04 */
#define MXC_F_GPIO_RSV_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_RSV_04_POS (4)

/* RSV 05 */
#define MXC_F_GPIO_RSV_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_RSV_05_POS (5)

/* RSV 06 */
#define MXC_F_GPIO_RSV_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_RSV_06_POS (6)

/* RSV 07 */
#define MXC_F_GPIO_RSV_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_RSV_07_POS (7)

/* RSV 08 */
#define MXC_F_GPIO_RSV_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_RSV_08_POS (8)

/* RSV 09 */
#define MXC_F_GPIO_RSV_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_RSV_09_POS (9)

/* RSV 10 */
#define MXC_F_GPIO_RSV_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_RSV_10_POS (10)

/* RSV 11 */
#define MXC_F_GPIO_RSV_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_RSV_11_POS (11)

/* RSV 12 */
#define MXC_F_GPIO_RSV_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_RSV_12_POS (12)

/* RSV 13 */
#define MXC_F_GPIO_RSV_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_RSV_13_POS (13)

/* RSV 14 */
#define MXC_F_GPIO_RSV_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_RSV_14_POS (14)

/* RSV 15 */
#define MXC_F_GPIO_RSV_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_RSV_15_POS (15)

/* RSV 16 */
#define MXC_F_GPIO_RSV_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_RSV_16_POS (16)

/* RSV 17 */
#define MXC_F_GPIO_RSV_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_RSV_17_POS (17)

/* RSV 18 */
#define MXC_F_GPIO_RSV_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_RSV_18_POS (18)

/* RSV 19 */
#define MXC_F_GPIO_RSV_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_RSV_19_POS (19)

/* RSV 20 */
#define MXC_F_GPIO_RSV_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_RSV_20_POS (20)

/* RSV 21 */
#define MXC_F_GPIO_RSV_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_RSV_21_POS (21)

/* RSV 22 */
#define MXC_F_GPIO_RSV_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_RSV_22_POS (22)

/* RSV 23 */
#define MXC_F_GPIO_RSV_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_RSV_23_POS (23)

/* RSV 24 */
#define MXC_F_GPIO_RSV_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_RSV_24_POS (24)

/* RSV 25 */
#define MXC_F_GPIO_RSV_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_RSV_25_POS (25)

/* RSV 26 */
#define MXC_F_GPIO_RSV_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_RSV_26_POS (26)

/* RSV 27 */
#define MXC_F_GPIO_RSV_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_RSV_27_POS (27)

/* RSV 28 */
#define MXC_F_GPIO_RSV_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_RSV_28_POS (28)

/* RSV 29 */
#define MXC_F_GPIO_RSV_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_RSV_29_POS (29)

/* RSV 30 */
#define MXC_F_GPIO_RSV_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_RSV_30_POS (30)

/* RSV 31 */
#define MXC_F_GPIO_RSV_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_RSV_31_POS (31)

/* DS 00 */
#define MXC_F_GPIO_DS_00 ((uint32_t)0x00000001UL)
#define MXC_F_GPIO_DS_00_POS (0)

/* DS 01 */
#define MXC_F_GPIO_DS_01 ((uint32_t)0x00000002UL)
#define MXC_F_GPIO_DS_01_POS (1)

/* DS 02 */
#define MXC_F_GPIO_DS_02 ((uint32_t)0x00000004UL)
#define MXC_F_GPIO_DS_02_POS (2)

/* DS 03 */
#define MXC_F_GPIO_DS_03 ((uint32_t)0x00000008UL)
#define MXC_F_GPIO_DS_03_POS (3)

/* DS 04 */
#define MXC_F_GPIO_DS_04 ((uint32_t)0x00000010UL)
#define MXC_F_GPIO_DS_04_POS (4)

/* DS 05 */
#define MXC_F_GPIO_DS_05 ((uint32_t)0x00000020UL)
#define MXC_F_GPIO_DS_05_POS (5)

/* DS 06 */
#define MXC_F_GPIO_DS_06 ((uint32_t)0x00000040UL)
#define MXC_F_GPIO_DS_06_POS (6)

/* DS 07 */
#define MXC_F_GPIO_DS_07 ((uint32_t)0x00000080UL)
#define MXC_F_GPIO_DS_07_POS (7)

/* DS 08 */
#define MXC_F_GPIO_DS_08 ((uint32_t)0x00000100UL)
#define MXC_F_GPIO_DS_08_POS (8)

/* DS 09 */
#define MXC_F_GPIO_DS_09 ((uint32_t)0x00000200UL)
#define MXC_F_GPIO_DS_09_POS (9)

/* DS 10 */
#define MXC_F_GPIO_DS_10 ((uint32_t)0x00000400UL)
#define MXC_F_GPIO_DS_10_POS (10)

/* DS 11 */
#define MXC_F_GPIO_DS_11 ((uint32_t)0x00000800UL)
#define MXC_F_GPIO_DS_11_POS (11)

/* DS 12 */
#define MXC_F_GPIO_DS_12 ((uint32_t)0x00001000UL)
#define MXC_F_GPIO_DS_12_POS (12)

/* DS 13 */
#define MXC_F_GPIO_DS_13 ((uint32_t)0x00002000UL)
#define MXC_F_GPIO_DS_13_POS (13)

/* DS 14 */
#define MXC_F_GPIO_DS_14 ((uint32_t)0x00004000UL)
#define MXC_F_GPIO_DS_14_POS (14)

/* DS 15 */
#define MXC_F_GPIO_DS_15 ((uint32_t)0x00008000UL)
#define MXC_F_GPIO_DS_15_POS (15)

/* DS 16 */
#define MXC_F_GPIO_DS_16 ((uint32_t)0x00010000UL)
#define MXC_F_GPIO_DS_16_POS (16)

/* DS 17 */
#define MXC_F_GPIO_DS_17 ((uint32_t)0x00020000UL)
#define MXC_F_GPIO_DS_17_POS (17)

/* DS 18 */
#define MXC_F_GPIO_DS_18 ((uint32_t)0x00040000UL)
#define MXC_F_GPIO_DS_18_POS (18)

/* DS 19 */
#define MXC_F_GPIO_DS_19 ((uint32_t)0x00080000UL)
#define MXC_F_GPIO_DS_19_POS (19)

/* DS 20 */
#define MXC_F_GPIO_DS_20 ((uint32_t)0x00100000UL)
#define MXC_F_GPIO_DS_20_POS (20)

/* DS 21 */
#define MXC_F_GPIO_DS_21 ((uint32_t)0x00200000UL)
#define MXC_F_GPIO_DS_21_POS (21)

/* DS 22 */
#define MXC_F_GPIO_DS_22 ((uint32_t)0x00400000UL)
#define MXC_F_GPIO_DS_22_POS (22)

/* DS 23 */
#define MXC_F_GPIO_DS_23 ((uint32_t)0x00800000UL)
#define MXC_F_GPIO_DS_23_POS (23)

/* DS 24 */
#define MXC_F_GPIO_DS_24 ((uint32_t)0x01000000UL)
#define MXC_F_GPIO_DS_24_POS (24)

/* DS 25 */
#define MXC_F_GPIO_DS_25 ((uint32_t)0x02000000UL)
#define MXC_F_GPIO_DS_25_POS (25)

/* DS 26 */
#define MXC_F_GPIO_DS_26 ((uint32_t)0x04000000UL)
#define MXC_F_GPIO_DS_26_POS (26)

/* DS 27 */
#define MXC_F_GPIO_DS_27 ((uint32_t)0x08000000UL)
#define MXC_F_GPIO_DS_27_POS (27)

/* DS 28 */
#define MXC_F_GPIO_DS_28 ((uint32_t)0x10000000UL)
#define MXC_F_GPIO_DS_28_POS (28)

/* DS 29 */
#define MXC_F_GPIO_DS_29 ((uint32_t)0x20000000UL)
#define MXC_F_GPIO_DS_29_POS (29)

/* DS 30 */
#define MXC_F_GPIO_DS_30 ((uint32_t)0x40000000UL)
#define MXC_F_GPIO_DS_30_POS (30)

/* DS 31 */
#define MXC_F_GPIO_DS_31 ((uint32_t)0x80000000UL)
#define MXC_F_GPIO_DS_31_POS (31)

#ifdef __cplusplus
}
#endif

#endif /* _MXC_GPIO_REGS_H_ */
