
#ifndef LOR_MENU_H
#define LOR_MENU_H  1
#include "network.h"
#include <QDialog>
#include "mainwindow.h"
#include <string>
#include <QEventLoop>
namespace Ui {
class LOR_menu;
}

class LOR_menu : public QDialog
{
    Q_OBJECT
public:
    explicit LOR_menu(QWidget *parent = 0);
    ~LOR_menu();
    std::string username;
    QEventLoop *wait_lor_menu;
    std::string password;
    std::string reply;
    int suss=1;

private slots:

    void on_GO_clicked();    
    void on_turn_clicked();
    void window_closed_slot();
private:
    Ui::LOR_menu *ui;
    int reg_login;


};

#endif // LOR_MENU_H
