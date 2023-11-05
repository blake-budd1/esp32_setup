idf_component_register(SRCS "wifi.c"
                    INCLUDE_DIRS "."
                    REQUIRES esp_wifi nvs_flash)
                    # Updated REQUIRES esp_wifi nvs_flash b/c necessary for wifi module to work

