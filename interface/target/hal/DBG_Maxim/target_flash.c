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

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "target_flash.h"
#include "target_struct.h"
#include "jtag_host.h"
#include "device_cfg.h"

#define ROM_TABLE_PID0  (0xE00FFFE0UL)
#define DEFAULT_ID      (0xB4C3)
#define MEDICAL_ID      (0x40090838UL)

typedef struct {
  uint32_t die_type;
  uint16_t part_num;
  uint16_t pkg_sel;
  uint32_t rev_id    :  4;
  uint32_t mask_id_l : 28;
  uint32_t mask_id_h : 31;
  uint32_t mask_id   :  1;
} medical_id_t;

#define DEV_CFG_TARGET_ADDRESS  (0x0000025cUL)    // From flash_algo map file
#define FLASH_ALGO_GEN_ADDER    32
#define DEV_CFG_LOCAL_ADDRESS   ((uint8_t*)((unsigned int)flash_algo_blob + DEV_CFG_TARGET_ADDRESS + FLASH_ALGO_GEN_ADDER))

/***** Global Data *****/
uint32_t flash_sector_size;


/***** File Scope Data *****/
static const device_cfg_t device_cfg[] = {
  { 0x4d513637UL, 0x400F0000UL, (12000000UL / 1000000UL),  32, 0x00000000UL, 0x040000,  0x800 }, // MAX32600 256kB, 2KB sectors
  { 0x4d453032UL, 0x40002000UL, (12000000UL / 1000000UL),  32, 0x00000000UL, 0x200000, 0x2000 }, // MAX32615 2MB, 8KB sectors
  {     0xB101UL, 0x40029000UL, (12000000UL / 1000000UL), 128, 0x10000000UL, 0x100000, 0x1000 }, // MAX32550 1MB, 4KB sectors
  {     0xB102UL, 0x40029000UL, (12000000UL / 1000000UL), 128, 0x10000000UL, 0x080000, 0x1000 }, // MAX32555 512kB, 4KB sectors
};
#define NUM_DEVICE_CFG  (sizeof(device_cfg) / sizeof(device_cfg_t))

static uint32_t flash_algo_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x4603b510, 0x4893460c, 0x68414448, 0xf0006888, 0xb1087080, 0xbd102001, 0x4448488e, 0x60486880, 
    0xe7f82000, 0x488b4602, 0x68414448, 0xf0206888, 0x60884070, 0x47702000, 0x44484886, 0x68886841, 
    0x7080f000, 0x2001b108, 0x6a484770, 0x2000b148, 0x6a486248, 0x2002b128, 0x6a486248, 0x2001b108, 
    0x6888e7f2, 0x4070f020, 0x5000f040, 0x20006088, 0xb510e7ea, 0x44484877, 0xf7ff6844, 0xb108ffdd, 
    0xbd102001, 0xf42068a0, 0xf440407f, 0x60a0402a, 0xf04068a0, 0x60a00002, 0x68a0bf00, 0x7080f000, 
    0xd1fa2800, 0xf02068a0, 0x60a04070, 0xf0006a60, 0xb1080002, 0xe7e42001, 0xe7e22000, 0x4605b570, 
    0x44484864, 0xf7ff6844, 0xb108ffb7, 0xbd702001, 0xf42068a0, 0xf440407f, 0x60a040aa, 0x68a06025, 
    0x0004f040, 0xbf0060a0, 0xf00068a0, 0x28007080, 0x68a0d1fa, 0x4070f020, 0x6a6060a0, 0x0002f000, 
    0x2001b108, 0x2000e7e3, 0xe92de7e1, 0x460747f0, 0x4690468a, 0x4448484f, 0x46566844, 0xf0084645, 
    0xb1100003, 0xe8bd2001, 0x464587f0, 0xff84f7ff, 0x2001b108, 0x68a0e7f7, 0x6000f020, 0x68a060a0, 
    0x0010f040, 0xe00e60a0, 0xcd016027, 0x68a06320, 0x0001f040, 0xbf0060a0, 0xf00068a0, 0x28007080, 
    0x1d3fd1fa, 0x2e041f36, 0xf007d303, 0x2800001f, 0x4838d1ea, 0x68c04448, 0xd1212880, 0xd31f2e10, 
    0xf02068a0, 0x60a00010, 0xf04068a0, 0x60a06000, 0x6027e014, 0x6320cd01, 0x6360cd01, 0x63a0cd01, 
    0x63e0cd01, 0xf04068a0, 0x60a00001, 0x68a0bf00, 0x7080f000, 0xd1fa2800, 0x3e103710, 0xd2e82e10, 
    0xd3192e04, 0xf02068a0, 0x60a06000, 0xf04068a0, 0x60a00010, 0x6027e00e, 0x6320cd01, 0xf04068a0, 
    0x60a00001, 0x68a0bf00, 0x7080f000, 0xd1fa2800, 0x1f361d3f, 0xd2ee2e04, 0x68a2b306, 0x6200f022, 
    0x68a260a2, 0x0210f042, 0xf04f60a2, 0x21ff30ff, 0x682ae005, 0x0201ea62, 0x02094010, 0x2e001e76, 
    0x6027d1f7, 0x68a26320, 0x0201f042, 0xbf0060a2, 0xf00268a2, 0x2a007280, 0xbf00d1fa, 0xf02068a0, 
    0x60a04070, 0xf0006a60, 0xb1080002, 0xe76a2001, 0xe7682000, 0x00000004, 0x00000000, 0x11111111, 
    0x22222222, 0x33333333, 0x44444444, 0x00000000, 0x00000000, 0x00000000, 
};

