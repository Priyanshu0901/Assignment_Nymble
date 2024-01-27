#ifndef SPIFFS_CONF_H
#define SPIFFS_CONF_H

#include <sys/unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include "esp_spiffs.h"

extern esp_vfs_spiffs_conf_t conf;

extern const char rec_file[15];


#endif //SPIFFS_CONF_H