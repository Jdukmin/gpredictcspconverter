#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include "tcptrx.h"
#include "becrx.h"

// 현재 상태를 저장할 구조체
typedef struct {
    double rx_freq; // 수신 주파수
    double tx_freq; // 송신 주파수
    char mode[16];
    int ptt;
} RigState;

RigState rig = {
    .rx_freq = 436500000,
    .tx_freq = 436500000,
    .mode = "USB",
    .ptt = 0
};
// 명령 핸들러 함수들
void handle_get_rx_freq(int socket) {
    char response[64];
    snprintf(response, sizeof(response), "%.0f\n", rig.rx_freq);
    send(socket, response, strlen(response), 0);
}

void handle_set_rx_freq(int socket, const char* args) {
    double freq;
    if (sscanf(args, "%lf", &freq) == 1) {
        rig.rx_freq = freq;
        printf("Set RX frequency to %u Hz\n", (uint32_t)rig.rx_freq);
        if(task_doppler_rx((uint32_t)freq) == 0)
        {
            send(socket, "RPRT 0\n", 7, 0);  // 정상 응답
            return;
        }
        else
        {
            printf("Rparam Error.\n");
            return;
        }
    }
    fprintf(stderr, "Invalid RX freq format: %s\n", args);
    send(socket, "RPRT -1\n", 8, 0); // 오류 응답
}

void handle_get_tx_freq(int socket) {
    char response[64];
    snprintf(response, sizeof(response), "%.0f\n", rig.tx_freq);
    send(socket, response, strlen(response), 0);
}

void handle_set_tx_freq(int socket, const char* args) {
    double freq;
    if (sscanf(args, "%lf", &freq) == 1) {
        rig.tx_freq = freq;
        printf("Set TX frequency to %u Hz\n", (uint32_t)rig.tx_freq);
        if(task_doppler_tx((uint32_t)freq) == 0)
        {
            send(socket, "RPRT 0\n", 7, 0);  // 정상 응답
            return;
        }
        else
        {
            printf("Rparam Error.\n");
            return;
        }
    } else {
        fprintf(stderr, "Invalid TX freq format: %s\n", args);
        send(socket, "RPRT -1\n", 8, 0);
    }
}

void handle_get_mode(int socket) {
    char response[64];
    snprintf(response, sizeof(response), "%s 2400\n", rig.mode);  // 2400은 예시 필터 폭
    send(socket, response, strlen(response), 0);
}


void handle_set_mode(int socket, const char* args) {
    char mode[16];
    int width;
    if (sscanf(args, "%15s %d", mode, &width) == 2) {
        strncpy(rig.mode, mode, sizeof(rig.mode));
        rig.mode[sizeof(rig.mode) - 1] = '\0';
        printf("Set mode to %s with width %d\n", rig.mode, width);
        send(socket, "RPRT 0\n", 7, 0);
    } else {
        fprintf(stderr, "Invalid mode format: %s\n", args);
        send(socket, "RPRT -1\n", 8, 0);
    }
}

void handle_set_ptt(int socket, const char* args) {
    int state;
    if (sscanf(args, "%d", &state) == 1) {
        rig.ptt = state;
        printf("Set PTT to %d\n", state);
        send(socket, "RPRT 0\n", 7, 0);
    } else {
        fprintf(stderr, "Invalid PTT format: %s\n", args);
        send(socket, "RPRT -1\n", 8, 0);
    }
}

void handle_get_ptt(int socket) {
    char response[8];
    snprintf(response, sizeof(response), "%d\n", rig.ptt);
    send(socket, response, strlen(response), 0);
}

// 명령 라우팅
void route_command(int socket, const char* buffer) {
    char command = buffer[0];
    const char* args = buffer + 1;

    while (*args == ' ') args++;  // 공백 스킵

    switch (command) {
        case 'f':
            handle_get_rx_freq(socket);
            break;
        case 'F':
            handle_set_rx_freq(socket, args);
            break;
        case 'r':
            handle_get_tx_freq(socket);
            break;
        case 'R':
            handle_set_tx_freq(socket, args);
            break;
        case 'm':
            handle_get_mode(socket);
            break;
        case 'M':
            handle_set_mode(socket, args);
            break;
        case 't':
            handle_get_ptt(socket);
            break;
        case 'T':
            handle_set_ptt(socket, args);
            break;
        case 'q':
            printf("Quit command received. Closing connection.\n");
            close(socket);
            return;
        case 'S':
            // 예시: VFO 명령 무시
            printf("VFO command received (ignored): %s\n", args);
            break;
        
        default:
            printf("Unknown command: %c\n", command);
            break;
    }
}

// 명령 라인 수신 및 처리
void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int buf_len = 0;
    while (1) {
        int valread = read(client_sock, buffer + buf_len, BUFFER_SIZE - buf_len - 1);
        if (valread <= 0) {
            printf("Client disconnected or read error.\n");
            break;
        }

        buf_len += valread;
        buffer[buf_len] = '\0';

        // 명령 줄바꿈 처리: \n으로 구분하여 명령 처리
        char *line;
        while ((line = strchr(buffer, '\n')) != NULL) {
            *line = '\0'; // \n을 NULL로 변환하여 명령 분리
            // printf("Received: %s\n", buffer);
            route_command(client_sock, buffer);

            // 나머지 데이터 이동
            int remaining = buf_len - (line - buffer + 1);
            memmove(buffer, line + 1, remaining);
            buf_len = remaining;
            buffer[buf_len] = '\0';  // 남은 데이터에 null terminator 추가
        }
        usleep(500);
    }
    // close(client_sock);  // 클라이언트 연결 종료
}

// 서버 시작
void* start_tcp_server(void* runstate) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // 소켓 생성
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // 포트 재사용 허용
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);

    // 바인드
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // 리슨
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections on port %d...\n", SERVER_PORT);

    // 클라이언트 연결 대기
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Connected to client\n");
        handle_client(new_socket);
    }

    close(server_fd);
    return NULL;
}