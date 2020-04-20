#include <line_tracer.h>
#include <common.h>

#ifdef UART_DRIVER

#define UART_REG 0xC0 

struct uart 
{ 
    uint8_t ucsr_a; 
    uint8_t ucsr_b; 
    uint8_t ucsr_c; 
    uint8_t reserved; 
    uint8_t ubrr_l; 
    uint8_t ubrr_h; 
    uint8_t udr; 
}; 

volatile struct uart *const uart = (void*)UART_REG;

int init_uart(void)
{

    uint16_t baudrate = F_CPU/UART_BAUDRATE/16 - 1;

    uart->ucsr_b = 0x00;
    uart->ucsr_a = 0x00;
    uart->ucsr_c = DATA_8BIT << CHAR_SZ_SHIFT; // 8,N,1
    uart->ubrr_h = (baudrate >> 8) & 0xFF;
    uart->ubrr_l = baudrate & 0xFF;
    uart->ucsr_b = (RXEN | TXEN);

	return 0;
}
int write_uart(uint8_t data)
{
    if (data == '\n')
        uart_tx('\r');
 
    while (!(uart->ucsr_a & UDRE));
    uart->udr = data;

	return 0;
}

struct device_driver_t uart_driver =
{
    .name = "uart_driver",
    .init = init_uart,
	.write = write_uart
};

MODULE_INIT(uart_driver)
#endif /* UART_DRIVER */
