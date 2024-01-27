//rtc.c

#include "rtc_hal.h"

uint64_t rtc_cb(){
    return (esp_rtc_get_time_us());
}

void print_rtc(){
    printf("%llu\n", (esp_rtc_get_time_us()));
}