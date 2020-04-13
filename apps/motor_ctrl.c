#include <line_tracer.h>
#include <common.h>

static unsigned char motor_speed = MOTOR_SPEED0;
static char flag = 0;
int speed_test_motor()
{
	struct device_driver_t* motor = -1;
	motor = get_device_driver("motor_driver", driver_list_head);
	if(motor == -1)
		return -1;
	
	if(motor_speed == MOTOR_SPEED100)
		flag = 1;
	if(motor_speed == MOTOR_SPEED0)
		flag = 0;
	if(flag)
		motor_speed --;
	else
		motor_speed ++;
		
	motor->write(motor_speed,MOTOR_FORWARD);
	
	return 0;
}
