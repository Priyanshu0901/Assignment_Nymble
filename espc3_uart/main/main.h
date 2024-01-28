#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include <rom/ets_sys.h>
#include "esp_log.h"
#include "esp_err.h"
#include "esp_system.h"

#define ESP_RTC_TAG         "ESP_RTC"
#define ESP_SPIFFS_TAG      "ESP_SPIFFS"
#define TIMER_TAG           "ESP_TIMER"

#define MTU_Size 50

extern uint8_t TX_Payload[MTU_Size];
extern uint8_t RX_Payload[MTU_Size];

extern TaskHandle_t Global_Loop;

extern uint8_t bytes_rec;

#endif