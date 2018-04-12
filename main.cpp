#include "mainwindow.h"
#include <QApplication>
#include "data_list.h"
#include "execute.h"
#include "interpreter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


    /*string code="int x;\nint z = 9;\ndouble x;";
    interpreter in;
    string x="e";
    string v="c";
    in.ex.initialize_data(x,3,v);
    in.ex.show_list();
    /*string x="xy";
    char *y=new char[1];
    strcpy(y,x.c_str());
    char v=*y;
    void *gg=malloc(1);
    *(char *)gg=*y;
    cout<<*(char *)gg<<endl;*/

    /*return 0;*/

}
