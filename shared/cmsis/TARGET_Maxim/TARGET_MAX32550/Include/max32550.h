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
* $Id: max32550.h 15080 2014-09-09 15:10:44Z kevin.gillespie $
*
********************************************************************************
*/

#ifndef _MAX32550_H_
#define _MAX32550_H_
#include <stdint.h>

/*
   If types are not defined elsewhere (CMSIS), define them here
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

/* -------------------------  Interrupt Number Definition  ------------------------ */

#define MXC_NUM_VECTORS  48

typedef enum IRQn
{
/* -------------------  Cortex-M3 Processor Exceptions Numbers  ------------------- */
  NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt          */
  HardFault_IRQn                = -13,      /*!<  3 HardFault Interrupt             */
  MemoryManagement_IRQn         = -12,      /*!<  4 Memory Management Interrupt     */
  BusFault_IRQn                 = -11,      /*!<  5 Bus Fault Interrupt             */
  UsageFault_IRQn               = -10,      /*!<  6 Usage Fault Interrupt           */
  SVCall_IRQn                   =  -5,      /*!< 11 SV Call Interrupt               */
  DebugMonitor_IRQn             =  -4,      /*!< 12 Debug Monitor Interrupt         */
  PendSV_IRQn                   =  -2,      /*!< 14 Pend SV Interrupt               */
  SysTick_IRQn                  =  -1,      /*!< 15 System Tick Interrupt           */

/* ----------------------  Target Specific Interrupt Numbers  --------------------- */
  PF_IRQn                       =   0,      /*!< Power Fail Interrupt */
  WDT_IRQn                      =   1,      /*!< Watchdog Timer Interrupt */
  USB_IRQn                      =   2,      /*!< USB Interrupt */
  RTC_IRQn                      =   3,      /*!< Real-Time Clock Interrupt */
  TRNG_IRQn                     =   4,      /*!< True Random Number Generator Interrupt */
  TMR0_IRQn                     =   5,      /*!< Timer 0 Interrupt */
  TMR1_IRQn                     =   6,      /*!< Timer 1 Interrupt */
  TMR2_IRQn                     =   7,      /*!< Timer 2 Interrupt */
  TMR3_IRQn                     =   8,      /*!< Timer 3 Interrupt */
  TMR4_IRQn                     =   9,      /*!< Timer 4 Interrupt */
  TMR5_IRQn                     =  10,      /*!< Timer 5 Interrupt */
  SC_IRQn                       =  11,      /*!< Smart Card Interrupt */
  LCD_IRQn                      =  12,      /*!< Mono LCD/TFT Interrupt */
  I2C_IRQn                      =  13,      /*!< I2C Interrupt */
  UART0_IRQn                    =  14,      /*!< UART 0 Interrupt */
  UART1_IRQn                    =  15,      /*!< UART 1 Interrupt */
  SPI0_IRQn                     =  16,      /*!< SPI 0 Interrupt */
  SPI1_IRQn                     =  17,      /*!< SPI 1 Interrupt */
  SPI2_IRQn                     =  18,      /*!< SPI 2 Interrupt */
  KBD_IRQn                      =  19,      /*!< Secure Keypad Interrupt */
  ADC_IRQn                      =  20,      /*!< ADC Interrupt */
  DAC_IRQn                      =  21,      /*!< DAC Interrupt */
  MSR_IRQn                      =  22,      /*!< MSR DSP Done Interrupt */
  FLC_IRQn                      =  23,      /*!< Flash Controller Interrupt */
  GPIO0_IRQn                    =  24,      /*!< GPIO 0 Interrupt */
  GPIO1_IRQn                    =  25,      /*!< GPIO 1 Interrupt */
  GPIO2_IRQn                    =  26,      /*!< GPIO 2 Interrupt */
  CRYPTO_IRQn                   =  27,      /*!< Crypto Engine Interrupt */
  DMA0_IRQn                     =  28,      /*!< DMA Channel 0 Interrupt */
  DMA1_IRQn                     =  29,      /*!< DMA Channel 1 Interrupt */
  DMA2_IRQn                     =  30,      /*!< DMA Channel 2 Interrupt */
  DMA3_IRQn                     =  31,      /*!< DMA Channel 3 Interrupt */
} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* --------  Configuration of the Cortex-M4 Processor and Core Peripherals  ------- */
#define __CM3_REV                 0x0201    /*!< Core revision r2p1                              */
#define __MPU_PRESENT             0         /*!< MPU present or not                              */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels         */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used    */

#include <core_cm3.h>                       /* Processor and core peripherals                    */
#include "system_max32550.h"                    /* System Header                                     */


/* ================================================================================ */
/* ==================       Device Specific Memory Section       ================== */
/* ================================================================================ */

#define MXC_FLASH_MEM_BASE    0x10000000UL
#define MXC_FLASH_PAGE_SIZE   0x1000        // 256 x 128b = 4KB
#define MXC_FLASH_MEM_SIZE    0x00100000UL
#define MXC_SYS_MEM_BASE      0x20000000UL

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/*
	Global Configuration Registers
*/
#define MXC_BASE_GCR ((uint32_t)0x40000000UL)
#define MXC_GCR ((mxc_gcr_regs_t*)MXC_BASE_GCR)
#define MXC_GCR_INSTANCES    (1)

