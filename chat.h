#ifndef CHAT_H
#define CHAT_H  1
#include <QWidget>
#include <string>

namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = 0,std::string username="",std::string password="");
    ~chat();
    std::string username,password;
    void get();

private slots:
    void on_pushButton_clicked();

private:
    Ui::chat *ui;
    int num=-1;
};

#endif // CHAT_H
