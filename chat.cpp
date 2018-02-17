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
    network *n=new network();
    n->show();
    n->curl("mode=chat/start&username="+username+"&password="+password);
    delete n;
    //std::thread get_msg(this->get,username,password);
    //get_msg.detach();
}

chat::~chat()
{
    delete ui;
}


void chat::get() {
    std::string numst,numstc;
    std::string msg;
    int num=-1;
    while (1)
    {
        std::stringstream nums;
        nums<<num;
        nums>>numst;
        network *n=new network();
        n->show();
        n->curl("mode=chat&username="+username+"&password="+password+"&num="+numst);
        msg=base64_decode(n->reply);
        delete n;
        while (msg=="n"|msg=="nk")
        {
            network *n=new network();
            n->show();
            n->curl("mode=chat&username="+username+"&password="+password+"&num="+numst);
            msg=base64_decode(n->reply);
            delete n;
            sleep(5);
        }
        ui->textBrowser->setText(ui->textBrowser->document()->toPlainText()+QString::fromStdString(msg));
        num++;
        sleep(1);
    }
}

void chat::on_chat_destroyed()
{

}

void chat::on_pushButton_clicked()
{
    this->get();
}
