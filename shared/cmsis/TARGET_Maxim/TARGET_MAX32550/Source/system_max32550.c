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
* $Id: system_max32550.c 15208 2014-09-16 18:53:05Z jeremy.brodt $
*
*******************************************************************************
*/

#include <stdint.h>
#include <stddef.h>
#include "max32550.h"
#include "gcr_regs.h"
#include "icc_regs.h"

/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = PLL0_FREQ;  /*!< System Clock Frequency (Core Clock)*/
uint32_t SystemPeriphClock = PLL0_FREQ / 2;

/*----------------------------------------------------------------------------
  Base address of interrupt vector table in flash
 *----------------------------------------------------------------------------*/
extern void (* const isr_vector[])(void);

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
  unsigned int freq;

  switch (MXC_GCR->clkcn & MXC_F_GCR_CLKCN_CLKSEL) {
    case MXC_S_GCR_CLKCN_CLKSEL_CRYPTO:
      freq = CRYPTO_RING_FREQ;
      break;
    case MXC_S_GCR_CLKCN_CLKSEL_PLL0:
      freq = PLL0_FREQ;
      break;
    case MXC_S_GCR_CLKCN_CLKSEL_HFXIN:
      freq = HFXIN_FREQ;
      break;
    case MXC_S_GCR_CLKCN_CLKSEL_RING:
      freq = NANO_RING_FREQ;
      break;
    default:
      return;
  }

  SystemCoreClock = freq >> ((MXC_GCR->clkcn & MXC_F_GCR_CLKCN_PSC) >> MXC_F_GCR_CLKCN_PSC_POS);
}

void SystemClockUpdate (void)
{
  SystemCoreClockUpdate();
  SystemPeriphClock = SystemCoreClock >> 1;
}

/* This function can be implemented by the application to initialize the STDIO interface */
__attribute__((weak))
int stdio_init(void *base)
{
  // Do nothing
  return 0;
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
  __set_PRIMASK(0);

  // Configure the interrupt controller to use the application vector table in Flash/RAM
  SCB->VTOR = (unsigned long)isr_vector;

  // Flush iCache
  MXC_ICC->inv = 1;
  while(!(MXC_ICC->ctrlstat & MXC_F_ICC_CTRLSTAT_RDY));

// TODO FIXME: disabling icache until HW issue is resolved
#ifdef ENABLE_CACHE
  // Enable iCache
  MXC_ICC->ctrlstat |= MXC_F_ICC_CTRLSTAT_EN;
#endif

  // Enable PLLs and wait for lock
  MXC_GCR->pll0cn |= MXC_F_GCR_PLL0CN_PLLEN;
  MXC_GCR->pll1cn |= MXC_F_GCR_PLL1CN_PLLEN;
  while ( !(MXC_GCR->pll0cn & MXC_F_GCR_PLL0CN_PLLLOCK) &&
          !(MXC_GCR->pll1cn & MXC_F_GCR_PLL1CN_PLLLOCK) );

  // Switch to PLL0 and wait for the clock
  MXC_GCR->clkcn = (MXC_GCR->clkcn & ~MXC_F_GCR_CLKCN_CLKSEL) | MXC_S_GCR_CLKCN_CLKSEL_PLL0;
  while (!(MXC_GCR->clkcn & MXC_F_GCR_CLKCN_CKRDY));

  // Enable all peripheral clocks
  MXC_GCR->perckcn = 0;

  SystemClockUpdate();

  stdio_init(NULL);
}