/*
	System Initialization Registers
*/
#define MXC_BASE_SIR ((uint32_t)0x40000400UL)
#define MXC_SIR ((mxc_sir_regs_t*)MXC_BASE_SIR)
#define MXC_SIR_INSTANCES    (1)

/*
	Cryptography
*/
#define MXC_BASE_CRYPTO ((uint32_t)0x40001000UL)
#define MXC_CRYPTO ((mxc_crypto_regs_t*)MXC_BASE_CRYPTO)
#define MXC_CRYPTO_INSTANCES    (1)

/*
	Watch Dog Timer
*/
#define MXC_BASE_WDT ((uint32_t)0x40003000UL)
#define MXC_WDT ((mxc_wdt_regs_t*)MXC_BASE_WDT)
#define MXC_WDT_INSTANCES    (1)

/*
	Security Monitor
*/
#define MXC_BASE_SM ((uint32_t)0x40004000UL)
#define MXC_SM ((mxc_sm_regs_t*)MXC_BASE_SM)
#define MXC_SM_INSTANCES    (1)

/*
	Real Time Clock
*/
#define MXC_BASE_RTC ((uint32_t)0x40006000UL)
#define MXC_RTC ((mxc_rtc_regs_t*)MXC_BASE_RTC)
#define MXC_RTC_INSTANCES    (1)

/*
	GPIO Ports
*/
#define MXC_BASE_GPIO0 ((uint32_t)0x40008000UL)
#define MXC_GPIO0 ((mxc_gpio_regs_t*)MXC_BASE_GPIO0)
#define MXC_BASE_GPIO1 ((uint32_t)0x40009000UL)
#define MXC_GPIO1 ((mxc_gpio_regs_t*)MXC_BASE_GPIO1)
#define MXC_BASE_GPIO2 ((uint32_t)0x4000A000UL)
#define MXC_GPIO2 ((mxc_gpio_regs_t*)MXC_BASE_GPIO2)
#define MXC_GPIO_INSTANCES    (3)
#define MXC_GPIO_INSTANCE_TO_BASE(instance) (((uint32_t)(instance) << 12) + MXC_BASE_GPIO0)
#define MXC_GPIO_BASE_TO_INSTANCE(base)     (((uint32_t)(base) & 0x00003000) >> 12)

/*
	I2C
*/
#define MXC_BASE_I2C ((uint32_t)0x4000C000UL)
#define MXC_I2C ((mxc_i2c_regs_t *)(MXC_BASE_I2C))
#define MXC_I2C_INSTANCES   (1)
#define MXC_I2C_VALID(P)    ((void*)(P) == (void*)MXC_BASE_I2C)

/*
	Timers
*/
#define MXC_BASE_TMR0 ((uint32_t)0x40010000UL)
#define MXC_TMR0 ((mxc_tmr_regs_t *)(MXC_BASE_TMR0))
#define MXC_BASE_TMR1 ((uint32_t)0x40011000UL)
#define MXC_TMR1 ((mxc_tmr_regs_t *)(MXC_BASE_TMR1))
#define MXC_BASE_TMR2 ((uint32_t)0x40012000UL)
#define MXC_TMR2 ((mxc_tmr_regs_t *)(MXC_BASE_TMR2))
#define MXC_BASE_TMR3 ((uint32_t)0x40013000UL)
#define MXC_TMR3 ((mxc_tmr_regs_t *)(MXC_BASE_TMR3))
#define MXC_BASE_TMR4 ((uint32_t)0x40014000UL)
#define MXC_TMR4 ((mxc_tmr_regs_t *)(MXC_BASE_TMR4))
#define MXC_BASE_TMR5 ((uint32_t)0x40015000UL)
#define MXC_TMR5 ((mxc_tmr_regs_t *)(MXC_BASE_TMR5))
#define MXC_TMR_INSTANCES    (6)

#define MXC_TMR_VALID(P)       (((P) == MXC_TMR0) || \
                                ((P) == MXC_TMR1) || \
                                ((P) == MXC_TMR2) || \
                                ((P) == MXC_TMR3) || \
                                ((P) == MXC_TMR4) || \
                                ((P) == MXC_TMR5))

/*
	SPI
*/
#define MXC_BASE_SPI0 ((uint32_t)0x40018000UL)
#define MXC_SPI0 ((mxc_spi_regs_t *)(MXC_BASE_SPI0))
#define MXC_BASE_SPI1 ((uint32_t)0x40019000UL)
#define MXC_SPI1 ((mxc_spi_regs_t *)(MXC_BASE_SPI1))
#define MXC_BASE_SPI2 ((uint32_t)0x4001A000UL)
#define MXC_SPI2 ((mxc_spi_regs_t *)(MXC_BASE_SPI2))
#define MXC_SPI_INSTANCES    (3)
#define MXC_SPI_TX_FIFO_DEPTH   8
#define MXC_SPI_INSTANCE_TO_BASE(instance) (((uint32_t)(instance) << 12) + MXC_BASE_SPI0)
#define MXC_SPI_BASE_TO_INSTANCE(base)     (((uint32_t)(base) & 0x00003000) >> 12)

