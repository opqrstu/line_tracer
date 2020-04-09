int init_driver_list(struct driver_list_node_t** head);
int clear_driver_list(struct driver_list_node_t* head);
int add_driver_list(struct device_driver_t driver, struct driver_list_node_t* head);
int print_driver_list(struct driver_list_node_t *head);
struct device_driver_t* get_device_driver(char* index, struct driver_list_node_t* head);

