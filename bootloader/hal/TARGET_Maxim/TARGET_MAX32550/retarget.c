/******************************************************************************/
/* RETARGET.C: 'Retarget' layer for target-dependent low level functions      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005 Keil Software. All rights reserved.                     */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <stdio.h>
#include <rt_misc.h>

#include "max32550.h"
#include "gpio_regs.h"
#include "uart_regs.h"

// Allow UART instance to be overridden at build time
#ifndef CONSOLE_UART
#define CONSOLE_UART  MXC_UART0
#endif

// Allow baud rate to be overridden at build time
#ifndef CONSOLE_BAUD
#define CONSOLE_BAUD  115200
#endif


#pragma import(__use_no_semihosting_swi)

struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;

mxc_uart_regs_t * ConsoleUart = (mxc_uart_regs_t*)CONSOLE_UART;

int stdio_init(void *base)
{
  /* If base is not NULL, override the default UART */
  if (base != NULL) {
    ConsoleUart = (mxc_uart_regs_t*)base;
  }

  // Configure GPIO for UART
  if (ConsoleUart == MXC_UART0) {
    MXC_GPIO0->en_clr = (0x3UL << 8);
    MXC_GPIO0->en1_clr = (0x3UL << 8);
  } else if (ConsoleUart == MXC_UART1) {
    MXC_GPIO0->en_clr = (0x3UL << 12);
    MXC_GPIO0->en1_clr = (0x3UL << 12);
  } else {
    ConsoleUart = 0;
    return -1;
  }

  // Disable interrupts
  ConsoleUart->int_en = 0;

  // Flush RX and TX FIFOS
  ConsoleUart->ctrl |= (MXC_F_UART_CTRL_TXFLUSH | MXC_F_UART_CTRL_RXFLUSH);

  // Wait for not busy
  while(ConsoleUart->stat & (MXC_F_UART_STAT_TXBUSY | MXC_F_UART_STAT_RXBUSY)) {}

  // Clear registers
  ConsoleUart->ctrl = 0;
  ConsoleUart->int_stat = 0;

  // Set the parity, size, stop and flow configuration
  ConsoleUart->ctrl |= MXC_S_UART_CTRL_SIZE_8;

  // Set the baud rate
  // Definitions in uart_regs.h
  ConsoleUart->baud0 = MXC_UART_BAUD0(CONSOLE_BAUD);
  ConsoleUart->baud1 = MXC_UART_BAUD1(CONSOLE_BAUD);

  return 0;
}


int fputc(int ch, FILE *f) {
  if (ConsoleUart != 0) {
    if (ch == '\n') {
      while (ConsoleUart->stat & MXC_F_UART_STAT_TXFULL);
      ConsoleUart->data = '\r';
    }
    while (ConsoleUart->stat & MXC_F_UART_STAT_TXFULL);
    ConsoleUart->data = ch;
  }
  return ch;
}

int fgetc(FILE *f) {
  char ch;

  if (ConsoleUart != 0) {
    while (ConsoleUart->stat & MXC_F_UART_STAT_RXEMPTY);
    ch = ConsoleUart->data;
    fputc(ch, f);
    return ch;
  }

  return 0;
}


int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}


void _ttywrch(int ch) {
  if (ConsoleUart != 0) {
    while (ConsoleUart->stat & MXC_F_UART_STAT_TXFULL);
    ConsoleUart->data = ch;
  }
}


void _sys_exit(int return_code) {
  while (1);    /* endless loop */
}
