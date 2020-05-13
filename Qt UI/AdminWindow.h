//
// Created by Ovidiu Popa on 13/05/2020.
//

#ifndef READING_MANAGER_ADMINWINDOW_H
#define READING_MANAGER_ADMINWINDOW_H


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

class AdminWindow  : public QMainWindow {
Q_OBJECT

public:
    AdminWindow(QWidget *parent = nullptr);

    ~AdminWindow();

private:
    Ui::AdminWindow *ui;

public slots:
    void MainWindow();
};


#endif //READING_MANAGER_ADMINWINDOW_H
