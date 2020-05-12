/*
 * uart.h
 *
 * Created: 2020-04-26 오후 2:08:13
 *  Author: woo
 */ 


#ifndef UART_H_
#define UART_H_

#define UART_REG    0x9B

enum
{
	DATA_5BIT,
	DATA_6BIT,
	DATA_7BIT,
	DATA_8BIT
};
#define CHAR_SZ_SHIFT   1

#define BAUD_2400   2400
#define BAUD_4800   4800
#define BAUD_9600   9600
#define BAUD_14400  14400
#define BAUD_19200  19200
#define BAUD_28800  28800
#define BAUD_38400  38400
#define BAUD_57600  57600
#define BAUD_115200 115200


#define UART_BAUDRATE   BAUD_4800
struct uart
{
	uint8_t     ucsr_a;
	uint8_t     ucsr_b;
	uint8_t     ucsr_c;
	uint8_t     reserved;
	uint8_t     ubrr_l;
	uint8_t     ubrr_h;
	uint8_t     udr;
};


#endif /* UART_H_ */