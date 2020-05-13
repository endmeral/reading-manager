//
// Created by Ovidiu Popa on 13/05/2020.
//


#include <QPushButton>
#include <QHeaderView>
#include "MainWindow.h"
#include "UserWindow.h"
#include "AdminWindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {


    setWindowTitle("Select Client Mode");
//    setMinimumSize(400, 300);

    auto u_button = new QPushButton("User", this);
//    u_button->setGeometry(10, 10, 120, 50);

    auto a_button = new QPushButton("Administrator", this);
//    a_button->setGeometry(10, 70, 120, 50);

    connect(a_button, SIGNAL(clicked()), this, SLOT(AdminWindow()));
    connect(u_button, SIGNAL(clicked()), this, SLOT(UserWindow()));

    // Set layout
    auto *layout = new QVBoxLayout;
    layout->addWidget(u_button);
    layout->addWidget(a_button);

    // Set layout in QWidget
    auto *window = new QWidget();
    window->setLayout(layout);

    // Set QWidget as the central layout of the main window
    setCentralWidget(window);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::AdminWindow() {
    auto AdminWindow = new class AdminWindow;
    AdminWindow->show();
    this->close();
}

void MainWindow::UserWindow() {
    auto UserWindow = new class UserWindow;
    UserWindow->show();
    this->close();
}

