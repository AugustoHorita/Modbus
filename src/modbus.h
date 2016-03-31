/*
 * modbus.h
 *
 *  Created on: 03/12/2014
 *      Author: cuki
 */

#ifndef MODBUS_H_
#define MODBUS_H_

#define READ_COILS					0x01
#define READ_DISCRETE_INPUTS		0x02
#define READ_HOLDING_REGISTERS		0x03
#define READ_INPUT_REGISTERS		0x04
#define WRITE_SINGLE_COIL			0x05
#define WRITE_SINGLE_REGISTER		0x06
#define WRITE_MULTIPLE_COILS		0x0F
#define WRITE_MULTIPLE_REGISTERS	0x10

#define HIGH						1
#define LOW							0
#define REQUEST_SIZE				8
#define BUFFER_S					256

extern const unsigned short wCRCTable[];
extern unsigned char makeByte(unsigned short word, unsigned char index);
extern unsigned short makeWord(unsigned char hiByte, unsigned char loByte);
extern unsigned short troca(unsigned short in);
extern unsigned short CRC16(unsigned char *nData, unsigned short wLength);
extern unsigned char *make_request(unsigned char dev_addr, unsigned short from,
		unsigned short to, unsigned char type);
extern unsigned char *make_read_request(unsigned char dev_addr,
		unsigned short from, unsigned short nr);
extern unsigned char *make_write_request(unsigned char dev_addr,
		unsigned short reg_addr, unsigned short reg_value);
extern unsigned char *make_discrete_inputs_request(unsigned char dev_addr,
		unsigned short reg_addr, unsigned short reg_value);
extern unsigned char *make_read_coils_request(unsigned char dev_addr,
		unsigned short reg_addr, unsigned short reg_value);
extern int get_device(int fd, unsigned char dev_addr, unsigned short reg_addr,
		unsigned short reg_data, unsigned char *device_memorie);
extern unsigned char *fromFloat(float in);
extern float toFloat(unsigned char *in);

#endif /* MODBUS_H_ */
