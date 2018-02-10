#include "chat_sendmsg.h"
#include "ui_chat_sendmsg.h"
#include "network.h"
chat_sendmsg::chat_sendmsg(QWidget *parent,std::string username,std::string password) :
    QDialog(parent),
    ui(new Ui::chat_sendmsg)
{
    ui->setupUi(this);
    this->username=username;
    this->password=password;

}

chat_sendmsg::~chat_sendmsg()
{
    delete ui;
}

void chat_sendmsg::on_pushButton_clicked()
{
    network *n=new network();
    n->show();
    n->curl("mode=chat/report&t="+ui->textEdit->document()->toPlainText().toStdString()+"&username="+username+"&password="+password);
    //std::string feelback=n->reply;
    delete n;
    ui->textEdit->setText("");
}
