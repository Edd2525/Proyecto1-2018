#include "data_nodo.h"
#include "data_nodo.h"
#include "string.h"
node::node()
{
    this->next=NULL;
    this->data=NULL;
    this->ID="";
    this->data_type=0;
}


node::node(string id, int data_)
{
    this->ID=id;
    this->data_type=data_;
    this->next=NULL;
}

void node::assign_memory(void *current_memory, string data)
{
    int op=this->data_type;
    if(op==1){//caso cuando el valor es int
        this->data=current_memory;
        int value=atoi(data.c_str());
        *(int*)this->data=value;
    }else if(op==2){//caso cuando el valor es long
        this->data=current_memory;
        long value=atol(data.c_str());
        *(long*)this->data=value;
    }else if(op==3){//caso cuando el valor es un char
        this->data=current_memory;
        const char *y=data.c_str();
        //strcpy(y,data.c_str());
        *(char *)this->data=*y;
    }else if(op==4){//caso cuando el valor es float
        this->data=current_memory;
        float value=strtof(data.c_str(),NULL);
        *(float*)this->data=value;
    }else if(op==5){//en caso de que el valor es double
        this->data=current_memory;
        double value=atof(data.c_str());
        *(double*)this->data=value;
    }


}

string node::get_id()
{
    return this->ID;
}

string node::get_data_type()
{
    switch (this->data_type) {
    case 1:
        return "int";
        break;
    case 2:
        return "long";
        break;
    case 3:
        return "char";
        break;
    case 4:
        return "float";
        break;
    case 5:
        return "double";
        break;

    default:
        return "No asignado";
        break;
    }
}

string node::get_data()
{
    int op=this->data_type;
    if(op==1){
        int x=*(int*)this->data;
        string str=to_string(x);
        return str;
    }
    else if(op==2){
        long x=*(long*)this->data;
        string str=to_string(x);
        return str;
    }else if(op==3){
        return "str";
    }else if(op==4){
        float x=*(float*)this->data;
        string str=to_string(x);
        return str;
    }else if(op==5){
        double x=*(double*)this->data;
        string str=to_string(x);
        return str;
    }else
        return "Junk";
}

void *node::get_memory()
{
    return this->data;
}

int node::get_memory_move()
{
    switch (this->data_type) {
    case 1:
        return 4;//"int";
        break;
    case 2:
        return 8;//"long";
        break;
    case 3:
        return 1;//"char";
        break;
    case 4:
        return 4;//"float";
        break;
    case 5:
        return  8;//"double";
        break;

    default:
        return  0;//"No asignado";
        break;
    }
}

int node::get_op_data()
{
    return this->data_type;
}


void node::print_node()
{   int op=this->data_type;
    if(op==1)//int
        cout<<"ID:"<<this->ID<<"  Type:"<<get_data_type()<<"  Memory:"<<this->data<<"  Data:"<<*(int*)this->data<<endl;
    else if(op==2)//long
        cout<<"ID:"<<this->ID<<"  Type:"<<get_data_type()<<"  Memory:"<<this->data<<"  Data:"<<*(long*)this->data<<endl;
    else if(op==3)//char
        cout<<"ID:"<<this->ID<<"  Type:"<<get_data_type()<<"  Memory:"<<this->data<<"  Data:"<<*(char*)this->data<<endl;
    else if(op==4)
        cout<<"ID:"<<this->ID<<"  Type:"<<get_data_type()<<"  Memory:"<<this->data<<"  Data:"<<*(float*)this->data<<endl;
    else if(op==5)
        cout<<"ID:"<<this->ID<<"  Type:"<<get_data_type()<<"  Memory:"<<this->data<<"  Data:"<<*(double*)this->data<<endl;
}
