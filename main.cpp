#pragma once
#include "UserInterface.h"
#include "PersistenceEngine.h"
#include "Qt UI/MainWindow.h"
#include <iostream>
#include <QApplication>


int main(int argc, char *argv[])
{
    /*
     * Qt GUI
     * if you want to work with a command line interface, comment the block below...
     * */
    QApplication a(argc, argv);
    MainWindow w;

    /*
     * ... uncomment these and change return value to 0
     * */
//    UserInterface UI;
//    UI.displayUI();

    return a.exec();
}
