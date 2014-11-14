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

#ifndef DEVICE_CFG_H
#define DEVICE_CFG_H

#include <stdint.h>

typedef struct {
  uint32_t device_id;
  uint32_t flc_base;
  uint32_t clkdiv_value;
  uint32_t burst_size;
  uint32_t flash_base;
  uint32_t flash_size;
  uint32_t sector_size;
} device_cfg_t;

#endif /* DEVICE_CFG_H */
