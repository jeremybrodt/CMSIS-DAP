/* CMSIS-DAP Interface Firmware
 * Copyright (c) 2009-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "max32550.h"
#include "flc_regs.h"
#include "flash_hal.h"        // FlashOS Structures

/***** DEFINITIONS *****/
#define FLC_CN_UNLOCK_VALUE   0x20000000UL

/******************************************************************************/
int flash_hal_init(uint32_t clk)
{
  // Set flash clock divider to generate a 1MHz clock from the APB clock
  MXC_FLC->clkdiv = clk / 1000000;

  /* Check if the flash controller is busy */
  if (MXC_FLC->cn & MXC_F_FLC_CN_PEND) {
    return 1;
  }

  /* Clear stale errors */
  if (MXC_FLC->intr & MXC_F_FLC_INTR_AF) {
    MXC_FLC->intr &= ~MXC_F_FLC_INTR_AF;
  }

  /* Unlock flash */
  MXC_FLC->cn = (MXC_FLC->cn & ~MXC_F_FLC_CN_UNLOCK) | FLC_CN_UNLOCK_VALUE;

  return 0;
}

/******************************************************************************/
int flash_hal_uninit(uint32_t fnc)
{
  /* Lock flash */
  MXC_FLC->cn &= ~MXC_F_FLC_CN_UNLOCK;

  return 0;
}

/******************************************************************************/
int flash_hal_erase_chip(void)
{
  /* Check if flash operation is in progress or locked */
  if ((MXC_FLC->cn & (MXC_F_FLC_CN_PEND | MXC_F_FLC_CN_UNLOCK)) != FLC_CN_UNLOCK_VALUE) {
    return 1;
  }

  /* Write mass erase code */
  MXC_FLC->cn = (MXC_FLC->cn & ~MXC_F_FLC_CN_ERASE_CODE) | MXC_S_FLC_CN_CODE_MASS_ERASE;

  /* Issue mass erase command */
  MXC_FLC->cn |= MXC_F_FLC_CN_ME;

  /* Wait until flash operation is complete */
  while (MXC_FLC->cn & MXC_F_FLC_CN_PEND);

  /* Check access violations */
  if (MXC_FLC->intr & MXC_F_FLC_INTR_AF) {
    MXC_FLC->intr &= ~MXC_F_FLC_INTR_AF;
    return 1;
  }

  return 0;                                  // Finished without Errors
}

/******************************************************************************/
int flash_hal_erase_sector(uint32_t adr)
{
  if (adr < START_APP_ADDRESS) {
    return 1;
  }

  /* Check if flash operation is in progress or locked */
  if ((MXC_FLC->cn & (MXC_F_FLC_CN_PEND | MXC_F_FLC_CN_UNLOCK)) != FLC_CN_UNLOCK_VALUE) {
    return 1;
  }

  /* Write page erase code */
  MXC_FLC->cn = (MXC_FLC->cn & ~MXC_F_FLC_CN_ERASE_CODE) | MXC_S_FLC_CN_CODE_PAGE_ERASE;

  /* Issue page erase command */
  MXC_FLC->addr = adr;
  MXC_FLC->cn |= MXC_F_FLC_CN_PGE;

  /* Wait until flash operation is complete */
  while (MXC_FLC->cn & MXC_F_FLC_CN_PEND);

  /* Check access violations */
  if (MXC_FLC->intr & MXC_F_FLC_INTR_AF) {
    MXC_FLC->intr &= ~MXC_F_FLC_INTR_AF;
    return 1;
  }

  return 0;                                  // Finished without Errors
}

/******************************************************************************/
int flash_hal_program_page(uint32_t adr, uint32_t sz, unsigned char *buf)
{
  unsigned long *ptr32;
  uint32_t last_word = 0xffffffff;
  uint32_t mask = 0xff;

  if (adr < START_APP_ADDRESS) {
    return 1;
  }

  /* Must be word aligned */
  if (adr & 0x3) {
    return 1;
  }

  /* Must not exceed flash size */
  if ((adr + sz) > (MXC_FLASH_MEM_BASE + MXC_FLASH_MEM_SIZE)) {
    return 1;
  }

  /* Check if flash operation is in progress or locked */
  if ((MXC_FLC->cn & (MXC_F_FLC_CN_PEND | MXC_F_FLC_CN_UNLOCK)) != FLC_CN_UNLOCK_VALUE) {
    return 1;
  }

  ptr32 = (unsigned long *)buf;

  // write in 32-bit units until we are 128-bit aligned
  MXC_FLC->cn &= ~MXC_F_FLC_CN_BRST;
  MXC_FLC->cn |= MXC_F_FLC_CN_WDTH;

  while ( (sz >= 4) && ((adr & 0x1F) != 0) ) {
    MXC_FLC->addr = adr;
    MXC_FLC->data0 = *ptr32++;
    MXC_FLC->cn |= MXC_F_FLC_CN_WR;

    /* Wait until flash operation is complete */
    while (MXC_FLC->cn & MXC_F_FLC_CN_PEND);

    adr += 4;
    sz -= 4;
  }

  if (sz >= 16) {
    // write in 128-bit bursts while we can
    MXC_FLC->cn &= ~MXC_F_FLC_CN_WDTH;
    MXC_FLC->cn |= MXC_F_FLC_CN_BRST;

    while (sz >= 16) {
      MXC_FLC->addr = adr;
      MXC_FLC->data0 = *ptr32++;
      MXC_FLC->data1 = *ptr32++;
      MXC_FLC->data2 = *ptr32++;
      MXC_FLC->data3 = *ptr32++;
      MXC_FLC->cn |= MXC_F_FLC_CN_WR;

      /* Wait until flash operation is complete */
      while (MXC_FLC->cn & MXC_F_FLC_CN_PEND);

      adr += 16;
      sz -= 16;
    }
  }

  if (sz >= 4) {
    // write in 32-bit units while we can
    MXC_FLC->cn &= ~MXC_F_FLC_CN_BRST;
    MXC_FLC->cn |= MXC_F_FLC_CN_WDTH;

    while (sz >= 4) {
      MXC_FLC->addr = adr;
      MXC_FLC->data0 = *ptr32++;
      MXC_FLC->cn |= MXC_F_FLC_CN_WR;

      /* Wait until flash operation is complete */
      while (MXC_FLC->cn & MXC_F_FLC_CN_PEND);

      adr += 4;
      sz -= 4;
    }
  }

  if (sz > 0) {
    // write remaining bytes in a 32-bit unit
    MXC_FLC->cn &= ~MXC_F_FLC_CN_BRST;
    MXC_FLC->cn |= MXC_F_FLC_CN_WDTH;

    while (sz > 0) {
      last_word &= (*ptr32 | ~mask);
      mask <<= 8;
      sz--;
    }

    MXC_FLC->addr = adr;
    MXC_FLC->data0 = last_word;
    MXC_FLC->cn |= MXC_F_FLC_CN_WR;

    /* Wait until flash operation is complete */
    while (MXC_FLC->cn & MXC_F_FLC_CN_PEND);
  }

  /* Check access violations */
  if (MXC_FLC->intr & MXC_F_FLC_INTR_AF) {
    MXC_FLC->intr &= ~MXC_F_FLC_INTR_AF;
    return 1;
  }

  return 0;                                  // Finished without Errors
}
