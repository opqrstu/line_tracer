/*
* blue_ctrl.c
*
* Created: 2020-05-09 오후 8:08:09
*  Author: woo
*/
#include <util/delay.h>
#include <stdlib.h>
#include <stdarg.h>
#include <common.h>

void write_blue(const char *format, ...) {
	struct device_driver_t* blue = -1;
	
	blue = get_device_driver("bluetooth_driver", driver_list_head);
	if(blue==-1)
		return;
	va_list ap;
	char buf[256];
	va_start(ap, format);
	vsprintf(buf, format, ap);
	va_end(ap);
	blue->write(buf);
}