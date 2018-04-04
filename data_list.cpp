#include "data_list.h"

data_list::data_list()
{
    node_head=NULL;
    node_tail=NULL;
    current=NULL;
}

data_list::~data_list()
{

}

void data_list::set_memory(void *memory)
{
    current=memory;
}

void *data_list::get_memory()
{
    return current;
}

bool data_list::initialize_data(string id, int data_, string data)
{
    node *new_node = new node(id,data_);
    if(node_head==NULL){
        node_head=new_node;
        node_tail=new_node;
    }

    else{
        node_tail->next=new_node;
        node_tail=node_tail->next;
    }

    new_node->assign_memory(current,data);
    current=current+new_node->get_memory_move();
    return true;

}

void data_list::show_list()
{
    cout<<"----------------PRINT--------------------"<<endl;
    node *temp=node_head;
    while(temp){
        temp->print_node();
        temp=temp->next;
    }
}
