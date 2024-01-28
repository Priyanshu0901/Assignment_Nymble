#ifndef UART_HAL_H
#define UART_HAL_H

#include "uart_conf.h"

void uart_1_init(void);

void write_uart_transmit(void);
void read_uart_transmit(void);

void print_uart(uint8_t Payload[]);

#endif //UART_HAL_H