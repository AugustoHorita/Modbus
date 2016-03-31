/*
 * serial.h
 *
 *  Created on: 07/07/2015
 *      Author: cuki
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdbool.h>
#include <stdint.h>

extern int open_port(char *porta);
extern int set_port(int baud_rate, int fd);
extern int make_transaction(int fd, uint8_t *msg, uint8_t *resp, int count);
extern bool check_response(uint8_t *response, uint8_t *request);
extern int make_read_transaction(int fd, int dev_addr, uint8_t *response,
		int from, int count);

#endif /* SERIAL_H_ */
