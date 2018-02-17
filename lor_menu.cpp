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
    //ui->Login_MENU->show();
    //ui->Reg_MENU->hide();
    reg_login=0;
    connect(this,SIGNAL(rejected()),this,SLOT(window_closed_slot()));
}

LOR_menu::~LOR_menu()
{
    delete ui;
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
            suss=0;
            wait_lor_menu->quit();
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
        if (u.reg(ui->Username_l->text().toStdString(),ui->Password_l->text().toStdString()))
        {
            ui->GO->hide();
            ui->main->hide();
            username=ui->Username_l->text().toStdString();
            password=ui->Password_l->text().toStdString();
            accept();
            suss=0;
            wait_lor_menu->quit();
        }
        else
        {
            ui->message->show();
            ui->GO->show();

        }
    }
}


void LOR_menu::on_turn_clicked()
{
    if (reg_login==0)
    {
        reg_login=1;
        ui->Tip->setText("Please Register");
        ui->turn->setText("Login?");
    }
    else
    {
        reg_login=0;
        ui->Tip->setText("Please Login");
        ui->turn->setText("Reg?");
    }
}

void LOR_menu::window_closed_slot(){
    suss=1;
    wait_lor_menu->quit();
}
