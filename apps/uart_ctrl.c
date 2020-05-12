/*
 * uart_ctrl.c
 *
 * Created: 2020-04-26 오후 4:53:58
 *  Author: woo
 */ 
#include <util/delay.h>
#include <stdlib.h>
#include <stdarg.h>
#include <common.h>

void write_uart(const char *format, ...) {
	struct device_driver_t* uart = -1;
	
	uart = get_device_driver("uart_driver", driver_list_head);
	if(uart==-1)
		return;
	va_list ap;
	char buf[256];
	va_start(ap, format);
	vsprintf(buf, format, ap);
	va_end(ap);
	uart->write(buf);
}