#include "network.h"
#include "ui_network.h"

network::network(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::network)
{
    ui->setupUi(this);
}

network::~network()
{
    delete ui;
}
void network::curl(std::string url)
{
    url="http://v.starfiles.tk:88/project/project.php?"+url;
    ui->message->setText("(1/4)Networking..");
    ui->progressBar->setValue(10);
    QEventLoop temp_loop;
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply* reply = manager->get(QNetworkRequest(QUrl(QString::fromStdString(url))));
    ui->message->setText("(2/4)Sending..");
    ui->progressBar->setValue(10);
    QObject::connect(reply, SIGNAL(finished()), &temp_loop, SLOT(quit()));
    ui->message->setText("(3/4)Replying..");
    ui->progressBar->setValue(40);
    temp_loop.exec();
    qDebug()<<"start";
    if(reply->error()==QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QString rlt =QString::fromUtf8(bytes);
        this->reply = rlt.toStdString();
        //std::cout<<rlt.toStdString();
        ui->message->setText("(4/4)OK.");
        ui->progressBar->setValue(100);

    }
    else
    {
        ui->message->setText("Error");
    }
    reply->deleteLater();
    qDebug()<<"finished";
}
std::string curl(std::string url) {
    network *n=new network();
    n->show();
    std::string reply;
    n->curl(url);
    //n->deleteLater();
    reply=n->reply;
    n->deleteLater();
    return reply;
}
