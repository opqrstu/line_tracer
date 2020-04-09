//#include <avr/io.h>
#include "include/line_tracer.h"
#include "include/common.h"
#include "drivers/list.h"



int main(void)
{
    struct device_driver_t *f;
    init_driver_list(&driver_list_head);

    struct device_driver_t d =
    {
        .name = "driver1",
        .b = 30
    };
    struct device_driver_t e =
    {
        .name = "driver2",
        .b = 55
    };

    add_driver_list(e, driver_list_head);
    add_driver_list(d, driver_list_head);

    f = get_device_driver("driver2", driver_list_head);
    if(f)
        printf("%d\n",f->b);

    print_driver_list(driver_list_head);
    clear_driver_list(driver_list_head);
    
}
