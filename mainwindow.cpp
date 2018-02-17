#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chat.h"
#include "chat_sendmsg.h"
MainWindow::MainWindow(QWidget *parent,std::string username,std::string password):QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //while (username=="");
    // QMessageBox::information(NULL, "Test",QString::fromStdString(username), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    ui->username->setText(QString::fromStdString(username));
    this->username=username;
    this->password=password;

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Chat_clicked()
{
    chat *chatwindow=new chat(0,username,password);
    chatwindow->show();
    chat_sendmsg *cw=new chat_sendmsg(0,username,password);
    cw->show();
}
