#include "mainwindow.h"
#include <QApplication>
#include "data_list.h"
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
    int data_type=5;
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

    string id5="x";
    int data_type5=4;
    string data5="2543";


    l.initialize_data(id,data_type,data);
    l.initialize_data(id2,data_type2,data2);
    l.initialize_data(id3,data_type3,data3);
    //l.initialize_data(id4,data_type4,data4);//char arreglar
    l.initialize_data(id5,data_type5,data5);

    l.show_list();

    node *x=l.get_node("o");
    if(x!=NULL){
        cout<<l.get_id(x)<<endl;
        cout<<l.get_type(x)<<endl;
        cout<<l.get_data(x)<<endl;
        cout<<l.get_memory(x)<<endl;
    }


    return 0;
}
