#include <common.h>

struct driver_list_node_t
{
    struct device_driver_t driver;
    struct driver_list_node_t *next;
};

struct driver_list_node_t *driver_list_head = 0;

int init_driver_head(struct driver_list_node_t** head)
{
    *head = 0;
    *head = malloc(sizeof(struct driver_list_node_t));
    if(*head)
        (*head)->next = 0;
    return (int)*head;
}

int clear_driver_list(struct driver_list_node_t* head)
{
    struct driver_list_node_t* tmp_node = head;
    struct driver_list_node_t* tmp_node_next = head->next;

    while(tmp_node)
    {
        free(tmp_node);
        tmp_node = 0;

        if(tmp_node_next)
        {
            tmp_node = tmp_node_next;
            tmp_node_next = tmp_node_next->next;
        }
    }
}

int add_driver_list(struct device_driver_t driver, struct driver_list_node_t* head)
{
    struct driver_list_node_t* tmp_node = 0;

    for(tmp_node = head; tmp_node; tmp_node = tmp_node->next)
    {
        if(tmp_node->next == 0)
            break;
    }
    tmp_node->next = malloc(sizeof(struct driver_list_node_t));
    tmp_node->next->driver = driver;
    tmp_node->next->next = 0;

    return 0;
}

#ifndef OS_ATMEGA
int print_driver_list(struct driver_list_node_t *head)
{
    struct driver_list_node_t* tmp_node = 0;

    for(tmp_node = head->next; tmp_node; tmp_node = tmp_node->next)
        printf("%d\n",tmp_node->driver.b);

    return 0;
}
#endif

struct device_driver_t* get_device_driver(char* index, struct driver_list_node_t* head)
{
    struct driver_list_node_t* tmp_node = 0;
    
    for(tmp_node = head; tmp_node;tmp_node = tmp_node->next)
    {
        if(strcmp(tmp_node->driver.name, index) == 0)
            return &tmp_node->driver;
    }
    return -1;
}

unsigned char ledtest = 0xff;
int init_drivers(struct driver_list_node_t *head)
{
    struct driver_list_node_t* tmp_node = 0;

PORTC = ledtest--;
    for(tmp_node = head->next; tmp_node;tmp_node = tmp_node->next)
    {
PORTC = ledtest--;
        if(tmp_node->driver.init)
            tmp_node->driver.init();
    }
}
