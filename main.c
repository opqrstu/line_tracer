#include <line_tracer.h>
#include <common.h>
#include "apps/led_ctrl.h"
#include "apps/motor_ctrl.h"
#include "apps/uart_ctrl.h"
#include "apps/blue_ctrl.h"

#include <qmc5883l.h>
#include <i2cmaster.h>
int main(void)
{
	int current_time = 0, past_time = 0;
	unsigned char infrared_flag;
	unsigned char move_stack[20], input_buf;
	int stack_count = 0;
	
	int16_t mx,my,mz;
	float hdg;
	
	init_drivers(driver_list_head);
	
	SREG = 0x80;

	DEBUG("\n\ninit_drivers...OK\n");
	
	struct device_driver_t* timer;
	probe_driver(&timer, "timer_driver");
	
	struct device_driver_t* blue;
	probe_driver(&blue, "bluetooth_driver");

	struct device_driver_t* infred;
	probe_driver(&infred, "infrared_driver");

	i2c_init();
	qmc5883l_init();
	sei();
	
	DEBUG("\nstart loop\n\n");
	while(1)
    {
        /* get a time */
        past_time = current_time;
        timer->read(&current_time, GET_SEC);

        /* get bluetooth read datas */
        if(input_buf = blue->read())
        {
            if(stack_count >= 20)
            {
                stack_count = 0;
            
            }
            DEBUG("input_data : %c\n",input_buf);
            move_stack[stack_count++] = input_buf;
        }

        /* operate once a second */
        if(current_time != past_time)
        {
            count_led();
            if(move_stack[stack_count-1] == 13)
            {
                move_stack[stack_count] = 0;
                write_uart("%s\n",move_stack);
                stack_count = 0;
            }

            /* get xyz */
            qmc5883l_getrawdata(&mx,&my,&mz);
            hdg = qmc5883l_calc_heading(mx,my);

            DEBUG("QMC5883L heading=%3d degr mx=%d my=%d mz=%d  \n", (int16_t)hdg,mx,my,mz);

        }

#if 0		
        /* check infrared leds */
		infrared_flag = 0;
		infred->read(&infrared_flag);
		if(infrared_flag != 0)
		{
			if(infrared_flag & (1<<INFRARED_PIN1))
			{
				DEBUG("on\n");
				on_led(LED_PIN4);	
			}
			else
				off_led(LED_PIN4);
		}
#endif

	}

	clear_driver_list(driver_list_head);
    return 0;
}
