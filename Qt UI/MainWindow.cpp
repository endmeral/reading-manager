//
// Created by Ovidiu Popa on 13/05/2020.
//


#include <QPushButton>
#include <QHeaderView>
#include "MainWindow.h"
#include "UserWindow.h"
#include "AdminWindow.h"
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    this->showOptions();
    mainWidget.show();

}

void MainWindow::showOptions() {

    auto *layout = new QVBoxLayout;
    auto title = new QLabel("Program Options:");
    auto u_button = new QPushButton("User", this);
    auto a_button = new QPushButton("Administrator", this);

    connect(a_button, SIGNAL(clicked()), this, SLOT(AdminWindow()));
    connect(u_button, SIGNAL(clicked()), this, SLOT(UserWindow()));

    // Set layout
    mainWidget.setWindowTitle("Select Client Mode");
    layout->addWidget(title);
    layout->addWidget(u_button);
    layout->addWidget(a_button);

    if (this->mainWidget.layout() != nullptr) {
        QLayoutItem *item;
        while ((item = this->mainWidget.layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete this->mainWidget.layout();
    }
    this->mainWidget.setLayout(layout);
}

MainWindow::~MainWindow() = default;

void MainWindow::AdminWindow() {
    auto admin = new class AdminWindow;
    admin->show();

    this->close();
}

void MainWindow::UserWindow() {
    auto user = new class UserWindow;

    user->show();
    this->close();
}

