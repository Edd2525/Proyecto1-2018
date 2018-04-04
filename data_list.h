#ifndef DATA_LIST_H
#define DATA_LIST_H
#include "data_nodo.h"

class data_list
{
public:
    data_list();
    ~data_list();
    void set_memory(void *memory);
    void *get_memory();
    bool initialize_data(string id, int data_, string data);
    void show_list();

private:
    void *current;
    node *node_head, *node_tail;
};

#endif // DATA_LIST_H