static const TARGET_FLASH flash = {
    0x20000021, // Init
    0x20000045, // UnInit
    0x20000093, // EraseChip
    0x200000DD, // EraseSector
    0x2000012B, // ProgramPage

    // RSB : base address is address of Execution Region PrgData in map file
    //       to access global/static data
    // RSP : Initial stack pointer
    {0x20000001, 0x20000258 + FLASH_ALGO_GEN_ADDER, 0x20001000}, // {breakpoint, RSB, RSP}

    0x20000400,               // program_buffer
    0x20000000,               // algo_start
    sizeof(flash_algo_blob),  // algo_size
    flash_algo_blob,          // image

    512   // ram_to_flash_bytes_to_be_written
};

static const device_cfg_t *current_cfg = NULL;



uint32_t temp_buffer[1024/4];

/******************************************************************************/
uint8_t target_flash_init(uint32_t clk)
{
  uint32_t pid[2], device_id;
  medical_id_t medical_id;
  int i;

  // Read Device ID
  if (!jtag_read_memory(ROM_TABLE_PID0, (uint8_t *)pid, sizeof(pid))) {
    return 0;
  }
  device_id = (pid[1] << 8) + pid[0];

  if (device_id == DEFAULT_ID) {
    // This device used the ARM default ID. Try to look for the medical ID
    if (!jtag_read_memory(MEDICAL_ID, (uint8_t *)&medical_id, sizeof(medical_id_t))) {
      return 0;
    }
    printf("Medical 0x%08x 0x%x %u\n", medical_id.die_type, medical_id.part_num, medical_id.part_num);
    device_id = medical_id.die_type;
  }

  // Search known devices
  for (i = 0; i < NUM_DEVICE_CFG; i++) {
    if (device_id == device_cfg[i].device_id) {
      printf("Device ID 0x%04x matched device %u\n", device_id, i);
      current_cfg = &device_cfg[i];
      break;
    }
  }

  if (i == NUM_DEVICE_CFG) {
    printf("Unknown device ID 0x%04x\n", device_id);
    current_cfg = NULL;
    return 0;
  }

  // Set sector size and configuration for this device
  flash_sector_size = current_cfg->sector_size;
  memcpy(DEV_CFG_LOCAL_ADDRESS, current_cfg, sizeof(device_cfg_t));

  // Download flash programming algorithm to target and initialise.
  if (!jtag_write_memory(flash.algo_start, (uint8_t *)flash.image, flash.algo_size)) {
    return 0;
  }

  return jtag_flash_syscall_exec(&flash.sys_call_param, flash.init, 0, 0 /* clk value is not used */, 0, 0);
}

/******************************************************************************/
uint8_t target_flash_erase_sector(unsigned int sector)
{
  uint32_t address;

  if (current_cfg == NULL) {
    return 0;
  }

  // Calculate sector address
  address = (sector * current_cfg->sector_size) + current_cfg->flash_base;
  
  return jtag_flash_syscall_exec(&flash.sys_call_param, flash.erase_sector, address, 0, 0, 0);
}

/******************************************************************************/
uint8_t target_flash_erase_chip(void)
{
  return jtag_flash_syscall_exec(&flash.sys_call_param, flash.erase_chip, 0, 0, 0, 0);
}

/******************************************************************************/
uint8_t target_flash_program_page(uint32_t address, uint8_t *buffer, uint32_t size)
{
  uint32_t bytes_written = 0;

  if (current_cfg == NULL) {
    return 0;
  }

  // Add flash base address
  address += current_cfg->flash_base;

  // Program a page in target flash.
  if (!jtag_write_memory(flash.program_buffer, buffer, size)) {
    return 0;
  }

  while(bytes_written < size) {
    if (!jtag_flash_syscall_exec(&flash.sys_call_param,
                                flash.program_page,
                                address,
                                flash.ram_to_flash_bytes_to_be_written,
                                flash.program_buffer + bytes_written, 0)) {
      return 0;
    }

    bytes_written += flash.ram_to_flash_bytes_to_be_written;
    address += flash.ram_to_flash_bytes_to_be_written;
  }

  return 1;
}
