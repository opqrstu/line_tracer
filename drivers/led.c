#include <line_tracer.h>
#include <common.h>

#ifdef LED_DRIVER
int init_led(void)
{
    LED_DDR = 0xff;
	return 0;
}

int write_led(char pin, char op)
{
    switch(pin)
    {
        case 1:
            op ? (LED_PORT |= 0x01) : (LED_PORT &= ~0x01);
            break;
        case 2:
            op ? (LED_PORT |= 0x02) : (LED_PORT &= ~0x02);
            break;
        case 3:
            op ? (LED_PORT |= 0x04) : (LED_PORT &= ~0x04);
            break;
        case 4:
            op ? (LED_PORT |= 0x08) : (LED_PORT &= ~0x08);
            break;
        case 5:
            op ? (LED_PORT |= 0x10) : (LED_PORT &= ~0x10);
            break;
        case 6:
            op ? (LED_PORT |= 0x20) : (LED_PORT &= ~0x20);
            break;
        case 7:
            op ? (LED_PORT |= 0x40) : (LED_PORT &= ~0x40);
            break;
        case 8:
            op ? (LED_PORT |= 0x80) : (LED_PORT &= ~0x80);
            break;
    }
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
