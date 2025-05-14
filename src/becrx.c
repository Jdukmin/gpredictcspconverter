#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <csp/csp.h>
#include <csp/drivers/usart.h>
#include <gs/param/rparam.h>

#include "becrx.h"

csp_iface_t* ifc = NULL;
csp_conf_t conf;

int init_task(uint8_t address, uint32_t rxbaudrate) {
    int ec = CSP_ERR_NONE;
    csp_conf_get_defaults(&conf);
    conf.address = address;
    ec = csp_init(&conf);
    if(ec != CSP_ERR_NONE)
    {
        printf("CSP initialize failed.\n");
    }
    csp_route_start_task(500, 0);
    csp_usart_conf_t conf = {
        .device = "/dev/GS102",
        .baudrate = 500000, /* supported on all platforms */
        .databits = 8,
        .stopbits = 1,
        .paritysetting = 0,
        .checkparity = 0};
    ec = csp_usart_open_and_add_kiss_interface(&conf, CSP_IF_KISS_DEFAULT_NAME,  &ifc);
    if (ec != CSP_ERR_NONE) {
        printf("Cannot Add KISS Interface.\n");
    }
    csp_rtable_set(20, 5, ifc, CSP_NO_VIA_ADDRESS);
    usleep(1*1000*1000);
    gs_rparam_set_uint32(20, 1, 0x0004, GS_RPARAM_MAGIC_CHECKSUM, 100, rxbaudrate);
    printf("RX Baudrate : %u\n", rxbaudrate);
    return ec;
}

int task_doppler_rx(uint32_t rxfreq) {
    return gs_rparam_set_uint32(20, 1, 0x0000, GS_RPARAM_MAGIC_CHECKSUM, 100, rxfreq);
}

int task_doppler_tx(uint32_t rxfreq) {
    return gs_rparam_set_uint32(20, 5, 0x0000, GS_RPARAM_MAGIC_CHECKSUM, 100, rxfreq);
}

void* task_rssi(void* runstate) {
    int16_t res = 0;
    int ec = 0;
    while (1) {
        
        usleep(5*1000*1000);    
        int ec = gs_rparam_get_int16(20, 4, 0x0004, GS_RPARAM_MAGIC_CHECKSUM, 100, &res);
        if(ec != GS_OK)
        {
            printf("Cannot read RSSI value.\n");
            continue;
        }
        printf("RSSI : %hddBm\n", res);
        
    }
}

/* Server task - handles requests from clients */
void* task_beacon(void* runstate) {

	csp_log_info("Server task started");

	/* Create socket with no specific socket options, e.g. accepts CRC32, HMAC, XTEA, etc. if enabled during compilation */
	csp_socket_t *sock = csp_socket(CSP_SO_NONE);

	/* Bind socket to all ports, e.g. all incoming connections will be handled here */
	csp_bind(sock, CSP_ANY);

	/* Create a backlog of 10 connections, i.e. up to 10 new connections can be queued */
	csp_listen(sock, 10);

	/* Wait for connections and then process packets on the connection */
	while (1) {

		/* Wait for a new connection, 10000 mS timeout */
		csp_conn_t *conn;
		if ((conn = csp_accept(sock, 10000)) == NULL) {
			/* timeout */
			continue;
		}

		/* Read packets on connection, timout is 100 mS */
		csp_packet_t *packet;
		while ((packet = csp_read(conn, 50)) != NULL) {
            csp_log_info("Packet received on port %d", csp_conn_dport(conn));
            for(int i = 0; i < packet->length; i++)
            {
                printf("%02hhx ", packet->data[i]);
                if(i % 10 == 0)
                    printf("\n");
            }
            csp_buffer_free(packet);
            // ++server_received;
            break;
		}

		/* Close current connection */
		csp_close(conn);

	}

	return NULL;

}