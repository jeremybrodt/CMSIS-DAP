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
#include "gpio_regs.h"
#include "RTL.h"

#ifdef TARGET_MAX32550_EVKIT
#define DAP_LED_PORT        MXC_GPIO0
#define DAP_LED_MASK        (1 << 21)
#define MSD_LED_PORT        MXC_GPIO0
#define MSD_LED_MASK        (1 << 22)
#define CDC_LED_PORT        MXC_GPIO0
#define CDC_LED_MASK        (1 << 22)
#else
#define DAP_LED_PORT        MXC_GPIO1
#define DAP_LED_MASK        (1 << 26)
#define MSD_LED_PORT        MXC_GPIO1
#define MSD_LED_MASK        (1 << 24)
#define CDC_LED_PORT        MXC_GPIO1
#define CDC_LED_MASK        (1 << 25)
#endif

void gpio_init(void)
{
    // DAP led (green)
    DAP_LED_PORT->out_set = DAP_LED_MASK;
    DAP_LED_PORT->en_set = DAP_LED_MASK;
    DAP_LED_PORT->en1_clr = DAP_LED_MASK;
    DAP_LED_PORT->out_en_set = DAP_LED_MASK;

    // MSD led (red)
    MSD_LED_PORT->out_set = MSD_LED_MASK;
    MSD_LED_PORT->en_set = MSD_LED_MASK;
    MSD_LED_PORT->en1_clr = MSD_LED_MASK;
    MSD_LED_PORT->out_en_set = MSD_LED_MASK;

    // Serial LED (blue)
    CDC_LED_PORT->out_set = CDC_LED_MASK;
    CDC_LED_PORT->en_set = CDC_LED_MASK;
    CDC_LED_PORT->en1_clr = CDC_LED_MASK;
    CDC_LED_PORT->out_en_set = CDC_LED_MASK;
}

void gpio_set_dap_led(uint8_t state)
{
    if (state) {
        DAP_LED_PORT->out_set = DAP_LED_MASK;
    } else {
        DAP_LED_PORT->out_clr = DAP_LED_MASK;
    }
}

void gpio_set_msd_led(uint8_t state)
{
    if (state) {
        MSD_LED_PORT->out_set = MSD_LED_MASK;
    } else {
        MSD_LED_PORT->out_clr = MSD_LED_MASK;
    }
}

void gpio_set_cdc_led(uint8_t state)
{
    if (state) {
        CDC_LED_PORT->out_set = CDC_LED_MASK;
    } else {
        CDC_LED_PORT->out_clr = CDC_LED_MASK;
    }
}

void gpio_enable_button_flag(OS_TID task, uint16_t flags) {
}
