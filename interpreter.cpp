#include "interpreter.h"

interpreter::interpreter()
{
    msg="";
    void *memory=malloc(500);
    ex.set_current(memory);
}

void interpreter::separate(string code)
{
    int x,y;
    string find=";";
    string segment;
    size_t found;

    while(code!=""){
        x=code.size();
        found=code.find(find)+1;
        segment=code.substr(0,found);
        code=code.substr(found,x);
        //cout<<segment<<endl;
        y=find_function(segment);
    }
}

int interpreter::find_function(string segment)
{
    //string find;
    size_t found;

    if((found=segment.find("int"))==0 || (found=segment.find("long"))==0
            || (found=segment.find("char"))==0|| (found=segment.find("float"))==0
            || (found=segment.find("double"))==0|| (found=segment.find("struct"))==0
            || (found=segment.find("reference"))==0){
        cout<<"entro"<<endl;
        return 0;
    }
    else{
        cout<<"no"<<endl;
        return 0;

    }

}

