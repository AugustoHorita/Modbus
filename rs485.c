/*
 * rs485.c
 *
 *  Created on: 27/11/2014
 *      Author: cuki
 */

#include <18F45K20.h>

#fuses HS

#use delay(clock=10MHz)
#use rs232(xmit=PIN_C6, rcv=PIN_c7, enable=PIN_C5, baud=19200)

#include "modbus.c"

//int cont[8] = { 0x03, 0x03, 0x00, 0x00, 0x00, 0x0A, 0xC4, 0x2F };
//int request[8];
int *request;

int main(void) {

	int i;

	request = make_read_request(1, 0, 10);

	while (TRUE) {

		delay_ms(1000);

		send_request(request);
	}

	return 0;
}
