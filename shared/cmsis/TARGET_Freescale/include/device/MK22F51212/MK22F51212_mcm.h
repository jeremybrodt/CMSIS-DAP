/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_MCM_REGISTERS_H__
#define __HW_MCM_REGISTERS_H__

#include "regs.h"

/*
 * MK22F51212 MCM
 *
 * Core Platform Miscellaneous Control Module
 *
 * Registers defined in this header file:
 * - HW_MCM_PLASC - Crossbar Switch (AXBS) Slave Configuration
 * - HW_MCM_PLAMC - Crossbar Switch (AXBS) Master Configuration
 * - HW_MCM_PLACR - Crossbar Switch (AXBS) Control Register
 * - HW_MCM_ISR - Interrupt Status and Control Register
 * - HW_MCM_CPO - Compute Operation Control Register
 *
 * - hw_mcm_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_MCM_BASE
#define HW_MCM_INSTANCE_COUNT (1U) //!< Number of instances of the MCM module.
#define REGS_MCM_BASE (0xE0080000U) //!< Base address for MCM.
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_MCM_PLASC - Crossbar Switch (AXBS) Slave Configuration
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MCM_PLASC - Crossbar Switch (AXBS) Slave Configuration (RO)
 *
 * Reset value: 0x001FU
 *
 * PLASC is a 16-bit read-only register identifying the presence/absence of bus
 * slave connections to the device's crossbar switch.
 */
typedef union _hw_mcm_plasc
{
    uint16_t U;
    struct _hw_mcm_plasc_bitfields
    {
        uint16_t ASC : 8;              //!< [7:0] Each bit in the ASC field indicates
                                       //! whether there is a corresponding connection to the crossbar switch's slave
                                       //! input port.
        uint16_t RESERVED0 : 8;        //!< [15:8]
    } B;
} hw_mcm_plasc_t;
#endif

/*!
 * @name Constants and macros for entire MCM_PLASC register
 */
//@{
#define HW_MCM_PLASC_ADDR        (REGS_MCM_BASE + 0x8U)

#ifndef __LANGUAGE_ASM__
#define HW_MCM_PLASC             (*(__I hw_mcm_plasc_t *) HW_MCM_PLASC_ADDR)
#define HW_MCM_PLASC_RD()        (HW_MCM_PLASC.U)
#endif
//@}

/*
 * Constants & macros for individual MCM_PLASC bitfields
 */

/*!
 * @name Register MCM_PLASC, field ASC[7:0] (RO)
 *
 * Values:
 * - 0 - A bus slave connection to AXBS input port n is absent
 * - 1 - A bus slave connection to AXBS input port n is present
 */
//@{
#define BP_MCM_PLASC_ASC     (0U)          //!< Bit position for MCM_PLASC_ASC.
#define BM_MCM_PLASC_ASC     (0x00FFU)     //!< Bit mask for MCM_PLASC_ASC.
#define BS_MCM_PLASC_ASC     (8U)          //!< Bit field size in bits for MCM_PLASC_ASC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_PLASC_ASC field.
#define BR_MCM_PLASC_ASC     (HW_MCM_PLASC.B.ASC)
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_MCM_PLAMC - Crossbar Switch (AXBS) Master Configuration
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MCM_PLAMC - Crossbar Switch (AXBS) Master Configuration (RO)
 *
 * Reset value: 0x0017U
 *
 * PLAMC is a 16-bit read-only register identifying the presence/absence of bus
 * master connections to the device's crossbar switch.
 */
typedef union _hw_mcm_plamc
{
    uint16_t U;
    struct _hw_mcm_plamc_bitfields
    {
        uint16_t AMC : 8;              //!< [7:0] Each bit in the AMC field indicates
                                       //! whether there is a corresponding connection to the AXBS master input port.
        uint16_t RESERVED0 : 8;        //!< [15:8]
    } B;
} hw_mcm_plamc_t;
#endif

/*!
 * @name Constants and macros for entire MCM_PLAMC register
 */
//@{
#define HW_MCM_PLAMC_ADDR        (REGS_MCM_BASE + 0xAU)

#ifndef __LANGUAGE_ASM__
#define HW_MCM_PLAMC             (*(__I hw_mcm_plamc_t *) HW_MCM_PLAMC_ADDR)
#define HW_MCM_PLAMC_RD()        (HW_MCM_PLAMC.U)
#endif
//@}

