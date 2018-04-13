#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_run_clicked()
{
    interpreter in;
    QString code=ui->code_text->toPlainText();
    in.separate_line_code(in.remove_backn(code.toStdString()));

    QString list = QString::fromStdString(in.ex.registry.list);
    QString ok = QString::fromStdString(in.ex.get_msg());
    QString error = QString::fromStdString(in.ex.get_error());

    cout<<in.ex.msg<<endl;
    cout<<in.ex.error<<endl;

    ui->ram_view->setText(list);
    ui->stdout->setText(error);
    ui->stdout_2->setText(ok);

}
