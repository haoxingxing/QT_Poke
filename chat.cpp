#include "chat.h"
#include "ui_chat.h"
#include "network.h"
#include <unistd.h>
#include <sstream>
#include "base64.h"
chat::chat(QWidget *parent,std::string username,std::string password) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    this->username=username;
    this->password=password;
    //network *n=new network();
    //n->show();
    curl("mode=chat/start&username="+username+"&password="+password);
    //delete n;
    //std::thread get_msg(this->get,username,password);
    //get_msg.detach();
}

chat::~chat()
{
    delete ui;
}
void chat::get() {
    std::string msg=base64_decode(curl("mode=chat&username="+username+"&password="+password));
    ui->textBrowser->setText(ui->textBrowser->document()->toPlainText()+QString::fromStdString(msg));

}
void chat::on_pushButton_clicked()
{
    this->get();
}
