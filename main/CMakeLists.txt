if(${IDF_TARGET} STREQUAL "linux")
    set(requires esp_stubs protocol_examples_common nvs_flash)
endif()

idf_component_register(SRCS "tcp_server.c"
                                INCLUDE_DIRS "."
                                REQUIRES ${requires})
