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

    //QString cod = QString::fromStdString(in.remove_backn(code.toStdString()));
    ui->ram_view->setText(QString::fromStdString(in.ex.get_msg()));
    ui->stdout->setText(QString::fromStdString(in.ex.get_error()));

}
