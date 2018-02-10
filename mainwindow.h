
#ifndef MAINWINDOW_H
#define MAINWINDOW_H    1

#include <QMainWindow>
#include <QProgressDialog>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include <string>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0,std::string username="",std::string password="");
    ~MainWindow();
    std::string username;
    std::string password;

protected:

private:
    Ui::MainWindow *ui;

private slots:
    void on_Chat_clicked();
};

#endif // MAINWINDOW_H
