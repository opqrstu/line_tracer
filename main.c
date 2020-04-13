#include <line_tracer.h>
#include <common.h>
#include "apps/led_ctrl.h"

int main(void)
{
	int current_time = 0, past_time = 0;
	SREG = 0x80;
	
	init_drivers(driver_list_head);

	struct device_driver_t* timer = -1;
	timer = get_device_driver("timer_driver", driver_list_head);
	if(timer == -1)
		return 0;

	while(1)
	{
		past_time = current_time;
		timer->read(&current_time, GET_SEC);
		if(current_time != past_time)
		{
			count_led();
		}
	}
#ifndef OS_ATMEGA
	print_driver_list(driver_list_head);
#endif
	clear_driver_list(driver_list_head);
}
