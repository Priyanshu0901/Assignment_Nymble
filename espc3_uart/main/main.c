#include "main.h"
#include "uart_mngr.h"
#include "spiffs_mngr.h"
#include "timer_mngr.h"

uint8_t TX_Payload[MTU_Size];
uint8_t RX_Payload[MTU_Size];
TaskHandle_t Global_Loop;
uint8_t bytes_rec = 0;


void func(void* pvParameters){
    start_timer();
    
    while(strcmp((char*)RX_Payload, "ACK") != 0){
        read_uart();
    }

    memset(TX_Payload, 0, sizeof(TX_Payload));
    strcpy((char *)TX_Payload, "50");

    while(strcmp((char*)RX_Payload, "MTU?") != 0){
        read_uart();
    }

    write_uart();
    memset(TX_Payload, 0, sizeof(TX_Payload));
    strcpy((char *)TX_Payload, "ACK\n");

    while((strcmp((char*)RX_Payload, "EOF") != 0)){
        read_uart();
        write_uart();    
    }

    write_uart();

    while (true)
    {
        /* code */
    }
    
}

void app_main(void)
{
    uart_1_init();
    init_spiffs();
    setup_timer();

    xTaskCreate(func,"Transmit_Task",2048,NULL,tskIDLE_PRIORITY, &Global_Loop);

}