/*
	UARTs
*/
#define MXC_BASE_UART0 ((uint32_t)0x40020000UL)
#define MXC_UART0 ((mxc_uart_regs_t*)MXC_BASE_UART0)
#define MXC_BASE_UART1 ((uint32_t)0x40021000UL)
#define MXC_UART1 ((mxc_uart_regs_t*)MXC_BASE_UART1)
#define MXC_UART_INSTANCES    (2)
#define MXC_UART_INSTANCE_TO_BASE(instance) (((uint32_t)(instance) << 12) + MXC_BASE_UART0)
#define MXC_UART_BASE_TO_INSTANCE(base)     (((uint32_t)(base) & 0x00001000) >> 12)

/*
	DMA
*/
#define MXC_BASE_DMA ((uint32_t)0x40028000UL)
#define MXC_DMA ((mxc_dma_regs_t*)MXC_BASE_DMA)
#define MXC_DMA_INSTANCES    (1)

/*
	Flash Controller
*/
#define MXC_BASE_FLC ((uint32_t)0x40029000UL)
#define MXC_FLC ((mxc_flc_regs_t*)MXC_BASE_FLC)
#define MXC_FLC_INSTANCES    (1)

/*
	Cache Controller
*/
#define MXC_BASE_ICC ((uint32_t)0x4002A000UL)
#define MXC_ICC ((mxc_icc_regs_t*)MXC_BASE_ICC)
#define MXC_ICC_INSTANCES    (1)

/*
	Magnetic Stripe Reader
*/
#define MXC_BASE_MSR ((uint32_t)0x4002B000UL)
#define MXC_MSR ((mxc_msr_regs_t*)MXC_BASE_MSR)
#define MXC_MSR_INSTANCES    (1)

/*
	Smart Card
*/
#define MXC_BASE_SC ((uint32_t)0x4002C000UL)
#define MXC_SC ((mxc_sc_regs_t*)MXC_BASE_SC)
#define MXC_SC_INSTANCES    (1)

/*
	Mono LCD Controller
*/
#define MXC_BASE_LCD ((uint32_t)0x40030000UL)

/*
	Color LCD Controller
*/
#define MXC_BASE_CLCD ((uint32_t)0x40031000UL)
#define MXC_CLCD ((mxc_clcd_regs_t*)MXC_BASE_CLCD)
#define MXC_CLCD_INSTANCES    (1)

/*
	Secure Keyboard
*/
#define MXC_BASE_KBD ((uint32_t)0x40032000UL)
#define MXC_KBD ((mxc_kbd_regs_t*)MXC_BASE_KBD)
#define MXC_KBD_INSTANCES    (1)

/*
	ADC
*/
#define MXC_BASE_ADC ((uint32_t)0x40034000UL)
#define MXC_ADC ((mxc_adc_regs_t*)MXC_BASE_ADC)
#define MXC_ADC_INSTANCES    (1)

/*
	DAC
*/
#define MXC_BASE_DAC ((uint32_t)0x40038000UL)
#define MXC_DAC ((mxc_dac_regs_t*)MXC_BASE_DAC)
#define MXC_DAC_INSTANCES    (1)

#define MXC_BASE_DAC_FIFO ((uint32_t)0x400B8000UL)
#define MXC_DAC_FIFO ((mxc_dac_fifo_t*)MXC_BASE_DAC_FIFO)

/*
	USB
*/
#define MXC_BASE_USB ((uint32_t)0x400B0000UL)
#define MXC_USB ((mxc_usb_regs_t*)MXC_BASE_USB)
#define MXC_USB_INSTANCES   (1)
#define MXC_USB_NUM_EP      (16)
#define MXC_USB_MAX_PACKET  (64)

/*
	TRNG
*/
#define MXC_BASE_TRNG ((uint32_t)0x400B5000UL)
#define MXC_TRNG ((mxc_trng_regs_t*)MXC_BASE_TRNG)
#define MXC_TRNG_INSTANCES    (1)

/******************************************************************************/
// bit_word_offset = (byte_offset x 32) + (bit_number × 4)
// bit_word_addr = bit_band_base + bit_word_offset
#define BITBAND(reg, bit)        ((0xf0000000 & (uint32_t)(reg)) + 0x2000000 + (((uint32_t)(reg) & 0x0fffffff) << 5) + ((bit) << 2))
#define BITBAND_ClrBit(reg, bit) *(volatile uint32_t *)BITBAND(reg, bit) = 0
#define BITBAND_SetBit(reg, bit) *(volatile uint32_t *)BITBAND(reg, bit) = 1
#define BITBAND_GetBit(reg, bit) (*(volatile uint32_t *)BITBAND(reg, bit))

#endif /* _MAX32550_H_ */
