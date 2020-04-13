#include <line_tracer.h>
#include <common.h>
#define PWM
#ifdef MOTOR_DRIVER
int init_motor(void)
{
	MOTOR_L_DDR |= 1 << (MOTOR_L_PIN);
	MOTOR_L_EN |= 1 << (MOTOR_L_EN_PIN);
	MOTOR_L_PORT |= 1 << (MOTOR_L_EN_PIN);
	//PORTB |= 1 << (MOTOR_L_PIN);
	
	MOTOR_R_DDR |= 1 << (MOTOR_R_PIN);
	MOTOR_R_EN |= 1 << (MOTOR_R_EN_PIN);
	MOTOR_R_PORT |= 1 << (MOTOR_R_EN_PIN);
	//PORTE |= 1 << (MOTOR_R_PIN);

	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(0<<COM1B0)|(0<<COM1B0)|(0<<COM1C1)|(0<<COM1C0)|(1<<WGM11)|(0<<WGM10);
	TCCR1B = (0<<ICNC1)|(0<<ICES1) |(1<<WGM13)  |(1<<WGM12 )|(0<<CS12  )|(1<<CS11 )|(0<<CS10 );
	TCCR1C = 0x00;
	
	ICR1 = 8192;
	OCR1A  = ICR1*0.1;

	TCCR3A = (1<<COM3A1)|(0<<COM3A0)|(0<<COM3B0)|(0<<COM3B0)|(0<<COM3C1)|(0<<COM3C0)|(1<<WGM31)|(0<<WGM30);
	TCCR3B = (0<<ICNC3)|(0<<ICES3) |(1<<WGM33)  |(1<<WGM32 )|(0<<CS32  )|(1<<CS31 )|(0<<CS30 );
	TCCR3C = 0x00;

	ICR3 = 8192;
	OCR3A  = ICR3*0.1;

	TCNT1H = 0;
	TCNT1L = 0;
	TCNT3H = 0;
	TCNT3L = 0;
	return 0;
}

int write_motor(char speed, char op)
{
#ifdef PWM
	if(op == MOTOR_FORWARD)
	{
		OCR1A = ICR1*(speed*0.1);
		OCR3A = ICR3*(speed*0.1);
	}
#endif
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
