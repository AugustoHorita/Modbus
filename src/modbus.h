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
#define buffer_s					256

extern unsigned short CRC16(unsigned char *nData, unsigned short wLength);
extern unsigned char *make_request(unsigned char dev_addr, unsigned short from,
		unsigned short to, unsigned char type);
extern unsigned char *make_read_request(unsigned char dev_addr,
		unsigned short from, unsigned short nr);
extern unsigned char *make_write_request(unsigned char dev_addr,
		unsigned short reg_addr, unsigned short reg_value);
extern int get_device(int fd, unsigned char dev_addr, unsigned short reg_addr,
		unsigned short reg_data, unsigned char *device_memorie);
extern unsigned char *fromFloat(float in);
extern float toFloat(unsigned char *in);

#endif /* MODBUS_H_ */
