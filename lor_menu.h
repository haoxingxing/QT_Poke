
#ifndef LOR_MENU_H
#define LOR_MENU_H  1
#include "network.h"
#include <QDialog>
#include "mainwindow.h"
#include <string>
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
    std::string password;
    std::string reply;

private slots:
    void on_turn_login_clicked();
    void on_turn_reg_clicked();
    void on_GO_clicked();    
private:
    Ui::LOR_menu *ui;
    int reg_login;


};

#endif // LOR_MENU_H
