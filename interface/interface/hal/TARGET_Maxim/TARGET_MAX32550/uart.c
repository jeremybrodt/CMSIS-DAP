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
#include "max32550.h"
#include "gpio_regs.h"
#include "uart_regs.h"
#include "uart.h"

static uint32_t baudrate;

// Size must be 2^n
#define  BUFFER_SIZE          (64)

static struct {
  uint8_t  data[BUFFER_SIZE];
  volatile uint16_t idx_in;
  volatile uint16_t idx_out;
  volatile  int16_t cnt_in;
  volatile  int16_t cnt_out;
} write_buffer, read_buffer;

/******************************************************************************/
int32_t uart_initialize(void)
{
  uart_uninitialize();

  // Configure GPIO for UART
  MXC_GPIO0->en_clr = (0x3UL << 12);
  MXC_GPIO0->en1_clr = (0x3UL << 12);

  MXC_UART1->ctrl_f.rxthd = 1;
  MXC_UART1->int_en |= MXC_F_UART_INTEN_FFRXIE;

  NVIC_EnableIRQ(UART1_IRQn);

  return 1;
}

/******************************************************************************/
int32_t uart_uninitialize(void)
{
  // disable interrupt
  NVIC_DisableIRQ(UART1_IRQn);

  // Disable interrupts
  MXC_UART1->int_en = 0;

  // Flush RX and TX FIFOS
  MXC_UART1->ctrl |= (MXC_F_UART_CTRL_TXFLUSH | MXC_F_UART_CTRL_RXFLUSH);

  // Wait for not busy
  while (MXC_UART1->stat & (MXC_F_UART_STAT_TXBUSY | MXC_F_UART_STAT_RXBUSY));

  // Clear registers
  MXC_UART1->ctrl = 0;
  MXC_UART1->int_stat = 0;
  MXC_UART1->baud0 = 0;
  MXC_UART1->baud1 = 0;
  MXC_UART1->pin = 0;
  MXC_UART1->dma = 0;

  // Clear buffers
  memset(&write_buffer, 0, sizeof(write_buffer));
  memset(&read_buffer, 0, sizeof(read_buffer));

  return 1;
}

/******************************************************************************/
void uart_set_control_line_state(uint16_t ctrl_bmp) {

}

/******************************************************************************/
int32_t uart_reset(void)
{
  NVIC_DisableIRQ(UART1_IRQn);

  // Flush RX and TX FIFOS
  MXC_UART1->ctrl |= (MXC_F_UART_CTRL_TXFLUSH | MXC_F_UART_CTRL_RXFLUSH);

  // Wait for not busy
  while (MXC_UART1->stat & (MXC_F_UART_STAT_TXBUSY | MXC_F_UART_STAT_RXBUSY));

  // Clear buffers
  memset(&write_buffer, 0, sizeof(write_buffer));
  memset(&read_buffer, 0, sizeof(read_buffer));

  NVIC_EnableIRQ(UART1_IRQn);

  return 1;
}

/******************************************************************************/
int32_t uart_set_configuration(UART_Configuration *config)
{
  uint32_t ctrl;

  // Get current configurations
  ctrl = MXC_UART1->ctrl & ~(MXC_F_UART_CTRL_PAREN |
                             MXC_F_UART_CTRL_PAREO |
                             MXC_F_UART_CTRL_PARMD |
                             MXC_F_UART_CTRL_SIZE |
                             MXC_F_UART_CTRL_STOP |
                             MXC_F_UART_CTRL_RTSCTSF);

  // Set the parity configuration
  switch (config->Parity) {
    case UART_PARITY_NONE:    break;
    case UART_PARITY_ODD:     ctrl |= (MXC_F_UART_CTRL_PAREN | MXC_F_UART_CTRL_PAREO); break;
    case UART_PARITY_EVEN:    ctrl |= (MXC_F_UART_CTRL_PAREN); break;
    case UART_PARITY_MARK:    return 0;
    case UART_PARITY_SPACE:   return 0;
  }

  switch (config->DataBits) {
    case UART_DATA_BITS_5:  ctrl |= MXC_S_UART_CTRL_SIZE_5; break;
    case UART_DATA_BITS_6:  ctrl |= MXC_S_UART_CTRL_SIZE_6; break;
    case UART_DATA_BITS_7:  ctrl |= MXC_S_UART_CTRL_SIZE_7; break;
    case UART_DATA_BITS_8:  ctrl |= MXC_S_UART_CTRL_SIZE_8; break;
    case UART_DATA_BITS_16: return 0;
  }

  switch (config->StopBits) {
    case UART_STOP_BITS_1:    break;
    case UART_STOP_BITS_1_5:
    case UART_STOP_BITS_2:    ctrl |= MXC_F_UART_CTRL_STOP; break;
  }

  switch (config->FlowControl) {
    case UART_FLOW_CONTROL_NONE:      break;
    case UART_FLOW_CONTROL_RTS_CTS:   ctrl |= MXC_F_UART_CTRL_RTSCTSF; break;
    case UART_FLOW_CONTROL_XON_XOFF:  return 0;
  }

  MXC_UART1->baud0 = MXC_UART_BAUD0(config->Baudrate);
  MXC_UART1->baud1 = MXC_UART_BAUD1(config->Baudrate);
  baudrate = config->Baudrate;

  // Set the new configuration
  MXC_UART1->ctrl = ctrl;

  return 1;
}

