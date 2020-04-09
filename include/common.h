#define OS_ATMEGA
#ifdef OS_ATMEGA
#include <avr/io.h>
#endif

struct device_driver_t
{
    char name[20];
    int (*init)();
    int b;
};

extern struct driver_list_node_t *driver_list_head;

#define MODULE_INIT(name) \
    __attribute__((constructor)) void module_init_##name(void) \
    { \
        if (driver_list_head == 0) \
            init_driver_head(&driver_list_head); \
        add_driver_list(name, driver_list_head); \
    }

