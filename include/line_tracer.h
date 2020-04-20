#define LED_DRIVER
#define TIMER_DRIVER
#define MOTOR_DRIVER
#define UART_DRIVER

#ifdef LED_DRIVER
#define LED_PORT PORTC
#define LED_DDR DDRC
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



