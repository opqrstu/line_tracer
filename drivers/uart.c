#include <line_tracer.h>
#include <common.h>
#include <uart.h>
#ifdef UART_DRIVER



int init_uart(void)
{
	UCSR1A = 0x00;
	UCSR1B = 0x88; //rx enable 0x98
	UCSR1C = 0x06;
	UBRR1H = 0x00;
	UBRR1L = 51;                // 9600 BR
}

static char rx_char(void) 
{
	while((UCSR1A&0x80) == 0);
	return UDR1; 
}

static void tx_char(char tx_data)
{
	while((UCSR1A&0x20) == 0);
	UDR1 = tx_data; 
}

static void tx_str(char* str)
{
	while(*str!='\0')
	{
		if(*str=='\n')
		tx_char('\r');
		tx_char(*str);
		str++;
	}
}


struct device_driver_t uart_driver =
{
    .name = "uart_driver",
    .init = init_uart,
	.write = tx_str
};

MODULE_INIT(uart_driver)
#endif /* UART_DRIVER */
