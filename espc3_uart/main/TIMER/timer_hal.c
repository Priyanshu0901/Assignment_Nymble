//timer_hal.c

#include "timer_hal.h"

esp_timer_handle_t transfer_speed_timer;
esp_timer_handle_t odo_timer;

void transfer_speed_timer_callback(void* arg) {
    float bits_per_second = bytes_rec * 8;
    if(bits_per_second>0){
        printf("Bits per second: %.2f \n",bits_per_second);
        bytes_rec = 0;
    }
}

void setup_timer() {
    const esp_timer_create_args_t transfer_speed_timer_args = {
        .callback = &transfer_speed_timer_callback,
        .name = "transfer_speed_timer"
    };

    esp_err_t timer_ret = esp_timer_create(&transfer_speed_timer_args, &transfer_speed_timer);
    if (timer_ret != ESP_OK) {
    ESP_LOGE(TIMER_TAG, "Failed to create timer: %s", esp_err_to_name(timer_ret));
    // Handle the error.
    }
    else{
        printf("Timer Created - transfer_speed\r\n");
    }

}
