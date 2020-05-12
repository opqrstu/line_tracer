#include <line_tracer.h>
#include <common.h>
#include <uart.h>
			//if(bluetooth_test = blue->read())
			//write_uart("blue : %d\n",bluetooth_test);
#ifdef BLUETOOTH_DRIVER
static unsigned short rx_buf=0;
ISR(USART0_RX_vect)
{
	rx_buf = UDR0;
	/*
	rx_buf = 0;
	if(UDR0 == 'a')
	rx_buf='a';
	if(UDR0 == 'w')
	rx_buf='w';
	if(UDR0 == 'd')
	rx_buf='d';
	if(UDR0 == 's')
	rx_buf='s';*/
}

int init_bluetooth(void)
{
	UCSR0A = 0x00;
	UCSR0B = 0x98; //rx enable 0x98
	UCSR0C = 0x06;
	UBRR0H = 0x00;
	UBRR0L = 51;                // 9600 BR
}

static char rx_char(void)
{
	while((UCSR0A&0x80) == 0);
	return UDR0;
}
static char rx_intterupt(void)
{
	if(rx_buf)
	{
		unsigned char tmp_buf = rx_buf;
		rx_buf = 0;
		return tmp_buf;
	}
	
	return 0;
}

static void tx_char(char tx_data)
{
	while((UCSR0A&0x20) == 0);
	UDR0 = tx_data;
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

struct device_driver_t bluetooth_driver =
{
	.name = "bluetooth_driver",
	.init = init_bluetooth,
	.write = tx_str,
	.read = rx_intterupt
};

MODULE_INIT(bluetooth_driver)
#endif /* BLUETOOTH_DRIVER */
