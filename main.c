#include "include/line_tracer.h"
#include "include/common.h"
#include "drivers/list.h"



int main(void)
{
    init_drivers(driver_list_head);
    print_driver_list(driver_list_head);
    clear_driver_list(driver_list_head);
}
