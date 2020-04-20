#include <line_tracer.h>
#include <common.h>

enum MOTOR_SEL
{
    MOTOR_L1 = 0,
    MOTOR_L2,
    MOTOR_R1,
    MOTOR_R2
};



int motor_forward(unsigned char speed)
{
	struct device_driver_t* motor = -1;
	motor = get_device_driver("motor_driver", driver_list_head);
	if(motor == -1)
		return -1;
	
    motor->write(MOTOR_L1, speed);
	motor->write(MOTOR_L2, 0);
    motor->write(MOTOR_R1, speed);
	motor->write(MOTOR_R2, 0);
	
	return 0;
}

int motor_reverse(unsigned char speed)
{
	struct device_driver_t* motor = -1;
	motor = get_device_driver("motor_driver", driver_list_head);
	if(motor == -1)
		return -1;
	
    motor->write(MOTOR_L1, 0);
	motor->write(MOTOR_L2, speed);
    motor->write(MOTOR_R1, 0);
	motor->write(MOTOR_R2, speed);
	
	return 0;
}

int motor_left(unsigned char speed)
{
	struct device_driver_t* motor = -1;
	motor = get_device_driver("motor_driver", driver_list_head);
	if(motor == -1)
		return -1;
	
    motor->write(MOTOR_L1, speed);
	motor->write(MOTOR_L2, 0);
    motor->write(MOTOR_R1, 0);
	motor->write(MOTOR_R2, speed);
	
	return 0;
}

int motor_right(unsigned char speed)
{
	struct device_driver_t* motor = -1;
	motor = get_device_driver("motor_driver", driver_list_head);
	if(motor == -1)
		return -1;
	
    motor->write(MOTOR_L1, 0);
	motor->write(MOTOR_L2, speed);
    motor->write(MOTOR_R1, speed);
	motor->write(MOTOR_R2, 0);
	
	return 0;
}


