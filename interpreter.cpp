#include "interpreter.h"

interpreter::interpreter()
{
    print="";
    void *memory=malloc(500);
    ex.set_current(memory);
}

int interpreter::code_type(string type)
{
    if(type=="int")
        return 1;
    else if(type=="long")
        return 2;
    else if(type=="char")
        return 3;
    else if(type=="float")
        return 4;
    else if(type=="double")
        return 5;
    else if(type=="struct")
        return 6;
    else if(type=="reference")
        return 7;
    else return 0;
}

int interpreter::code_operatidon(string opera)
{
    if(opera=="=")
        return 1;
    else if(opera=="+")
        return 2;
    else if(opera=="-")
        return 3;
    else if(opera=="*")
        return 4;
    else if(opera=="/")
        return 5;
    else return 0;
}

string interpreter::eliminate_space(string code)
{

}

string interpreter::remove_backn(string code)
{
    int x;
    string code_end="";
    string find="\n";
    size_t found;
    while(code!=""){
        x=code.size();
        found=code.find(find)+1;
        code_end=code_end+code.substr(0,found-1);
        code=code.substr(found,x);
        if(found==0)
            code="";
    }
    return code_end;
}

void interpreter::separate_line_code(string code)
{
    int x;
    string find=";";
    string segment;
    size_t found;

    while(code!=""){
        x=code.size();
        found=code.find(find)+1;
        segment=code.substr(0,found);
        this->separete_comand_variable(segment);
        code=code.substr(found,x);
        //cout<<segment<<endl;
        //y=find_function(segment);
    }
}


void interpreter::separete_comand_variable(string code)
{
    size_t found;
    int x;
    bool continue_=true;
    string data_type="";
    string origen="";
    string operation="";
    string data_opera="";
    x=code.size();
    code=code.substr(0,x-1);//elimina el ; final
    if(code.find("print")==0){
        x=code.size();
        found=code.find("=")+1;
        code=code.substr(found,x);
        print_code(code);

    }
    else if((found=code.find("int"))==0 || (found=code.find("long"))==0
            || (found=code.find("char"))==0|| (found=code.find("float"))==0
            || (found=code.find("double"))==0|| (found=code.find("struct"))==0
            || (found=code.find("reference"))==0){
        x=code.size();
        found=code.find(" ")+1;
        data_type=code.substr(0,found-1);//asigna el tipo de dato
        code=code.substr(found,x);
        x=code.size();
        found=code.find(" ")+1;
        origen=code.substr(0,found-1);//id del dato
        code=code.substr(found,x);
        //cout<<interpreter::code_type(data_type)<<endl;
        continue_=ex.initialize_data(origen,interpreter::code_type(data_type)," ");
    }else{
        x=code.size();
        found=code.find(" ")+1;
        origen=code.substr(0,found-1);//id del dato
        code=code.substr(found,x);
    }

    while(continue_){
        if(code.find("=")==0 || code.find("+")==0 ||
             code.find("-")==0 || code.find("*")==0 ||
             code.find("/")==0){
            x=code.size();
            found=code.find(" ")+1;
            operation=code.substr(0,found-1);//operacion a realizar
            code=code.substr(found,x);
            x=code.size();
            found=code.find(" ")+1;
            data_opera=code.substr(0,found-1);
            //cout<<"operacio "<<operation<<endl;
            //cout<<"variable "<<data_opera<<endl;
            //cout<<"Code "<<interpreter::code_operatidon(operation)<<endl;
            if(ex.operation(this->code_operatidon(operation),origen,data_opera)){
                //cout<<"entro  "<<endl;
                code=code.substr(found,x);
                if(code.size()==1)
                    continue_=false;
            }
            else{
                cout<<"Problemas"<<endl;
                continue_=false;
            }
        }else
            continue_=false;
    }
    ex.show_list();
}

void interpreter::print_code(string code)
{
    int x;
    size_t found;
    bool continue_=true;
    string print_="";
    string info_="";
    string data_;
    //cout<<code<<endl;
    while(continue_){
        if(code.find("'")==0){
            x=code.size();
            code=code.substr(1,x);
            found=code.find("'");
            info_=info_+code.substr(0,found);
            code=code.substr(found+1,x);

        }
        else if(code.find("(")==0){
            x=code.size();
            code=code.substr(1,x);
            found=code.find(")");
            data_=code.substr(0,found);
            node *data=ex.registry.get_node(data_);
            if(data != NULL){
                info_=info_+data->get_data();
                code=code.substr(found+1,x);
            }
            else{
                info_=info_+"ERROR";
                continue_=false;
            }

            }
            else
                continue_=false;

        }
    print=info_+"\n";



}

string interpreter::get_error()
{
    return ex.get_error();
}

