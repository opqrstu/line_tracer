#include <line_tracer.h>
#include <common.h>

#ifdef MOTOR_DRIVER
int init_motor(void)
{
	MOTOR_L_DDR = 1 << (MOTOR_L_PIN-1);
	MOTOR_R_DDR = 1 << (MOTOR_R_PIN-1);

	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(0<<COM1B0)|(0<<COM1B0)|(0<<COM1C1)|(0<<COM1C0)|(1<<WGM11)|(0<<WGM10);
	TCCR1B = (0<<ICNC1)|(0<<ICES1) |(1<<WGM13)  |(1<<WGM12 )|(0<<CS12  )|(1<<CS11 )|(0<<CS10 );
	TCCR1C = 0x00;
	
	ICR1 = 8192;        
	OCR1A  = ICR1*0.1; 
	return 0;
}

int write_motor(char speed, char op)
{
	if(op == MOTOR_FORWARD)
		switch(speed)
		{
			OCR1A = ICR1*(speed*0.1);
		}
	return 0;
}

struct device_driver_t motor_driver =
{
	.name = "motor_driver",
	.init = init_motor,
	.write = write_motor
};

MODULE_INIT(motor_driver)
#endif /* MOTOR_DRIVER */
