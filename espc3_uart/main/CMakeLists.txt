idf_component_register(SRCS 
                        "main.c"
                        "./UART/uart_conf.c" "./UART/uart_hal.c" "./UART/uart_mngr.c"
                        "./SPIFFS/spiffs_conf.c" "./SPIFFS/spiffs_hal.c" "./SPIFFS/spiffs_mngr.c"
                        "./TIMER/timer_conf.c" "./TIMER/timer_hal.c" "./TIMER/timer_mngr.c"

                    INCLUDE_DIRS 
                    "."
                    "./UART"
                    "./SPIFFS"
                    "./TIMER"
                    )