/*
 * Constants & macros for individual MCM_PLAMC bitfields
 */

/*!
 * @name Register MCM_PLAMC, field AMC[7:0] (RO)
 *
 * Values:
 * - 0 - A bus master connection to AXBS input port n is absent
 * - 1 - A bus master connection to AXBS input port n is present
 */
//@{
#define BP_MCM_PLAMC_AMC     (0U)          //!< Bit position for MCM_PLAMC_AMC.
#define BM_MCM_PLAMC_AMC     (0x00FFU)     //!< Bit mask for MCM_PLAMC_AMC.
#define BS_MCM_PLAMC_AMC     (8U)          //!< Bit field size in bits for MCM_PLAMC_AMC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_PLAMC_AMC field.
#define BR_MCM_PLAMC_AMC     (HW_MCM_PLAMC.B.AMC)
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_MCM_PLACR - Crossbar Switch (AXBS) Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MCM_PLACR - Crossbar Switch (AXBS) Control Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * The PLACR register selects the arbitration policy for the crossbar masters.
 */
typedef union _hw_mcm_placr
{
    uint32_t U;
    struct _hw_mcm_placr_bitfields
    {
        uint32_t RESERVED0 : 9;        //!< [8:0]
        uint32_t ARB : 1;              //!< [9] Arbitration select
        uint32_t RESERVED1 : 22;       //!< [31:10]
    } B;
} hw_mcm_placr_t;
#endif

/*!
 * @name Constants and macros for entire MCM_PLACR register
 */
//@{
#define HW_MCM_PLACR_ADDR        (REGS_MCM_BASE + 0xCU)

#ifndef __LANGUAGE_ASM__
#define HW_MCM_PLACR             (*(__IO hw_mcm_placr_t *) HW_MCM_PLACR_ADDR)
#define HW_MCM_PLACR_RD()        (HW_MCM_PLACR.U)
#define HW_MCM_PLACR_WR(v)       (HW_MCM_PLACR.U = (v))
#define HW_MCM_PLACR_SET(v)      (HW_MCM_PLACR_WR(HW_MCM_PLACR_RD() |  (v)))
#define HW_MCM_PLACR_CLR(v)      (HW_MCM_PLACR_WR(HW_MCM_PLACR_RD() & ~(v)))
#define HW_MCM_PLACR_TOG(v)      (HW_MCM_PLACR_WR(HW_MCM_PLACR_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual MCM_PLACR bitfields
 */

/*!
 * @name Register MCM_PLACR, field ARB[9] (RW)
 *
 * Values:
 * - 0 - Fixed-priority arbitration for the crossbar masters
 * - 1 - Round-robin arbitration for the crossbar masters
 */
//@{
#define BP_MCM_PLACR_ARB     (9U)          //!< Bit position for MCM_PLACR_ARB.
#define BM_MCM_PLACR_ARB     (0x00000200U) //!< Bit mask for MCM_PLACR_ARB.
#define BS_MCM_PLACR_ARB     (1U)          //!< Bit field size in bits for MCM_PLACR_ARB.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_PLACR_ARB field.
#define BR_MCM_PLACR_ARB     (BITBAND_ACCESS32(HW_MCM_PLACR_ADDR, BP_MCM_PLACR_ARB))
#endif

//! @brief Format value for bitfield MCM_PLACR_ARB.
#define BF_MCM_PLACR_ARB(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_PLACR_ARB), uint32_t) & BM_MCM_PLACR_ARB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARB field to a new value.
#define BW_MCM_PLACR_ARB(v)  (BITBAND_ACCESS32(HW_MCM_PLACR_ADDR, BP_MCM_PLACR_ARB) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_MCM_ISR - Interrupt Status and Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MCM_ISR - Interrupt Status and Control Register (RW)
 *
 * Reset value: 0x00020000U
 *
 * The MCM_ISCR register includes the enable and status bits associated with the
 * core's floating-point exceptions. The individual event indicators are first
 * qualified with their exception enables and then logically summed to form an
 * interrupt request sent to the core's NVIC. Bits 15-8 are read-only indicator
 * flags based on the processor's FPSCR register. Attempted writes to these bits are
 * ignored. Once set, the flags remain asserted until software clears the
 * corresponding FPSCR bit.
 */
