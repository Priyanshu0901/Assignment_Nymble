//spiffs_mngr.c

#include "spiffs_mngr.h"
#include "uart_mngr.h"


void send_file() {
    FILE *file = fopen(rec_file, "r");

    if (file == NULL) {
        ESP_LOGE(ESP_SPIFFS_TAG, "Failed to open file for reading");
        return;
    }

    fseek(file, 0, SEEK_END);
    long total_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(total_size + 1);
    if (content == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return;
    }

    fread(content, 1, total_size, file);
    fclose(file);

    content[total_size] = '\0';

    long start = 0;
    long end = MTU_Size;

    while (start < total_size) {
        char *packet = (char *)malloc(end - start + 1);
        strncpy(packet, content + start, end - start);
        packet[end - start] = '\0';

        memset (TX_Payload,0,sizeof(TX_Payload));
        strcpy((char *)TX_Payload,(char *)packet);
        write_uart();

        free(packet);

        start = end;
        end += MTU_Size;
    }

    memset (TX_Payload,0,sizeof(TX_Payload));
    strcpy((char *)TX_Payload, "EOF\n");
    write_uart();

    free(content);
}