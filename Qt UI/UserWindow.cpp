//
// Created by Ovidiu Popa on 13/05/2020.
//

#include "UserWindow.h"
#include "MainWindow.h"
#include <QPushButton>
#include <QHeaderView>
#include <QVBoxLayout>

UserWindow::UserWindow(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("User Mode");
//    setMinimumSize(400, 300);

    auto database_button = new QPushButton("Search database", this);
    auto reading_list_button = new QPushButton("See reading list", this);
    auto r_button = new QPushButton("Back", this);

    connect(r_button, SIGNAL(clicked()), this, SLOT(MainWindow()));
    connect(database_button, SIGNAL(clicked()), this, SLOT(DatabaseWindow()));
    connect(reading_list_button, SIGNAL(clicked()), this, SLOT(ReadingListWindow()));

    /*
     * SET INITIAL LAYOUT
     * */
    auto *layout = new QVBoxLayout;
    layout->addWidget(database_button);
    layout->addWidget(reading_list_button);
    layout->addWidget(r_button);
    // Set layout in QWidget
    auto *window = new QWidget();
    window->setLayout(layout);
    // Set QWidget as the central layout of the main window
    setCentralWidget(window);


}

UserWindow::~UserWindow() {
    delete ui;
}

void UserWindow::MainWindow() {
    auto MainWindow = new class MainWindow;
    MainWindow->show();
    this->close();
}

void UserWindow::DatabaseWindow() {
    
}

void UserWindow::ReadingListWindow() {

}

