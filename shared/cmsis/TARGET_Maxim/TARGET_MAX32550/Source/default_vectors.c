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
* $Id: default_vectors.c 15208 2014-09-16 18:53:05Z jeremy.brodt $
*
********************************************************************************
*/

#include "max32550.h"

/* The stack address is defined by the linker
 * It is typed as a function here to avoid compiler warnings
 */
extern void __StackTop(void);

void Reset_Handler(void);

/* This macro will create weak functions for the default interrupt handlers */
#define CREATE_DEFAULT_HANDLER(name)      \
__attribute__((weak)) void name(void) {   \
  while(1);                               \
}

/* ARM Cortex Interrupts */
CREATE_DEFAULT_HANDLER(NMI_Handler);
CREATE_DEFAULT_HANDLER(HardFault_Handler);
CREATE_DEFAULT_HANDLER(MemManage_Handler);
CREATE_DEFAULT_HANDLER(BusFault_Handler);
CREATE_DEFAULT_HANDLER(UsageFault_Handler);
CREATE_DEFAULT_HANDLER(SVC_Handler);
CREATE_DEFAULT_HANDLER(DebugMon_Handler);
CREATE_DEFAULT_HANDLER(PendSV_Handler);
CREATE_DEFAULT_HANDLER(SysTick_Handler);

/* External Interrupts */
CREATE_DEFAULT_HANDLER(PF_IRQHandler);
CREATE_DEFAULT_HANDLER(WDT_IRQHandler);
CREATE_DEFAULT_HANDLER(USB_IRQHandler);
CREATE_DEFAULT_HANDLER(RTC_IRQHandler);
CREATE_DEFAULT_HANDLER(TRNG_IRQHandler);
CREATE_DEFAULT_HANDLER(TMR0_IRQHandler);
CREATE_DEFAULT_HANDLER(TMR1_IRQHandler);
CREATE_DEFAULT_HANDLER(TMR2_IRQHandler);
CREATE_DEFAULT_HANDLER(TMR3_IRQHandler);
CREATE_DEFAULT_HANDLER(TMR4_IRQHandler);
CREATE_DEFAULT_HANDLER(TMR5_IRQHandler);
CREATE_DEFAULT_HANDLER(SC_IRQHandler);
CREATE_DEFAULT_HANDLER(LCD_IRQHandler);
CREATE_DEFAULT_HANDLER(I2C_IRQHandler);
CREATE_DEFAULT_HANDLER(UART0_IRQHandler);
CREATE_DEFAULT_HANDLER(UART1_IRQHandler);
CREATE_DEFAULT_HANDLER(SPI0_IRQHandler);
CREATE_DEFAULT_HANDLER(SPI1_IRQHandler);
CREATE_DEFAULT_HANDLER(SPI2_IRQHandler);
CREATE_DEFAULT_HANDLER(KBD_IRQHandler);
CREATE_DEFAULT_HANDLER(ADC_IRQHandler);
CREATE_DEFAULT_HANDLER(DAC_IRQHandler);
CREATE_DEFAULT_HANDLER(MSR_IRQHandler);
CREATE_DEFAULT_HANDLER(FLC_IRQHandler);
CREATE_DEFAULT_HANDLER(GPIO0_IRQHandler);
CREATE_DEFAULT_HANDLER(GPIO1_IRQHandler);
CREATE_DEFAULT_HANDLER(GPIO2_IRQHandler);
CREATE_DEFAULT_HANDLER(CRYPTO_IRQHandler);
CREATE_DEFAULT_HANDLER(DMA0_IRQHandler);
CREATE_DEFAULT_HANDLER(DMA1_IRQHandler);
CREATE_DEFAULT_HANDLER(DMA2_IRQHandler);
CREATE_DEFAULT_HANDLER(DMA3_IRQHandler);

/* Create the application vector table in Flash/RAM */
__attribute__ ((section(".isr_vector"), used, aligned(256)))
void (* const isr_vector[MXC_NUM_VECTORS])(void) =
{
  __StackTop,            /* Top of Stack */
  Reset_Handler,         /* Reset Handler */
  NMI_Handler,           /* NMI Handler */
  HardFault_Handler,     /* Hard Fault Handler */
  MemManage_Handler,     /* MPU Fault Handler */
  BusFault_Handler,      /* Bus Fault Handler */
  UsageFault_Handler,    /* Usage Fault Handler */
  0,                     /* Reserved */
  0,                     /* Reserved */
  0,                     /* Reserved */
  0,                     /* Reserved */
  SVC_Handler,           /* SVCall Handler */
  DebugMon_Handler,      /* Debug Monitor Handler */
  0,                     /* Reserved */
  PendSV_Handler,        /* PendSV Handler */
  SysTick_Handler,       /* SysTick Handler */

  /* External interrupts */
  PF_IRQHandler,          /* Power Fail Interrupt */
  WDT_IRQHandler,         /* Watchdog Timer Interrupt */
  USB_IRQHandler,         /* USB Interrupt */
  RTC_IRQHandler,         /* Real-Time Clock Interrupt */
  TRNG_IRQHandler,        /* True Random Number Generator Interrupt */
  TMR0_IRQHandler,        /* Timer 0 Interrupt */
  TMR1_IRQHandler,        /* Timer 1 Interrupt */
  TMR2_IRQHandler,        /* Timer 2 Interrupt */
  TMR3_IRQHandler,        /* Timer 3 Interrupt */
  TMR4_IRQHandler,        /* Timer 4 Interrupt */
  TMR5_IRQHandler,        /* Timer 5 Interrupt */
  SC_IRQHandler,          /* Smart Card Interrupt */
  LCD_IRQHandler,         /* Mono LCD/TFT Interrupt */
  I2C_IRQHandler,         /* I2C Interrupt */
  UART0_IRQHandler,       /* UART 0 Interrupt */
  UART1_IRQHandler,       /* UART 1 Interrupt */
  SPI0_IRQHandler,        /* SPI 0 Interrupt */
  SPI1_IRQHandler,        /* SPI 1 Interrupt */
  SPI2_IRQHandler,        /* SPI 2 Interrupt */
  KBD_IRQHandler,         /* Secure Keypad Interrupt */
  ADC_IRQHandler,         /* ADC Interrupt */
  DAC_IRQHandler,         /* DAC Interrupt */
  MSR_IRQHandler,         /* MSR DSP Done Interrupt */
  FLC_IRQHandler,         /* Flash Controller Interrupt */
  GPIO0_IRQHandler,       /* GPIO 0 Interrupt */
  GPIO1_IRQHandler,       /* GPIO 1 Interrupt */
  GPIO2_IRQHandler,       /* GPIO 2 Interrupt */
  CRYPTO_IRQHandler,      /* Crypto Engine Interrupt */
  DMA0_IRQHandler,        /* DMA Channel 0 Interrupt */
  DMA1_IRQHandler,        /* DMA Channel 1 Interrupt */
  DMA2_IRQHandler,        /* DMA Channel 2 Interrupt */
  DMA3_IRQHandler,        /* DMA Channel 3 Interrupt */
};

