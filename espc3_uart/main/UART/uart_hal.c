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
    // Send the data
    //int bytes_written = uart_write_bytes(uart_num, UART_TX_Data_un.Payload, UART_TX_DATA_LEN);
    
    // if (bytes_written < 0) {
    //     printf("UART write error\n");
    // }
}

void read_uart_transmit(){
    // Read the data
    //int bytes_read = uart_read_bytes(uart_num, UART_RX_Data_un.Payload, UART_RX_DATA_LEN,100);
    
//     if (bytes_read < 0) {
//         printf("UART read error\n");
//     }
}
