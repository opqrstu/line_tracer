#include <line_tracer.h>
#include <common.h>


enum LED_CTRL
{
#ifdef LED_SOURCE_CURRENT
    LED_OFF = 0,
    LED_ON = 1,
#else
    LED_ON = 0,
    LED_OFF = 1,
#endif
};

static unsigned char led_count = 0;
int count_led()
{
	struct device_driver_t* led = -1;
	led = get_device_driver("led_driver", driver_list_head);
	if(led == -1)
		return -1;

	led_count++;

	if(led_count > 0x0f)
		led_count = 0;

    led->write(0xff, LED_OFF);
    led->write(led_count, LED_ON);

	return 0;
}
int on_led(char pin)
{
	struct device_driver_t* led = -1;
	led = get_device_driver("led_driver", driver_list_head);
	if(led == -1)
		return -1;
	
	led->write(1<<pin, LED_ON);
	return 0;
}
int off_led(char pin)
{
	struct device_driver_t* led = -1;
	led = get_device_driver("led_driver", driver_list_head);
	if(led == -1)
		return -1;
	led->write(1<<pin, LED_OFF);
	return 0;
}
