//
// Created by Ovidiu Popa on 13/05/2020.
//

#ifndef READING_MANAGER_MAINWINDOW_H
#define READING_MANAGER_MAINWINDOW_H


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void AdminWindow();
    void UserWindow();
};


#endif //READING_MANAGER_MAINWINDOW_H
