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
    w.show();

    /*
     * ... and uncomment these
     * */
//    UserInterface UI;
//    UI.displayUI();

    return a.exec();
}
