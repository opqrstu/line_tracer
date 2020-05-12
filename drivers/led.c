#include <line_tracer.h>
#include <common.h>

#ifdef LED_DRIVER
int init_led(void)
{
	int i;
	for(i = LED_PIN1; i<LED_MAX; i++)
	LED_DDR |= (1<<i);

	return 0;
}
int write_led(char pin, char op)
{
    op ? (LED_PORT |= pin) : (LED_PORT &= ~pin);

	return 0;
}


struct device_driver_t led_driver =
{
    .name = "led_driver",
    .init = init_led,
	.write = write_led
};

MODULE_INIT(led_driver)
#endif /* LED_DRIVER */
