#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <stdlib.h>
#include "serial.h"
#include "modbus.h"

int open_port(char *porta) {
	int fd;

	fd = open(porta, O_RDWR | O_NOCTTY | O_NDELAY);

	return fd;
}

int set_port(int baud_rate, int fd) {
	struct termios options;
	speed_t speed;

	switch (baud_rate) {
	default:
	case 9600:
		speed = B9600;
		break;
	case 19200:
		speed = B19200;
		break;
	case 57600:
		speed = B57600;
		break;
	case 115200:
		speed = B115200;
		break;
	}

	tcgetattr(fd, &options);
	cfsetispeed(&options, speed);
	cfsetospeed(&options, speed);

	options.c_cflag |= (CLOCAL | CREAD);
	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	options.c_cflag &= ~CRTSCTS;
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	options.c_oflag &= ~OPOST;
	options.c_iflag &= ~(IXON | IXOFF | IXANY);

	tcsetattr(fd, TCSANOW, &options);

	return 0;
}

int make_transaction(int fd, uint8_t *msg, uint8_t *resp, int count) {
	int n = -1;

	tcflush(fd, TCIFLUSH);
	write(fd, msg, count);
	usleep(300000);
	n = read(fd, resp, count);

	return n;
}

bool check_response(uint8_t *response, uint8_t *request) {
	bool check = true;
	int cont;

	for (cont = 0; cont < 8; ++cont) {
		if (cont == 5)
			check &= response[cont] == 0x00;
		else
			check &= response[cont] == request[cont];
	}

	return check;
}

int clear_response(uint8_t *response, int size) {
	int cont;

	for (cont = 0; cont < size; ++cont)
		response[cont] = 0;

	return 0;
}

int make_read_transaction(int fd, int dev_addr, uint8_t *response, int from,
		int count) {
	int n = -1;
	uint8_t *request;

	request = (uint8_t *) malloc(REQUEST_SIZE);

	clear_response(response, count);
	make_read_request(dev_addr, from, count);
	n = make_transaction(fd, request, response, count);

	free(request);

	if (n != count) {
		return -1;
	} else if (!check_response(response, request))
		return -2;

	return n;
}
