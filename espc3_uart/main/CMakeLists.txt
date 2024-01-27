idf_component_register(SRCS 
                        "main.c"
                        "./UART/uart_conf.c" "./UART/uart_hal.c" "./UART/uart_mngr.c"
                        "./SPIFFS/spiffs_conf.c" "./SPIFFS/spiffs_hal.c" "./SPIFFS/spiffs_mngr.c"
                        "./RTC/rtc_hal.c"

                    INCLUDE_DIRS 
                    "."
                    "./UART"
                    "./SPIFFS"
                    "./RTC"

                    )
