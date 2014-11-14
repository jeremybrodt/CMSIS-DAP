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

#include <string.h>
#include "version.h"
#include "jtag_host.h"
#include "DAP_config.h"
#include "DAP.h"

// MAX326xx pin mapping
#define PIN_RSTN_OUT   PIN_nTRST_OUT
#define PIN_SRSTN_OUT  PIN_nRESET_OUT

void target_dsb(void) {

  // Select Maxim test TAP (TSEL=0)
  PIN_TSEL_OUT(0);
  Delayms(1);

  // Assert RSTN
  PIN_RSTN_OUT(0);
  Delayms(1);

  // Release RSTN
  PIN_RSTN_OUT(1);
  Delayms(10);

  // Write DSB_code (default 0x0) to address 0x87654321
  JTAG_IR(0x7);
  JTAG_DR(32, 0x0, NULL);
  JTAG_IR(0x6);
  JTAG_DR(32, 0x87654321, NULL);

  // Set bit 31 of JTAG test_control register
  JTAG_IR(0xA);
  JTAG_DR(32, 0x80000000, NULL);
  Delayms(1);

  // Assert and release SRSTN to trigger DSB
  PIN_SRSTN_OUT(0);
  PIN_SRSTN_OUT(1);
  Delayms(1);

  // Assert RSTN to clear DSB_code
  PIN_RSTN_OUT(0);
  Delayms(1);

  // Select ARM TAP (TSEL=1)
  PIN_TSEL_OUT(1);

  // Release RSTN
  PIN_RSTN_OUT(1);
}

// Process DAP Vendor command and prepare response
// Default function (can be overridden)
//   request:  pointer to request data
//   response: pointer to response data
//   return:   number of bytes in response
// this function is declared as __weak in DAP.c
uint32_t DAP_ProcessVendorCommand(uint8_t *request, uint8_t *response) {

    // get unique ID command
    if (*request == ID_DAP_Vendor0) {
        uint8_t * id_str = get_uid_string();
        uint8_t len = strlen((const char *)(id_str + 4));
        *response = ID_DAP_Vendor0;
        *(response + 1) = len;
        memcpy(response + 2, id_str + 4, len);
        return (len + 2);
    }

    // Destructive Security Bypass
    else if (*request == ID_DAP_Vendor1) {
        target_dsb();
        *response = ID_DAP_Vendor1;
        return (1);
    }

    // else return invalid command
    else {
        *response = ID_DAP_Invalid;
    }
    return (1);
}
