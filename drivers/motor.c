#include <line_tracer.h>
#include <common.h>

#ifdef MOTOR_DRIVER

enum MOTOR_SELECT
{
    MOTOR_L1 = 0,
    MOTOR_L2,
    MOTOR_R1,
    MOTOR_R2
};
int init_motor(void)
{
#ifdef PC_PWM_MOTOR
	MOTOR_L_DDR |= (1<<MOTOR_L_EN_PIN) | (1<<MOTOR_L1_OUT_PIN) | (1<<MOTOR_L2_OUT_PIN);
	MOTOR_L_PORT |= (1<<MOTOR_L_EN_PIN);
	
	MOTOR_R_DDR |= (1<<MOTOR_R_EN_PIN) | (1<<MOTOR_R1_OUT_PIN) | (1<<MOTOR_R2_OUT_PIN);
	MOTOR_R_PORT |= (1<<MOTOR_R_EN_PIN);

	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(1<<COM1B1)|(0<<COM1B0)|(0<<COM1C1)|(0<<COM1C0)|(1<<WGM11)|(0<<WGM10);
	TCCR1B = (0<<ICNC1)|(0<<ICES1) |(1<<WGM13)  |(1<<WGM12 )|(0<<CS12  )|(1<<CS11 )|(0<<CS10 );
	TCCR1C = 0x00;
	
	ICR1 = 8192;
	
    OCR1A = ICR1*0.1;
    OCR1B = ICR1*0.1;



	TCCR3A = (1<<COM3A1)|(0<<COM3A0)|(1<<COM3B1)|(0<<COM3B0)|(0<<COM3C1)|(0<<COM3C0)|(1<<WGM31)|(0<<WGM30);
	TCCR3B = (0<<ICNC3)|(0<<ICES3) |(1<<WGM33)  |(1<<WGM32 )|(0<<CS32  )|(1<<CS31 )|(0<<CS30 );
	TCCR3C = 0x00;

	ICR3H = 8192 >> 8;
	ICR3L = 8192 & 0xff;

    unsigned int tmp_ICR3 = (ICR3H << 8) | (ICR3L & 0xff);
    tmp_ICR3 *= 0.1;
    
	OCR3AH = (tmp_ICR3 >> 8);
	OCR3AL = (tmp_ICR3 & 0xff);
	OCR3BH = (tmp_ICR3 >> 8);
	OCR3BL = (tmp_ICR3 & 0xff);

	TCNT1H = 0;
	TCNT1L = 0;
	TCNT3H = 0;
	TCNT3L = 0;
#endif
	return 0;
}

int write_motor(unsigned char motor_sel, unsigned char speed)
{
#ifdef PC_PWM_MOTOR
	if(motor_sel == MOTOR_L1)
	{
		OCR1A = ICR1*(speed*0.1);
	}
    else if(motor_sel == MOTOR_L2)
	{
		OCR1B = ICR1*(speed*0.1);
	}
	else if(motor_sel == MOTOR_R1)
    {
        unsigned int tmp_ICR3 = 8192;//(ICR3H << 8) | (ICR3L & 0xff);
        tmp_ICR3 *= 0.1*speed;

        OCR3AH = (tmp_ICR3 >> 8);
        OCR3AL = (tmp_ICR3 & 0xff);
    }
	else if(motor_sel == MOTOR_R2)
	{
        unsigned int tmp_ICR3 = 8192;//(ICR3H << 8) | (ICR3L & 0xff);
        tmp_ICR3 *= 0.1*speed;

        OCR3BH = (tmp_ICR3 >> 8);
        OCR3BL = (tmp_ICR3 & 0xff);
	}
    else
        return -1;
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
