//
// Created by Ovidiu Popa on 13/05/2020.
//

#ifndef READING_MANAGER_USERWINDOW_H
#define READING_MANAGER_USERWINDOW_H


#include <QMainWindow>
#include <QLineEdit>
#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include "../Controller.h"
#include <QPushButton>

class UserWindow  : public QMainWindow {
Q_OBJECT

public:
    UserWindow(QWidget *parent = nullptr);

    ~UserWindow();

private:
    Controller readingListController;
    Controller databaseController;

    QTableWidget* databaseTableWidget;
    QTableWidget* readingListTableWidget;

    QLineEdit* genreForFilter;

    QWidget* createCentralWidget();
    void createDatabaseTableWidget();
    void createReadingListTableWidget();
    QWidget* createFilterByGenreWidget();
    QWidget* createDatabaseAndToListenWidget();


public slots:
    void populateDatabase();
    void populateReadingList();

    void addBookButtonPressed();
    void deleteBookButtonPressed();


    void addBook(int);
    void deleteBook(int);

};


#endif //READING_MANAGER_USERWINDOW_H
