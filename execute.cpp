#include "execute.h"

execute::execute()
{
    msg="";
    error="";
}

execute::~execute()
{

}

bool execute::initialize_data(string id, int data_, string data)
{
    if(registry.initialize_data(id,data_,data)){
        msg=msg+"Agregado correctamente "+id+"\n";
        return true;
    }
    else{
        error=error+"Error la variable "+id+" ya fue inicializada\n";
        return false;
    }
}

void execute::set_current(void *memory)
{
    registry.set_memory(memory);
}

bool execute::same_data_type(node *origen, node *compare)
{
    if(origen->get_data_type()==compare->get_data_type())
        return true;
    else
        return false;
}

bool execute::operation(int op, string id1, string id2)
{
    node *origen=registry.get_node(id1);
    node *operation=registry.get_node(id2);
    if(origen!=NULL && operation!=NULL){
        if(this->same_data_type(origen,operation)){
            if(op==1){//asignacion
                if(this->assignment(origen,operation))
                    msg=msg+"Asignacion entre "+id1+" con "+id2+" correcta\n";
                else
                    error=error+"Este sistema no acepta operaciones entre "+origen->get_data_type();
            }else if(op==2){//suma
                if(this->sum(origen,operation))
                    msg=msg+"Suma entre "+id1+" con "+id2+" correcta\n";
                else
                    error=error+"Este sistema no acepta operaciones entre "+origen->get_data_type();
            }else if(op==3){//resta
                if(this->subtraction(origen,operation))
                    msg=msg+"Resta entre "+id1+" con "+id2+" correcta\n";
                else
                    error=error+"Este sistema no acepta operaciones entre "+origen->get_data_type();

            }else if(op==4){//multi
                if(this->multiply(origen,operation))
                    msg=msg+"Multiplicacion entre "+id1+" con "+id2+" correcta\n";
                else
                    error=error+"Este sistema no acepta operaciones entre "+origen->get_data_type();

            }else if(op==5){//divi
                if(this->divide(origen,operation))
                    msg=msg+"Divicion entre "+id1+" con "+id2+" correcta\n";
                else
                   error=error+"Este sistema no acepta operaciones entre "+origen->get_data_type();
            }
        }
        else{
            error=error+id1+" con "+id2+" no se puede realizar: "+origen->get_data_type()+" con "+operation->get_data_type()+"\n";
            return false;
        }
    }
    else{
        error=error+"Variables no encontradas ("+id1+") ("+id2+")\n";
        return false;
    }
}

bool execute::assignment(node *origen, node *operation)
{
    int op=origen->get_op_data();

    if(op==1){//en caso de ser int
        int y;
        y=*(int *)operation->get_memory();
        *(int *)origen->get_memory()=y;
        return true;
    }else if(op==2){//en caso de ser long
        long y;
        y=*(long *)operation->get_memory();
        *(long *)origen->get_memory()=y;
        return true;
    }else if(op==3){//en caso de ser char
        //charrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
        error=error+"Char no acepta operacion + \n";
        return false;
    }else if(op==4){//en caso de ser float
        float y;
        y=*(float *)operation->get_memory();
        *(float *)origen->get_memory()=y;
        return true;
    }else if(op==5){//en caso de ser double
        double y;
        y=*(double *)operation->get_memory();
        *(double *)origen->get_memory()=y;
        return true;
    }
}

bool execute::sum(node *origen, node *operation)
{
    int op=origen->get_op_data();

    if(op==1){//en caso de ser int
        int x, y;
        x=*(int *)origen->get_memory();
        y=*(int *)operation->get_memory();
        *(int *)origen->get_memory()=x+y;
        cout<<*(int *)origen->get_memory()<<endl;
        return true;
    }else if(op==2){//en caso de ser long
        long x, y;
        x=*(long *)origen->get_memory();
        y=*(long *)operation->get_memory();
        *(long *)origen->get_memory()=x+y;
        return true;
    }else if(op==3){//en caso de ser char
        //charrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
        error=error+"Char no acepta operacion + \n";
        return false;
    }else if(op==4){//en caso de ser float
        float x, y;
        x=*(float *)origen->get_memory();
        y=*(float *)operation->get_memory();
        *(float *)origen->get_memory()=x+y;
        return true;
    }else if(op==5){//en caso de ser double
        double x, y;
        x=*(double *)origen->get_memory();
        y=*(double *)operation->get_memory();
        *(double *)origen->get_memory()=x+y;
        return true;
    }
}

