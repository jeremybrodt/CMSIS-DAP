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

#ifndef TARGET_FLASH_H
#define TARGET_FLASH_H

#include <stdint.h>

#define FLASH_SECTOR_SIZE   flash_sector_size
#define TARGET_AUTO_INCREMENT_PAGE_SIZE     (0x800)

/***** Global Data *****/
extern uint32_t flash_sector_size;

/***** Function Prototypes *****/
uint8_t target_flash_init(uint32_t clk);
uint8_t target_flash_erase_sector(unsigned int sector);
uint8_t target_flash_erase_chip(void);
uint8_t target_flash_program_page(uint32_t address, uint8_t *buffer, uint32_t size);

#endif  /* TARGET_FLASH_H */
