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
    cout<<memory_current<<endl;

    data_list l;
    l.set_memory(memory_current);
    cout<<l.get_memory()<<endl;
    string id="x";
    int data_type=5;
    string data="2";

    string id2="t";
    int data_type2=1;
    string data2="22";


    l.initialize_data(id,data_type,data);
    l.initialize_data(id2,data_type2,data2);

    l.show_list();

    return 0;
}
