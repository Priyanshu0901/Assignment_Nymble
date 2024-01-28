#ifndef TIMER_HAL_H
#define TIMER_HAL_H


#include "esp_timer.h"

#include "timer_conf.h"


extern void setup_timer();

extern esp_timer_handle_t transfer_speed_timer;

#endif  // TIMER_HAL_H
