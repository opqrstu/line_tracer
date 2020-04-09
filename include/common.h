struct device_driver_t
{
    char name[20];
    int (*init)();
    int b;
};

extern struct driver_list_node_t *driver_list_head;


