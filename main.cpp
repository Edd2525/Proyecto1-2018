#include "mainwindow.h"
#include <QApplication>
#include "data_list.h"
#include "execute.h"
#include "interpreter.h"
int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //test
    return a.exec();*/

    void *memory_start, *memory_current;
    void *space=malloc(500);
    memory_start=space;
    memory_current=space;
    //cout<<memory_current<<endl;

    data_list l;
    l.set_memory(memory_current);
    //cout<<l.get_memory()<<endl;
    string id="x";
    int data_type=1;
    string data="2";

    string id2="t";
    int data_type2=1;
    string data2="42";

    string id3="r";
    int data_type3=2;
    string data3="454";

    string id4="q";
    int data_type4=3;
    string data4="2332";

    string id5="y";
    int data_type5=4;
    string data5="2543";

    string code="int x;"
                "int y=6;"
                "x=2;"
                "y=x;"
                "x=y+x;"
                "long h;"
                "double u;"
                "float b;"
                "char p;";
    cout<<code<<endl;
    interpreter in;
    in.separate(code);


    /*execute ex;
    ex.set_current(memory_current);
    ex.initialize_data(id,data_type,data);
    ex.initialize_data(id2,data_type2,data2);
    ex.initialize_data(id3,data_type3,data3);
    ex.initialize_data(id5,data_type5,data5);
    ex.show_list();
    ex.operation(5,"x","t");
    ex.show_list();*/

    return 0;
}
