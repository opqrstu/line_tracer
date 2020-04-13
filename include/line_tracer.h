#define LED_DRIVER
#define TIMER_DRIVER
#define MOTOR_DRIVER

#ifdef LED_DRIVER
#ifdef OS_ATMEGA
#define LED_PORT PORTC
#define LED_DDR DDRC
#else
int tmp_ledport, tmp_ledddr;
#define LED_PORT tmp_ledport
#define LED_DDR tmp_ledddr
#endif /* OS_ATMEGA */
#endif /* LED_DRIVER */

#ifdef MOTOR_DRIVER
#define MOTOR_L_DDR DDRB
#define MOTOR_R_DDR DDRE

#define MOTOR_L_PIN 5
#define MOTOR_R_PIN 5
#if 0
#define MOTOR_L1_PORT PORTB
#define MOTOR_L2_PORT PORTB
#define MOTOR_R1_PORT PORTB
#define MOTOR_R2_PORT PORTB
#endif
#endif



