#include <line_tracer.h>
#include <common.h>
#include "apps/led_ctrl.h"

int main(void)
{
    int current_time = 0, past_time = 0;    int motor_test_flag = 0;
    SREG = 0x80;

    init_drivers(driver_list_head);

    struct device_driver_t* timer = -1;
    timer = get_device_driver("timer_driver", driver_list_head);
    if(timer == -1)
        return 0;

    while(1)
    {
        past_time = current_time;
        timer->read(&current_time, GET_SEC);

        if(current_time != past_time)
        {
            count_led();
            if(motor_test_flag == 0)
                motor_forward(MOTOR_SPEED50);
            else if(motor_test_flag == 1)
                motor_forward(MOTOR_SPEED70);
            else if(motor_test_flag == 2)
                motor_forward(MOTOR_SPEED100);
            else if(motor_test_flag == 3)
                motor_reverse(MOTOR_SPEED50);
            else if(motor_test_flag == 4)
                motor_reverse(MOTOR_SPEED70);
            else if(motor_test_flag == 5)
                motor_reverse(MOTOR_SPEED100);
            else if(motor_test_flag == 6)
                motor_left(MOTOR_SPEED50);
            else if(motor_test_flag == 7)
                motor_left(MOTOR_SPEED70);
            else if(motor_test_flag == 8)
                motor_left(MOTOR_SPEED100);
            else if(motor_test_flag == 9)
                motor_right(MOTOR_SPEED50);
            else if(motor_test_flag == 10)
                motor_right(MOTOR_SPEED70);
            else if(motor_test_flag == 11)
                motor_right(MOTOR_SPEED100);
            motor_test_flag ++;

            if(motor_test_flag == 12)
                motor_test_flag = 0;
        }
    }
#ifndef OS_ATMEGA
    print_driver_list(driver_list_head);
#endif
    clear_driver_list(driver_list_head);
}
