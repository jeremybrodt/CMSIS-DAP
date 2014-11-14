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
* $Id: system_max32550.h 13476 2014-05-09 15:49:57Z jeremy.brodt $
*
*******************************************************************************
*/

#ifndef SYSTEM_MAX32550_H
#define SYSTEM_MAX32550_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#ifndef HFXIN_FREQ
#define HFXIN_FREQ        12000000
#endif
#ifndef PLL0_FREQ
#define PLL0_FREQ         (HFXIN_FREQ * 9)
#endif
#define PLL1_FREQ         48000000

// Nominal Frequency (Nf) Calculation
// Per Spec: PCF = PSC + 2
// Nf = PCLK * 2^PCF
// PCLK = PLLO / 2^(PSC+1)
// Nf = 2 * PLLO
#define NOM_FREQ          (2 * PLL0_FREQ)

#define CRYPTO_RING_FREQ  12000000
#define NANO_RING_FREQ    40000000

extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */
extern uint32_t SystemPeriphClock;

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);
extern void SystemClockUpdate (void);

/**
 * Initialize and use the specified UART for Console STDIO
 *
 * @param  Pointer to the base address of the UART to use
 * @return 0 if successful, -1 upon error
 *
 * @brief  Initializes the specified UART for Console STDIO use.
 */
extern int SystemConsoleInit(void * uart);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_MAX32550_H */

