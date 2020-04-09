#define LED_DRIVER

#ifdef LED_DRIVER
#ifdef OS_ATMEGA
#define LED_PORT PORTC
#define LED_DDR DDRC
#else
int tmp_ledport, tmp_ledddr;
#define LED_PORT tmp_ledport
#define LED_DDR tmp_ledddr
#endif
#endif

