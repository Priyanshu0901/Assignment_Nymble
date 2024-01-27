//uart_mngr.c

#include "uart_mngr.h"

void write_uart(void){

    write_uart_transmit();
}

void print_uart(){
    printf(
        "RX data:"
    );

    for(int i =0;i<10;i++){
        //printf("\t%d,",UART_RX_Data_un.Payload[i]);
    }

    printf("\n");
}

void read_uart(void){
    //memset(UART_RX_Data_un.Payload,0,10);
    read_uart_transmit();
}