#ifndef _TCPTRX_H_
#define _TCPTRX_H_

#define SERVER_PORT 4532
#define BUFFER_SIZE 1024

void handle_get_rx_freq(int socket);
void handle_set_rx_freq(int socket, const char* args);
void handle_get_tx_freq(int socket);
void handle_set_tx_freq(int socket, const char* args);
void handle_get_mode(int socket);
void handle_set_mode(int socket, const char* args);
void handle_set_ptt(int socket, const char* args);
void handle_get_ptt(int socket);
void route_command(int socket, const char* buffer);
void handle_client(int client_sock);
void* start_tcp_server(void* runstate);

#endif