typedef union _hw_mcm_isr
{
    uint32_t U;
    struct _hw_mcm_isr_bitfields
    {
        uint32_t RESERVED0 : 8;        //!< [7:0]
        uint32_t FIOC : 1;             //!< [8] FPU invalid operation interrupt status
        uint32_t FDZC : 1;             //!< [9] FPU divide-by-zero interrupt status
        uint32_t FOFC : 1;             //!< [10] FPU overflow interrupt status
        uint32_t FUFC : 1;             //!< [11] FPU underflow interrupt status
        uint32_t FIXC : 1;             //!< [12] FPU inexact interrupt status
        uint32_t RESERVED1 : 2;        //!< [14:13]
        uint32_t FIDC : 1;             //!< [15] FPU input denormal interrupt status
        uint32_t RESERVED2 : 8;        //!< [23:16]
        uint32_t FIOCE : 1;            //!< [24] FPU invalid operation interrupt enable
        uint32_t FDZCE : 1;            //!< [25] FPU divide-by-zero interrupt enable
        uint32_t FOFCE : 1;            //!< [26] FPU overflow interrupt enable
        uint32_t FUFCE : 1;            //!< [27] FPU underflow interrupt enable
        uint32_t FIXCE : 1;            //!< [28] FPU inexact interrupt enable
        uint32_t RESERVED3 : 2;        //!< [30:29]
        uint32_t FIDCE : 1;            //!< [31] FPU input denormal interrupt enable
    } B;
} hw_mcm_isr_t;
#endif

/*!
 * @name Constants and macros for entire MCM_ISR register
 */
//@{
#define HW_MCM_ISR_ADDR          (REGS_MCM_BASE + 0x10U)

#ifndef __LANGUAGE_ASM__
#define HW_MCM_ISR               (*(__IO hw_mcm_isr_t *) HW_MCM_ISR_ADDR)
#define HW_MCM_ISR_RD()          (HW_MCM_ISR.U)
#define HW_MCM_ISR_WR(v)         (HW_MCM_ISR.U = (v))
#define HW_MCM_ISR_SET(v)        (HW_MCM_ISR_WR(HW_MCM_ISR_RD() |  (v)))
#define HW_MCM_ISR_CLR(v)        (HW_MCM_ISR_WR(HW_MCM_ISR_RD() & ~(v)))
#define HW_MCM_ISR_TOG(v)        (HW_MCM_ISR_WR(HW_MCM_ISR_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual MCM_ISR bitfields
 */

