#ifndef MOTOR_CTRL_H_
#define MOTOR_CTRL_H_

int motor_forward(unsigned char speed);
int motor_reverse(unsigned char speed);
int motor_left(unsigned char speed);
int motor_right(unsigned char speed);

enum MOTOR_SPEED
{
	MOTOR_SPEED100 = 10,
	MOTOR_SPEED90 = 9,
	MOTOR_SPEED80 = 8,
	MOTOR_SPEED70 = 7,
	MOTOR_SPEED60 = 6,
	MOTOR_SPEED50 = 5,
	MOTOR_SPEED40 = 4,
	MOTOR_SPEED30 = 3,
	MOTOR_SPEED20 = 2,
	MOTOR_SPEED10 = 1,
	MOTOR_SPEED0 = 0
};



#endif /* MOTOR_CTRL_H_ */