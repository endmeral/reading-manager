//
// Created by Ovidiu Popa on 13/05/2020.
//

#ifndef READING_MANAGER_MAINWINDOW_H
#define READING_MANAGER_MAINWINDOW_H


#include <QMainWindow>

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void showOptions();

private:
    QWidget mainWidget;

public slots:
    void AdminWindow();
    void UserWindow();
};


#endif //READING_MANAGER_MAINWINDOW_H
