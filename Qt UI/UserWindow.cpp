//
// Created by Ovidiu Popa on 13/05/2020.
//

#include "UserWindow.h"
#include "MainWindow.h"
#include "../Controller.h"
#include "../Book.h"
#include "../UserInterface.h"
#include <vector>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFormLayout>

UserWindow::UserWindow(QWidget *parent) : QMainWindow(parent) {

//    this->database.loadData("database", "/Users/ovidiupopa/CLionProjects/reading-manager/database.json");
//    this->reading_list.loadData("readinglist", "/Users/ovidiupopa/CLionProjects/reading-manager/readinglist.json");

    setWindowTitle("bug futu-l in gura");
    this->showOptions();
    mainWidget.show();
}

void UserWindow::showOptions() {

    auto *mainLayout = new QVBoxLayout;
    auto title = new QLabel("User Options:");
    auto database_button = new QPushButton("Search database", this);
    auto reading_list_button = new QPushButton("See reading list", this);
    auto r_button = new QPushButton("Back", this);

    connect(r_button, SIGNAL(clicked()), this, SLOT(MainWindow()));
    connect(database_button, SIGNAL(clicked()), this, SLOT(DatabaseWindow()));
    connect(reading_list_button, SIGNAL(clicked()), this, SLOT(ReadingListWindow()));

    /*
     * SET INITIAL LAYOUT
     * */
    mainWidget.setWindowTitle("User Mode");
    mainLayout->addWidget(title);
    mainLayout->addWidget(database_button);
    mainLayout->addWidget(reading_list_button);
    mainLayout->addWidget(r_button);

    if (this->mainWidget.layout() != nullptr) {
        QLayoutItem *item;
        while ((item = this->mainWidget.layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(mainLayout);
}

UserWindow::~UserWindow() = default;

void UserWindow::MainWindow() {
    auto MainWindow = new class MainWindow;
    MainWindow->show();
    this->close();
}

void UserWindow::DatabaseWindow() {
    auto *databaseLayout = new QFormLayout();

}

void UserWindow::ReadingListWindow() {
    auto *readingListLayout = new QVBoxLayout();
    auto title = new QLabel("Your books are:");
    auto r_button = new QPushButton("Back", this);
    connect(r_button, &QPushButton::clicked, this, &UserWindow::showOptions);

    readingListLayout->addWidget(title);
    readingListLayout->addWidget(r_button);

    if ( this->mainWidget.layout() != nullptr ) {
        QLayoutItem *item;
        while ((item = this->mainWidget.layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(readingListLayout);
}



