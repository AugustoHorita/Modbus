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

#define high	1
#define low		0

long CRC16(const int *nData, long wLength);
int toInt(long in, short side);
int *make_read_request(int dev_addr, long from, long to);

#endif /* MODBUS_H_ */
