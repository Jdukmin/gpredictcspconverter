#ifndef _BECRX_H_
#define _BECRX_H_
#include <inttypes.h>

int init_task(uint8_t address, uint32_t rxbaudrate);
int task_doppler_rx(uint32_t rxfreq);
int task_doppler_tx(uint32_t rxfreq);
void* task_rssi(void* runstate);
void* task_beacon(void* runstate);

#endif