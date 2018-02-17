#include <QApplication>
#include "lor_menu.h"
#include "mainwindow.h"
#include "network.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //std::cout<<curl("http://www.baidu.com");
    QEventLoop wait_lor_menu;
    LOR_menu *first_menu=new LOR_menu;
    first_menu->wait_lor_menu=&wait_lor_menu;
    first_menu->show();
    wait_lor_menu.exec();
    if (first_menu->suss==0)
    {
    //QMessageBox::information(NULL, "Test","233", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        MainWindow *mainw=new MainWindow(0,first_menu->username,first_menu->password);
        first_menu->deleteLater();
        mainw->show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
