if(${IDF_TARGET} STREQUAL "linux")
    set(requires esp_stubs protocol_examples_common nvs_flash)
endif()

idf_component_register(SRCS "tcp_client_main.c" "tcp_client.c"
                                INCLUDE_DIRS "."
                                REQUIRES ${requires})
