#include <line_tracer.h>
#include <common.h>

#ifdef INFRARED_DRIVER
int init_infrared(void)
{
	int i;
	for(i = INFRARED_PIN1; i<INFRARED_MAX; i++)
		INFRARED_DDR &= ~(1<<i);

	return 0;
}
int read_infrared(unsigned char *flag)
{
	int i;
	unsigned char ret = 0;
	for(i = INFRARED_PIN1; i<INFRARED_MAX; i++)
	{
		if((INFRARED_PIN & (1<<i)) == 0) // a black line is detected
		{
			ret |= (1<<i);	
		}
	}
	*flag = ret;
	
	return 0;
}


struct device_driver_t infrared_driver =
{
	.name = "infrared_driver",
	.init = init_infrared,
	.read = read_infrared
};

MODULE_INIT(infrared_driver)
#endif /* INFRARED_DRIVER */