/******************************************************************************/
int32_t uart_get_configuration(UART_Configuration *config)
{
  uint32_t ctrl;

  // Get current configurations
  ctrl = MXC_UART1->ctrl;

  if (!(ctrl & MXC_F_UART_CTRL_PAREN)) {
    config->Parity = UART_PARITY_NONE;
  } else if (ctrl & MXC_F_UART_CTRL_PAREO) {
    config->Parity = UART_PARITY_ODD;
  } else {
    config->Parity = UART_PARITY_EVEN;
  }

  switch (ctrl & MXC_F_UART_CTRL_SIZE) {
    case MXC_S_UART_CTRL_SIZE_5: config->DataBits = UART_DATA_BITS_5; break;
    case MXC_S_UART_CTRL_SIZE_6: config->DataBits = UART_DATA_BITS_6; break;
    case MXC_S_UART_CTRL_SIZE_7: config->DataBits = UART_DATA_BITS_7; break;
    case MXC_S_UART_CTRL_SIZE_8: config->DataBits = UART_DATA_BITS_8; break;
  }

  if (!(ctrl & MXC_F_UART_CTRL_STOP)) {
    config->StopBits = UART_STOP_BITS_1;
  } else if ((ctrl & MXC_F_UART_CTRL_SIZE) == MXC_S_UART_CTRL_SIZE_5) {
    config->StopBits = UART_STOP_BITS_1_5;
  } else {
    config->StopBits = UART_STOP_BITS_2;
  }

  if (ctrl & MXC_F_UART_CTRL_RTSCTSF) {
    config->FlowControl = UART_FLOW_CONTROL_RTS_CTS;
  } else {
    config->FlowControl = UART_FLOW_CONTROL_NONE;
  }

  config->Baudrate = baudrate;

  return 1;
}

/******************************************************************************/
int32_t uart_write_free(void)
{
  return BUFFER_SIZE - (write_buffer.cnt_in - write_buffer.cnt_out);
}

/******************************************************************************/
int32_t uart_write_data(uint8_t *data, uint16_t size)
{
  uint32_t cnt;

  for (cnt = 0; (cnt < size) && ((write_buffer.cnt_in - write_buffer.cnt_out) < BUFFER_SIZE); cnt++) {
    write_buffer.data[write_buffer.idx_in++] = *data++;
    write_buffer.idx_in &= (BUFFER_SIZE - 1);
    write_buffer.cnt_in++;
  }

  // enable the transmit interrupt
  MXC_UART1->int_en |= MXC_F_UART_INTEN_FFTXOIE;
  NVIC_SetPendingIRQ(UART1_IRQn);

  return cnt;
}

/******************************************************************************/
int32_t uart_read_data(uint8_t *data, uint16_t size)
{
  int32_t cnt;

  for (cnt = 0; (cnt < size) && (read_buffer.cnt_in != read_buffer.cnt_out); cnt++) {
    *data++ = read_buffer.data[read_buffer.idx_out++];
    read_buffer.idx_out &= (BUFFER_SIZE - 1);
    read_buffer.cnt_out++;
  }

  if (MXC_UART1->stat & MXC_F_UART_STAT_RXELT) {
    NVIC_SetPendingIRQ(UART1_IRQn);
  }

  return cnt;
}

/******************************************************************************/
void UART1_IRQHandler(void)
{
  uint32_t int_stat;

  // Read and clear interrupts
  int_stat = MXC_UART1->int_stat;
  MXC_UART1->int_stat = ~int_stat;

  // Handle characters to transmit
  while (!(MXC_UART1->stat & MXC_F_UART_STAT_TXFULL) && (write_buffer.cnt_in != write_buffer.cnt_out)) {
    MXC_UART1->data = write_buffer.data[write_buffer.idx_out++];
    write_buffer.idx_out &= (BUFFER_SIZE - 1);
    write_buffer.cnt_out++;
  }

  // Handle received characters
  while (!(MXC_UART1->stat & MXC_F_UART_STAT_RXEMPTY) && ((read_buffer.cnt_in - read_buffer.cnt_out) < BUFFER_SIZE)) {
    read_buffer.data[read_buffer.idx_in++] = MXC_UART1->data;
    read_buffer.idx_in &= (BUFFER_SIZE - 1);
    read_buffer.cnt_in++;
  }
}
