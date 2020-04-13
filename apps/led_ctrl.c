#include <line_tracer.h>
#include <common.h>


static unsigned char led_count = 0;
int count_led()
{
	led_count++;
	if(led_count > 0x0f)
		led_count = 0;
	LED_PORT = ~(led_count & 0x0f);
	
	return 0;
}
