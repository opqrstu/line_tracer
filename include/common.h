#define OS_ATMEGA
#ifdef OS_ATMEGA
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#endif

#ifdef TIMER_DRIVER
#include <timer.h>
#endif
#ifdef MOTOR_DRIVER
#include <motor.h>
#endif

struct device_driver_t
{
    char name[20];
    int (*init)();
	int (*read)();
	int (*write)();
    void* device_datas;
};

extern struct driver_list_node_t *driver_list_head;

#define MODULE_INIT(name) \
    __attribute__((constructor)) void module_init_##name(void) \
    { \
        if (driver_list_head == 0) \
            init_driver_head(&driver_list_head); \
        add_driver_list(name, driver_list_head); \
    }

#include <list.h>