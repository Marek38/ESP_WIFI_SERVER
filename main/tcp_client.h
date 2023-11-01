#pragma once

#include "stdbool.h"
#include "stdint.h"
#include "stddef.h"

int tcp_client_init(const char* host_ip, uint16_t port);
bool tcp_client_send(int sock, const char* data);
bool tcp_client_receive(int sock, char* data, size_t max_len);