bool execute::subtraction(node *origen, node *operation)
{
    int op=origen->get_op_data();

    if(op==1){//en caso de ser int
        int x, y;
        x=*(int *)origen->get_memory();
        y=*(int *)operation->get_memory();
        *(int *)origen->get_memory()=x-y;
        return true;
    }else if(op==2){//en caso de ser long
        long x, y;
        x=*(long *)origen->get_memory();
        y=*(long *)operation->get_memory();
        *(long *)origen->get_memory()=x-y;
        return true;
    }else if(op==3){//en caso de ser char
        error=error+"Char no acepta operacion - \n";
        //charrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
        return false;
    }else if(op==4){//en caso de ser float
        float x, y;
        x=*(float *)origen->get_memory();
        y=*(float *)operation->get_memory();
        *(float *)origen->get_memory()=x-y;
        return true;
    }else if(op==5){//en caso de ser double
        double x, y;
        x=*(double *)origen->get_memory();
        y=*(double *)operation->get_memory();
        *(double *)origen->get_memory()=x-y;
        return true;
    }
}

bool execute::multiply(node *origen, node *operation)
{
    int op=origen->get_op_data();

    if(op==1){//en caso de ser int
        int x, y;
        x=*(int *)origen->get_memory();
        y=*(int *)operation->get_memory();
        *(int *)origen->get_memory()=x*y;
        return true;
    }else if(op==2){//en caso de ser long
        long x, y;
        x=*(long *)origen->get_memory();
        y=*(long *)operation->get_memory();
        *(long *)origen->get_memory()=x*y;
        return true;
    }else if(op==3){//en caso de ser char
        error=error+"Char no acepta operacion * \n";
        //charrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
        return false;
    }else if(op==4){//en caso de ser float
        float x, y;
        x=*(float *)origen->get_memory();
        y=*(float *)operation->get_memory();
        *(float *)origen->get_memory()=x*y;
        return true;
    }else if(op==5){//en caso de ser double
        double x, y;
        x=*(double *)origen->get_memory();
        y=*(double *)operation->get_memory();
        *(double *)origen->get_memory()=x*y;
        return true;
    }
}

bool execute::divide(node *origen, node *operation)
{
    int op=origen->get_op_data();

    if(op==1){//en caso de ser int
        int x, y;
        x=*(int *)origen->get_memory();
        y=*(int *)operation->get_memory();
        *(int *)origen->get_memory()=x/y;
        return true;
    }else if(op==2){//en caso de ser long
        long x, y;
        x=*(long *)origen->get_memory();
        y=*(long *)operation->get_memory();
        *(long *)origen->get_memory()=x/y;
        return true;
    }else if(op==3){//en caso de ser char
        error=error+"Char no acepta operacion / \n";
        //charrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
        return false;
    }else if(op==4){//en caso de ser float
        float x, y;
        x=*(float *)origen->get_memory();
        y=*(float *)operation->get_memory();
        *(float *)origen->get_memory()=x/y;
        return true;
    }else if(op==5){//en caso de ser double
        double x, y;
        x=*(double *)origen->get_memory();
        y=*(double *)operation->get_memory();
        *(double *)origen->get_memory()=x/y;
        return true;
    }
}

string execute::get_msg()
{
    return msg;
}

string execute::get_error()
{
    return error;
}

void execute::show_list()
{
    registry.show_list();
}
