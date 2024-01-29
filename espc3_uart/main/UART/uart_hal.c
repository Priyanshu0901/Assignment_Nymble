//uart_hal.c

#include "uart_hal.h"

void uart_1_init(void){

    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));

    ESP_ERROR_CHECK(uart_set_pin(uart_num, UART_1_TX , UART_1_RX, UART_1_RTS, UART_1_CTS));

    ESP_ERROR_CHECK(uart_driver_install(uart_num, UART_1_RX_BUFF, UART_1_TX_BUFF, 0, NULL, 0));

    if(uart_is_driver_installed(uart_num))
        printf("\nUart Installed Properly\n");

}

void write_uart_transmit(){
    int bytes_written = uart_write_bytes(uart_num, TX_Payload, MTU_Size);
    
    if (bytes_written < 0) {
        printf("UART write error\n");
    }
    else if (bytes_written > 0) {
        bytes_rec += bytes_written;
        printf("TX data:\t");
        print_uart(&TX_Payload);
    }
}

void read_uart_transmit(){

    int bytes_read = uart_read_bytes(uart_num, RX_Payload, MTU_Size,10);
    
    if (bytes_read < 0) {
        printf("UART read error\n");
    }
    else if (bytes_read > 0) {
        bytes_rec += bytes_read;
        printf("RX data:\t");
        print_uart(&RX_Payload);
    }
}

int read_uart_transmit_ret(){
    memset(RX_Payload,0,MTU_Size);

    int bytes_read = uart_read_bytes(uart_num, RX_Payload, MTU_Size,10);
    
    if (bytes_read < 0) {
        printf("UART read error\n");
    }
    else if (bytes_read > 0) {
        bytes_rec += bytes_read;
        printf("RX data:\t");
        print_uart(&RX_Payload);
        return bytes_read;
    }
    return 0;
}


void print_uart(uint8_t Payload[]){
    puts((const char *)Payload);
}
