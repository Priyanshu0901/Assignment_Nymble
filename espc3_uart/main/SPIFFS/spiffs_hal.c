//spiffs_hal.c

#include "spiffs_hal.h"

void init_spiffs(){
    esp_err_t ret = esp_vfs_spiffs_register(&conf);

    if(ret != ESP_OK){
        ESP_LOGE(ESP_SPIFFS_TAG, "%d\n", ret);
    }

    size_t total = 0, used = 0;
    esp_spiffs_info(conf.partition_label, &total, &used);
    ESP_LOGI(ESP_SPIFFS_TAG, "Partition size: total: %d, used: %d", total, used);

    if(esp_spiffs_mounted(conf.partition_label)){
        ESP_LOGI(ESP_SPIFFS_TAG,"Mounted");
    }

}

void write_uart_file() {

    ESP_LOGI(ESP_SPIFFS_TAG, "Opening LDS file");
    
    FILE* file = fopen(rec_file, "w") ;

    if (file == NULL) {
        ESP_LOGE(ESP_SPIFFS_TAG, "Failed to open file for writing");
        return;
    }

    // // Write the data to the file
    // for (int i = 0; i < LDS_BLACK_BOX_SIZE; i++) {
    //     for (int j = 0; j < LDS_NUMBER_OF_DATA; j++) {
    //         fprintf(file, "%u", lds_black_box[i][j]);
    //         if (j < LDS_NUMBER_OF_DATA - 1) {
    //             fprintf(file, ",");
    //         }
    //     }
    //     fprintf(file, "\n");
    // }

    fclose(file);
}


void read_uart_file() {
    FILE* file = fopen(rec_file, "r");

    if (file == NULL) {
        ESP_LOGE(ESP_SPIFFS_TAG, "Failed to open file for reading");
        return;
    }

    // Read the data from the file
    // for (int i = 0; i < LDS_BLACK_BOX_SIZE; i++) {
    //     for (int j = 0; j < LDS_NUMBER_OF_DATA; j++) {
    //         if (fscanf(file, "%hhu,", &lds_black_box[i][j]) != 1) {
    //             ESP_LOGE(ESP_SPIFFS_TAG, "Error reading data from file");
    //             break;
    //         }
    //     }
    // }

    fclose(file);
}