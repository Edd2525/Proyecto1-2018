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
    if(find_id(id))
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
    return false;
}

bool data_list::find_id(string id)
{
    node *temp=node_head;
    if(node_head==NULL)//lista vacia
        return true;
    while(temp){
        if(id==temp->ID)
            return false;
        temp=temp->next;
    }
    return true;
}

node *data_list::get_node(string id)
{
    node *temp=node_head;
    if(node_head==NULL)//lista vacia
        return NULL;
    while(temp){
        if(id==temp->ID)
            return temp;
        temp=temp->next;
    }
    return NULL;
}

string data_list::get_id(node *nodo)
{
    return nodo->get_id();
}

string data_list::get_type(node *node)
{
    return node->get_data_type();
}

void *data_list::get_memory(node *nodo)
{
    return nodo->get_memory();
}

string data_list::get_data(node *nodo)
{
    return nodo->get_data();
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
