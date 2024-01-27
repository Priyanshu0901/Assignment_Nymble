#ifndef SPIFFS_HAL_H
#define SPIFFS_HAL_H

#include "spiffs_conf.h"
#include "main.h"


void init_spiffs(void);

void write_uart_file(void);
void read_uart_file(void);

#endif //SPIFFS_HAL_H