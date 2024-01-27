//spiffs_conf.c

#include "spiffs_conf.h"

esp_vfs_spiffs_conf_t conf = {
    .base_path = "/storage",
    .partition_label = NULL,
    .max_files = 5,
    .format_if_mount_failed = true
};

const char rec_file[15] = "/b_box/lds.txt";

