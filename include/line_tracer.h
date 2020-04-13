#define LED_DRIVER
#define TIMER_DRIVER
#define MOTOR_DRIVER

#ifdef LED_DRIVER
#define LED_PORT PORTC
#define LED_DDR DDRC
#endif /* LED_DRIVER */

#ifdef MOTOR_DRIVER
#define MOTOR_L_EN DDRB
#define MOTOR_L_DDR DDRB

#define MOTOR_R_EN DDRE
#define MOTOR_R_DDR DDRE

#define MOTOR_L_EN_PIN 4
#define MOTOR_L_PIN 5

#define MOTOR_R_EN_PIN 4
#define MOTOR_R_PIN 5

#define MOTOR_L_PORT PORTB
#define MOTOR_R_PORT PORTE
#endif



