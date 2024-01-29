//timer_mngr.c

#include "timer_mngr.h"

void start_timer(){
    esp_timer_start_periodic(transfer_speed_timer, time_interval);  // 1 second interval (in microseconds)
}

void stop_timer(){
    esp_timer_stop(transfer_speed_timer);

}

