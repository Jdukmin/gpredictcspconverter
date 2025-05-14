#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#include <csp/csp.h>
#include <csp/drivers/usart.h>
#include <gs/param/rparam.h>

#include "tcptrx.h"
#include "becrx.h"

pthread_t p_thread[5];

int main() {
    int ec = init_task(8, 4800);
    if(ec != CSP_ERR_NONE)
    {
        printf("Error whiel initializing.\n");
        return 0;
    }
    csp_route_print_interfaces();
    csp_route_print_table();
    bool runstate = true;
    pthread_create(&p_thread[0], NULL, start_tcp_server, &runstate);
    pthread_create(&p_thread[1], NULL, task_beacon, &runstate);
    pthread_create(&p_thread[2], NULL, task_rssi, &runstate);
    pthread_join(p_thread[0], NULL);
    pthread_join(p_thread[1], NULL);
    pthread_join(p_thread[2], NULL);
    return 0;
}