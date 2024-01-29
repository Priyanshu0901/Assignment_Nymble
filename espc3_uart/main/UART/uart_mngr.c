//uart_mngr.c

#include "uart_mngr.h"

void write_uart(void){
    write_uart_transmit();
}


void read_uart(void){
    memset(RX_Payload,0,MTU_Size);
    read_uart_transmit();
}