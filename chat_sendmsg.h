#ifndef CHAT_SENDMSG_H
#define CHAT_SENDMSG_H

#include <QDialog>
#include <string>
namespace Ui {
class chat_sendmsg;
}

class chat_sendmsg : public QDialog
{
    Q_OBJECT

public:
    explicit chat_sendmsg(QWidget *parent = 0,std::string username="",std::string password="");
    ~chat_sendmsg();
    std::string username,password;

private slots:
    void on_pushButton_clicked();

private:
    Ui::chat_sendmsg *ui;
};

#endif // CHAT_SENDMSG_H
