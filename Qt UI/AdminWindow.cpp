//
// Created by Ovidiu Popa on 13/05/2020.
//

#include "AdminWindow.h"
#include "MainWindow.h"
#include <QPushButton>
#include <QHeaderView>
#include <QVBoxLayout>

AdminWindow::AdminWindow(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Administrator Mode");
//    setMinimumSize(400, 300);

    auto wip_button = new QPushButton("WIP", this);
    auto r_button = new QPushButton("Back", this);

    connect(r_button, SIGNAL(clicked()), this, SLOT(MainWindow()));

    // Set layout
    auto *layout = new QVBoxLayout;
    layout->addWidget(wip_button);
    layout->addWidget(r_button);

    // Set layout in QWidget
    auto *window = new QWidget();
    window->setLayout(layout);

    // Set QWidget as the central layout of the main window
    setCentralWidget(window);
}

AdminWindow::~AdminWindow() = default;

void AdminWindow::MainWindow() {
    auto MainWindow = new class MainWindow;
    MainWindow->show();
    this->close();

}
