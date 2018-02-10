#include <QApplication>
#include "lor_menu.h"
#include "mainwindow.h"
#include "network.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::cout<<curl("http://www.baidu.com");
    LOR_menu first_menu;
    first_menu.show();
    //QMessageBox::information(NULL, "Test",QString::fromStdString(username), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    return a.exec();
}
