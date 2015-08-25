/*
 * modbus.h
 *
 *  Created on: 03/12/2014
 *      Author: cuki
 */

#ifndef MODBUS_H_
#define MODBUS_H_

#define read_coils					0x01
#define read_discrete_inputs		0x02
#define read_holding_registers		0x03
#define read_input_registers		0x04
#define write_single_coil			0x05
#define write_single_register		0x06
#define write_multiple_coils		0x0F
#define Write_multiple_registers	0x10

#define high						1
#define low							0
#define request_size				8

unsigned short CRC16(unsigned char *nData, unsigned short wLength);
unsigned char *make_read_request(unsigned char dev_addr, unsigned short from,
		unsigned short to);
unsigned char send_request(unsigned char *output);

#endif /* MODBUS_H_ */
