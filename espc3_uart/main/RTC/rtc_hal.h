#ifndef RTC_HAL_H
#define RTC_HAL_H

#include "rtc.h"
#include "esp_private/esp_clk.h"
#include "main.h"

extern void print_rtc();
extern uint64_t rtc_cb();

#endif //RTC_HAL_H