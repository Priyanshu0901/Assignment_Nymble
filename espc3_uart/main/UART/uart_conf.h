#ifndef UART_CONF_H
#define UART_CONF_H

#include "main.h"
#include "driver/uart.h"

#define UART_1_TX       21
#define UART_1_RX       20
#define UART_1_RTS      UART_PIN_NO_CHANGE
#define UART_1_CTS      UART_PIN_NO_CHANGE

#define UART_1_RX_BUFF  200
#define UART_1_TX_BUFF  200

extern const uart_port_t uart_num;

extern uart_config_t uart_config ;


#endif //UART_CONF_H