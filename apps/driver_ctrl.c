#include <line_tracer.h>
#include <common.h>
#include "uart_ctrl.h"
int probe_driver(struct device_driver_t** driver_ctrl , char* name)
{
	*driver_ctrl = -1;
	DEBUG("get_%s...", name);
	*driver_ctrl = get_device_driver(name, driver_list_head);
	if(*driver_ctrl == -1)
	{
		DEBUG("fail\n");
		return -1;
	}
	else
		DEBUG("OK\n");
		
	return 0;
}
