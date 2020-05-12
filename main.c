#include <line_tracer.h>
#include <common.h>
#include "apps/led_ctrl.h"
#include "apps/motor_ctrl.h"
#include "apps/uart_ctrl.h"
#include "apps/blue_ctrl.h"

int main(void)
{
	int current_time = 0, past_time = 0, bluetooth_test = 0;
	unsigned char infrared_flag;
	unsigned char move_stack[20];
	int stack_count = 0;
	SREG = 0x80;

	init_drivers(driver_list_head);
	write_uart("\n\ninit_driver...OK\n");
	
	struct device_driver_t* timer;
	probe_driver(&timer, "timer_driver");
	
	struct device_driver_t* blue;
	probe_driver(&blue, "bluetooth_driver");

	struct device_driver_t* infred;
	probe_driver(&infred, "infrared_driver");
	
	write_uart("\nstart loop\n\n");
	while(1)
	{
		past_time = current_time;
		timer->read(&current_time, GET_SEC);
					if(bluetooth_test = blue->read())
					{
						write_uart("blue : %d\n",bluetooth_test);
						write_blue("blue : %d\n",bluetooth_test);
						move_stack[stack_count++] = bluetooth_test;
					}
		if(current_time != past_time)
		{
			count_led();
			if(move_stack[stack_count-1] == 13)
			{
				move_stack[stack_count] = 0;
				write_uart("%s\n",move_stack);
				stack_count = 0;
				bluetooth_test = 0;
			}
			
		}
		
		infrared_flag = 0;
		infred->read(&infrared_flag);
		if(infrared_flag != 0)
		{
			if(infrared_flag & (1<<INFRARED_PIN1))
			{
				write_uart("on\n");
				on_led(LED_PIN4);	
			}
			else
				off_led(LED_PIN4);
		}
	}
	#ifndef OS_ATMEGA
	print_driver_list(driver_list_head);
	#endif
	clear_driver_list(driver_list_head);
}
