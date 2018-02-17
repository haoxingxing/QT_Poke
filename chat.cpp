#include "chat.h"
#include "ui_chat.h"
#include "network.h"
#include <unistd.h>
#include <sstream>
#include <QTimer>
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
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(s_get()));
    timer->start(1000);
}

chat::~chat()
{
    delete ui;
}

void chat::s_get() {
    //std::string msg=;
    ui->textBrowser->setText(QString::fromStdString(curl("mode=chat&username="+username+"&password="+password)));
    ui->label->setText("Get Message Success!");
}
void chat::on_pushButton_clicked()
{
    ui->pushButton->setText("Bufit!");
    std::string buf="mode=chat/report&t="+ui->textEdit->document()->toPlainText().toStdString()+"&username="+username+"&password="+password;
    ui->pushButton->setText("Clear!");
    ui->textEdit->setText("");
    ui->pushButton->setText("Sending!");
    curl(buf);
    ui->pushButton->setText("OK!");
    ui->label->setText("Send Message Success!");
    usleep(10000);
    ui->pushButton->setText("Send");
}
