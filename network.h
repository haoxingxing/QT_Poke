#ifndef NETWORK_H
#define NETWORK_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
namespace Ui {
class network;
}

class network : public QWidget
{
    Q_OBJECT

public:
    explicit network(QWidget *parent = 0);
    void curl(std::string url);
    ~network();
    std::string reply;
private:
    Ui::network *ui;
};
std::string curl(std::string url);
#endif // NETWORK_H