/*!
 * @name Register MCM_ISR, field FIOC[8] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[IOC] bit and signals an
 * illegal operation has been detected in the processor's FPU. Once set, this bit
 * remains set until software clears the FPSCR[IOC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
//@{
#define BP_MCM_ISR_FIOC      (8U)          //!< Bit position for MCM_ISR_FIOC.
#define BM_MCM_ISR_FIOC      (0x00000100U) //!< Bit mask for MCM_ISR_FIOC.
#define BS_MCM_ISR_FIOC      (1U)          //!< Bit field size in bits for MCM_ISR_FIOC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FIOC field.
#define BR_MCM_ISR_FIOC      (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIOC))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FDZC[9] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[DZC] bit and signals a
 * divide by zero has been detected in the processor's FPU. Once set, this bit remains
 * set until software clears the FPSCR[DZC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
//@{
#define BP_MCM_ISR_FDZC      (9U)          //!< Bit position for MCM_ISR_FDZC.
#define BM_MCM_ISR_FDZC      (0x00000200U) //!< Bit mask for MCM_ISR_FDZC.
#define BS_MCM_ISR_FDZC      (1U)          //!< Bit field size in bits for MCM_ISR_FDZC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FDZC field.
#define BR_MCM_ISR_FDZC      (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FDZC))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FOFC[10] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[OFC] bit and signals an
 * overflow has been detected in the processor's FPU. Once set, this bit remains set
 * until software clears the FPSCR[OFC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
//@{
#define BP_MCM_ISR_FOFC      (10U)         //!< Bit position for MCM_ISR_FOFC.
#define BM_MCM_ISR_FOFC      (0x00000400U) //!< Bit mask for MCM_ISR_FOFC.
#define BS_MCM_ISR_FOFC      (1U)          //!< Bit field size in bits for MCM_ISR_FOFC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FOFC field.
#define BR_MCM_ISR_FOFC      (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FOFC))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FUFC[11] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[UFC] bit and signals an
 * underflow has been detected in the processor's FPU. Once set, this bit remains set
 * until software clears the FPSCR[UFC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
//@{
#define BP_MCM_ISR_FUFC      (11U)         //!< Bit position for MCM_ISR_FUFC.
#define BM_MCM_ISR_FUFC      (0x00000800U) //!< Bit mask for MCM_ISR_FUFC.
#define BS_MCM_ISR_FUFC      (1U)          //!< Bit field size in bits for MCM_ISR_FUFC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FUFC field.
#define BR_MCM_ISR_FUFC      (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FUFC))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FIXC[12] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[IXC] bit and signals an
 * inexact number has been detected in the processor's FPU. Once set, this bit
 * remains set until software clears the FPSCR[IXC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
//@{
#define BP_MCM_ISR_FIXC      (12U)         //!< Bit position for MCM_ISR_FIXC.
#define BM_MCM_ISR_FIXC      (0x00001000U) //!< Bit mask for MCM_ISR_FIXC.
#define BS_MCM_ISR_FIXC      (1U)          //!< Bit field size in bits for MCM_ISR_FIXC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FIXC field.
#define BR_MCM_ISR_FIXC      (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIXC))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FIDC[15] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[IDC] bit and signals input
 * denormalized number has been detected in the processor's FPU. Once set, this
 * bit remains set until software clears the FPSCR[IDC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
//@{
#define BP_MCM_ISR_FIDC      (15U)         //!< Bit position for MCM_ISR_FIDC.
#define BM_MCM_ISR_FIDC      (0x00008000U) //!< Bit mask for MCM_ISR_FIDC.
#define BS_MCM_ISR_FIDC      (1U)          //!< Bit field size in bits for MCM_ISR_FIDC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FIDC field.
#define BR_MCM_ISR_FIDC      (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIDC))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FIOCE[24] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
//@{
#define BP_MCM_ISR_FIOCE     (24U)         //!< Bit position for MCM_ISR_FIOCE.
#define BM_MCM_ISR_FIOCE     (0x01000000U) //!< Bit mask for MCM_ISR_FIOCE.
#define BS_MCM_ISR_FIOCE     (1U)          //!< Bit field size in bits for MCM_ISR_FIOCE.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FIOCE field.
#define BR_MCM_ISR_FIOCE     (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIOCE))
#endif

//! @brief Format value for bitfield MCM_ISR_FIOCE.
#define BF_MCM_ISR_FIOCE(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_ISR_FIOCE), uint32_t) & BM_MCM_ISR_FIOCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIOCE field to a new value.
#define BW_MCM_ISR_FIOCE(v)  (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIOCE) = (v))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FDZCE[25] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
//@{
#define BP_MCM_ISR_FDZCE     (25U)         //!< Bit position for MCM_ISR_FDZCE.
#define BM_MCM_ISR_FDZCE     (0x02000000U) //!< Bit mask for MCM_ISR_FDZCE.
#define BS_MCM_ISR_FDZCE     (1U)          //!< Bit field size in bits for MCM_ISR_FDZCE.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FDZCE field.
#define BR_MCM_ISR_FDZCE     (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FDZCE))
#endif

//! @brief Format value for bitfield MCM_ISR_FDZCE.
#define BF_MCM_ISR_FDZCE(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_ISR_FDZCE), uint32_t) & BM_MCM_ISR_FDZCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FDZCE field to a new value.
#define BW_MCM_ISR_FDZCE(v)  (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FDZCE) = (v))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FOFCE[26] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
//@{
#define BP_MCM_ISR_FOFCE     (26U)         //!< Bit position for MCM_ISR_FOFCE.
#define BM_MCM_ISR_FOFCE     (0x04000000U) //!< Bit mask for MCM_ISR_FOFCE.
#define BS_MCM_ISR_FOFCE     (1U)          //!< Bit field size in bits for MCM_ISR_FOFCE.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FOFCE field.
#define BR_MCM_ISR_FOFCE     (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FOFCE))
#endif

//! @brief Format value for bitfield MCM_ISR_FOFCE.
#define BF_MCM_ISR_FOFCE(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_ISR_FOFCE), uint32_t) & BM_MCM_ISR_FOFCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FOFCE field to a new value.
#define BW_MCM_ISR_FOFCE(v)  (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FOFCE) = (v))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FUFCE[27] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
//@{
#define BP_MCM_ISR_FUFCE     (27U)         //!< Bit position for MCM_ISR_FUFCE.
#define BM_MCM_ISR_FUFCE     (0x08000000U) //!< Bit mask for MCM_ISR_FUFCE.
#define BS_MCM_ISR_FUFCE     (1U)          //!< Bit field size in bits for MCM_ISR_FUFCE.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FUFCE field.
#define BR_MCM_ISR_FUFCE     (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FUFCE))
#endif

//! @brief Format value for bitfield MCM_ISR_FUFCE.
#define BF_MCM_ISR_FUFCE(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_ISR_FUFCE), uint32_t) & BM_MCM_ISR_FUFCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FUFCE field to a new value.
#define BW_MCM_ISR_FUFCE(v)  (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FUFCE) = (v))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FIXCE[28] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
//@{
#define BP_MCM_ISR_FIXCE     (28U)         //!< Bit position for MCM_ISR_FIXCE.
#define BM_MCM_ISR_FIXCE     (0x10000000U) //!< Bit mask for MCM_ISR_FIXCE.
#define BS_MCM_ISR_FIXCE     (1U)          //!< Bit field size in bits for MCM_ISR_FIXCE.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FIXCE field.
#define BR_MCM_ISR_FIXCE     (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIXCE))
#endif

//! @brief Format value for bitfield MCM_ISR_FIXCE.
#define BF_MCM_ISR_FIXCE(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_ISR_FIXCE), uint32_t) & BM_MCM_ISR_FIXCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIXCE field to a new value.
#define BW_MCM_ISR_FIXCE(v)  (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIXCE) = (v))
#endif
//@}

/*!
 * @name Register MCM_ISR, field FIDCE[31] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
//@{
#define BP_MCM_ISR_FIDCE     (31U)         //!< Bit position for MCM_ISR_FIDCE.
#define BM_MCM_ISR_FIDCE     (0x80000000U) //!< Bit mask for MCM_ISR_FIDCE.
#define BS_MCM_ISR_FIDCE     (1U)          //!< Bit field size in bits for MCM_ISR_FIDCE.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_ISR_FIDCE field.
#define BR_MCM_ISR_FIDCE     (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIDCE))
#endif

//! @brief Format value for bitfield MCM_ISR_FIDCE.
#define BF_MCM_ISR_FIDCE(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_ISR_FIDCE), uint32_t) & BM_MCM_ISR_FIDCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIDCE field to a new value.
#define BW_MCM_ISR_FIDCE(v)  (BITBAND_ACCESS32(HW_MCM_ISR_ADDR, BP_MCM_ISR_FIDCE) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_MCM_CPO - Compute Operation Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MCM_CPO - Compute Operation Control Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * This register controls the Compute Operation.
 */
