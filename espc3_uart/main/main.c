#include "main.h"
#include "uart_mngr.h"
#include "spiffs_mngr.h"
#include "timer_mngr.h"

uint8_t TX_Payload[MTU_Size];
uint8_t RX_Payload[MTU_Size];
TaskHandle_t Global_Loop;
uint8_t bytes_rec = 0;


void func(void* pvParameters){
    strcpy((char *)TX_Payload, "ESP ready\n");
    write_uart();

    start_timer();
    while(true){
        read_uart();
    }
}

void app_main(void)
{
    uart_1_init();
    init_spiffs();
    setup_timer();

    xTaskCreate(func,"Transmit_Task",2048,NULL,tskIDLE_PRIORITY, &Global_Loop);

}
