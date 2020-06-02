//
// Created by Ovidiu Popa on 13/05/2020.
//

#ifndef READING_MANAGER_ADMINWINDOW_H
#define READING_MANAGER_ADMINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QTableWidget>
#include"../Controller.h"

class AdminWindow  : public QMainWindow {
Q_OBJECT

public:
    AdminWindow(QWidget *parent = nullptr);

    ~AdminWindow();

signals:
public slots:
    void searchPersistenceFile();
    void populateDatabaseFromFile();
    void populateDatabase();
    void addBook();
    void deleteBook();
    void updateBook();
    void cellClicked(int);
    void undo();
    void redo();

private:
    Controller databaseController;

    QLineEdit* m_persistenceFileName;
    QLineEdit* m_title;
    QLineEdit* m_author;
    QLineEdit* m_genre;
    QLineEdit* m_description;
    QLineEdit* m_publication_year;
    QLineEdit* m_cover;

    QTableWidget* m_repoTableWidget;
    void createTableWidget();
    QWidget* createCentralWidget();
    QWidget* createPersistenceWidget();
    QWidget* createDataAboutBookWidget();
    QWidget* createButtonsWidget();
};


#endif //READING_MANAGER_ADMINWINDOW_H