typedef union _hw_mcm_cpo
{
    uint32_t U;
    struct _hw_mcm_cpo_bitfields
    {
        uint32_t CPOREQ : 1;           //!< [0] Compute Operation request
        uint32_t CPOACK : 1;           //!< [1] Compute Operation acknowledge
        uint32_t CPOWOI : 1;           //!< [2] Compute Operation wakeup on interrupt
        uint32_t RESERVED0 : 29;       //!< [31:3]
    } B;
} hw_mcm_cpo_t;
#endif

/*!
 * @name Constants and macros for entire MCM_CPO register
 */
//@{
#define HW_MCM_CPO_ADDR          (REGS_MCM_BASE + 0x40U)

#ifndef __LANGUAGE_ASM__
#define HW_MCM_CPO               (*(__IO hw_mcm_cpo_t *) HW_MCM_CPO_ADDR)
#define HW_MCM_CPO_RD()          (HW_MCM_CPO.U)
#define HW_MCM_CPO_WR(v)         (HW_MCM_CPO.U = (v))
#define HW_MCM_CPO_SET(v)        (HW_MCM_CPO_WR(HW_MCM_CPO_RD() |  (v)))
#define HW_MCM_CPO_CLR(v)        (HW_MCM_CPO_WR(HW_MCM_CPO_RD() & ~(v)))
#define HW_MCM_CPO_TOG(v)        (HW_MCM_CPO_WR(HW_MCM_CPO_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual MCM_CPO bitfields
 */

/*!
 * @name Register MCM_CPO, field CPOREQ[0] (RW)
 *
 * This bit is auto-cleared by vector fetching if CPOWOI = 1.
 *
 * Values:
 * - 0 - Request is cleared.
 * - 1 - Request Compute Operation.
 */
