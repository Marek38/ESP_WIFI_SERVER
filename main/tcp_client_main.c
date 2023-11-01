/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */
#include "nvs_flash.h"
#include "esp_netif.h"
#include "protocol_examples_common.h"
#include "esp_event.h"
#include "tcp_client.h"
#include "esp_log.h"

extern void tcp_client(void);

static const char *TAG = "MAIN";

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
     * Read "Establishing Wi-Fi or Ethernet Connection" section in
     * examples/protocols/README.md for more information about this function.
     */
    ESP_ERROR_CHECK(example_connect());

    int sock = 0;
    do
    {
        sock = tcp_client_init("192.168.100.94", 8075);
    } while (sock <= 0);

    while (1)
    {
        // ESP_LOGI(TAG, "Sending hallo...");
        // tcp_client_send(sock, "Hallo\n");
        // vTaskDelay(1000 / portTICK_PERIOD_MS);

        ESP_LOGI(TAG, "Receiving data from server...");
        char data_buffer[1000] = {0};
        bool rec_status = tcp_client_receive(sock, data_buffer, sizeof(data_buffer));
        if (rec_status)
        {
            ESP_LOGI(TAG, "Received data - %s", data_buffer);
        }
        else
        {
            ESP_LOGW(TAG, "There was some problem during receiving of data");
        }
    }
}
