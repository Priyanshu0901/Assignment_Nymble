#include "main.h"
#include "uart_mngr.h"
#include "spiffs_mngr.h"
#include "rtc_hal.h"

void app_main(void)
{
    uart_1_init();
    init_spiffs();

}