//@{
#define BP_MCM_CPO_CPOREQ    (0U)          //!< Bit position for MCM_CPO_CPOREQ.
#define BM_MCM_CPO_CPOREQ    (0x00000001U) //!< Bit mask for MCM_CPO_CPOREQ.
#define BS_MCM_CPO_CPOREQ    (1U)          //!< Bit field size in bits for MCM_CPO_CPOREQ.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_CPO_CPOREQ field.
#define BR_MCM_CPO_CPOREQ    (BITBAND_ACCESS32(HW_MCM_CPO_ADDR, BP_MCM_CPO_CPOREQ))
#endif

//! @brief Format value for bitfield MCM_CPO_CPOREQ.
#define BF_MCM_CPO_CPOREQ(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_CPO_CPOREQ), uint32_t) & BM_MCM_CPO_CPOREQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CPOREQ field to a new value.
#define BW_MCM_CPO_CPOREQ(v) (BITBAND_ACCESS32(HW_MCM_CPO_ADDR, BP_MCM_CPO_CPOREQ) = (v))
#endif
//@}

/*!
 * @name Register MCM_CPO, field CPOACK[1] (RO)
 *
 * Values:
 * - 0 - Compute operation entry has not completed or compute operation exit has
 *     completed.
 * - 1 - Compute operation entry has completed or compute operation exit has not
 *     completed.
 */
//@{
#define BP_MCM_CPO_CPOACK    (1U)          //!< Bit position for MCM_CPO_CPOACK.
#define BM_MCM_CPO_CPOACK    (0x00000002U) //!< Bit mask for MCM_CPO_CPOACK.
#define BS_MCM_CPO_CPOACK    (1U)          //!< Bit field size in bits for MCM_CPO_CPOACK.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_CPO_CPOACK field.
#define BR_MCM_CPO_CPOACK    (BITBAND_ACCESS32(HW_MCM_CPO_ADDR, BP_MCM_CPO_CPOACK))
#endif
//@}

/*!
 * @name Register MCM_CPO, field CPOWOI[2] (RW)
 *
 * Values:
 * - 0 - No effect.
 * - 1 - When set, the CPOREQ is cleared on any interrupt or exception vector
 *     fetch.
 */
//@{
#define BP_MCM_CPO_CPOWOI    (2U)          //!< Bit position for MCM_CPO_CPOWOI.
#define BM_MCM_CPO_CPOWOI    (0x00000004U) //!< Bit mask for MCM_CPO_CPOWOI.
#define BS_MCM_CPO_CPOWOI    (1U)          //!< Bit field size in bits for MCM_CPO_CPOWOI.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the MCM_CPO_CPOWOI field.
#define BR_MCM_CPO_CPOWOI    (BITBAND_ACCESS32(HW_MCM_CPO_ADDR, BP_MCM_CPO_CPOWOI))
#endif

//! @brief Format value for bitfield MCM_CPO_CPOWOI.
#define BF_MCM_CPO_CPOWOI(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_MCM_CPO_CPOWOI), uint32_t) & BM_MCM_CPO_CPOWOI)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CPOWOI field to a new value.
#define BW_MCM_CPO_CPOWOI(v) (BITBAND_ACCESS32(HW_MCM_CPO_ADDR, BP_MCM_CPO_CPOWOI) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_mcm_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All MCM module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_mcm
{
    uint8_t _reserved0[8];
    __I hw_mcm_plasc_t PLASC;              //!< [0x8] Crossbar Switch (AXBS) Slave Configuration
    __I hw_mcm_plamc_t PLAMC;              //!< [0xA] Crossbar Switch (AXBS) Master Configuration
    __IO hw_mcm_placr_t PLACR;             //!< [0xC] Crossbar Switch (AXBS) Control Register
    __IO hw_mcm_isr_t ISR;                 //!< [0x10] Interrupt Status and Control Register
    uint8_t _reserved1[44];
    __IO hw_mcm_cpo_t CPO;                 //!< [0x40] Compute Operation Control Register
} hw_mcm_t;
#pragma pack()

//! @brief Macro to access all MCM registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_MCM</code>.
#define HW_MCM         (*(hw_mcm_t *) REGS_MCM_BASE)
#endif

#endif // __HW_MCM_REGISTERS_H__
// v22/130726/0.9
// EOF
