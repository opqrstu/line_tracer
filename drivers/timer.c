#include <line_tracer.h>
#include <common.h>

#ifdef TIMER_DRIVER

struct timer_datas_t
{
	int sec;
	int min;
};

static struct timer_datas_t timer_datas; 
static unsigned char tcnt0_count;

static int read_timer(int* value, char key)
{

	switch(key)
	{
		case GET_SEC:
			*value = timer_datas.sec;
			return 0;
			break;
		default:
			return -1;
	}
	
	return -1;
}

int init_timer(void)
{
	TIMSK |= 0x1;
	TCCR0 |= 0x7; // 주파수를 낮춤 1024 나눔
	TCNT0 = 0;
	timer_datas.sec = 0;
	return 0;
}

ISR(TIMER0_OVF_vect)
{
	if(tcnt0_count%30 == 0)
	{
		timer_datas.sec++;
		if(tcnt0_count >= 240)
			tcnt0_count = 0;
	}

	tcnt0_count++;
}

struct device_driver_t timer_driver =
{
	.name = "timer_driver",
	.init = init_timer,
	.read = read_timer
};

MODULE_INIT(timer_driver)
#endif /* TIMER_DRIVER */
