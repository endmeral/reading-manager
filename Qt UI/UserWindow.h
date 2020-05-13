//
// Created by Ovidiu Popa on 13/05/2020.
//

#ifndef READING_MANAGER_USERWINDOW_H
#define READING_MANAGER_USERWINDOW_H


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UserWindow; }
QT_END_NAMESPACE

class UserWindow  : public QMainWindow {
Q_OBJECT

public:
    UserWindow(QWidget *parent = nullptr);

    ~UserWindow();

private:
    Ui::UserWindow *ui;

public slots:
    void MainWindow();
    void DatabaseWindow();
    void ReadingListWindow();
};


#endif //READING_MANAGER_USERWINDOW_H
