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

#include "target_reset.h"
#include "jtag_host.h"
#include "DAP_config.h"
#include "DAP.h"

void target_before_init_debug(void)
{
  DAP_Data.jtag_dev.count = 1;
  DAP_Data.jtag_dev.index = 0;
  DAP_Data.jtag_dev.ir_length[0] = 4;
  DAP_Data.jtag_dev.ir_before[0] = 0;
  DAP_Data.jtag_dev.ir_after[0] = 0;
}

uint8_t target_port_init(void)
{
  PORT_JTAG_SETUP();
  return 1;
}

uint8_t target_unlock_sequence(void)
{
  return 1;
}

uint8_t target_set_state(TARGET_RESET_STATE state)
{
  return jtag_set_target_state(state);
}

uint8_t target_read_memory(uint32_t address, uint8_t *data, uint32_t size) {
  return jtag_read_memory(address, data, size);
}
