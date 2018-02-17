#include "lor_menu.h"
#include "ui_lor_menu.h"
#include "user.h"
#include <iostream>
LOR_menu::LOR_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LOR_menu)
{
    ui->setupUi(this);
    ui->main->show();
    ui->message->hide();
    ui->Login_MENU->show();
    ui->Reg_MENU->hide();
    reg_login=0;

}

LOR_menu::~LOR_menu()
{
    delete ui;
}
void LOR_menu::on_turn_reg_clicked()
{
    ui->Reg_MENU->show();
    ui->Login_MENU->hide();
    reg_login=1;
}

void LOR_menu::on_turn_login_clicked()
{
    ui->Login_MENU->show();
    ui->Reg_MENU->hide();
    reg_login=0;
}
void LOR_menu::on_GO_clicked()
{

    ui->GO->hide();
    if (!reg_login)
    {
        user u;
        if (u.login(ui->Username_l->text().toStdString(),ui->Password_l->text().toStdString()))
        {
            ui->GO->hide();
            ui->main->hide();
            username=ui->Username_l->text().toStdString();
            password=ui->Password_l->text().toStdString();
            accept();
        }
        else
        {
            ui->message->show();
            ui->GO->show();
        }

    }
    else
    {
        user u;
        if (u.reg(ui->Username_r->text().toStdString(),ui->Password_r->text().toStdString()))
        {
            ui->GO->hide();
            ui->main->hide();
            username=ui->Username_r->text().toStdString();
            password=ui->Password_r->text().toStdString();
            accept();
        }
        else
        {
            ui->message->show();
            ui->GO->show();

        }
    }
}

