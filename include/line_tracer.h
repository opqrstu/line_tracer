#define LED_DRIVER
#define TIMER_DRIVER
#define MOTOR_DRIVER
#define UART_DRIVER
#define BLUETOOTH_DRIVER
#define INFRARED_DRIVER
#define DEBUG_PRINT

#ifdef DEBUG_PRINT
#ifdef UART_DRIVER
#define debug_print(fmt,args...) write_uart(fmt ,##args)
#endif
#endif

#ifdef LED_DRIVER
#define LED_PORT PORTC
#define LED_DDR DDRC
enum
{
	LED_PIN1 = 0,
	LED_PIN2 = 1,
	LED_PIN3 = 2,
	LED_PIN4 = 3,
	LED_PIN5 = 4,
	LED_MAX	
};
#endif /* LED_DRIVER */

#ifdef MOTOR_DRIVER
#define MOTOR_L_DDR DDRB
#define MOTOR_R_DDR DDRE

#define MOTOR_L_EN_PIN 4
#define MOTOR_L1_OUT_PIN 5
#define MOTOR_L2_OUT_PIN 6

#define MOTOR_R_EN_PIN 2
#define MOTOR_R1_OUT_PIN 3
#define MOTOR_R2_OUT_PIN 4

#define MOTOR_L_PORT PORTB
#define MOTOR_R_PORT PORTE

#define PC_PWM_MOTOR
#endif

#ifdef INFRARED_DRIVER
#define INFRARED_DDR PORTA
#define INFRARED_PIN PINA
enum
{
	INFRARED_PIN1 = 0,
	INFRARED_PIN2,
	INFRARED_PIN3,
	INFRARED_MAX	
};
#endif



