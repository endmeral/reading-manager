//
// Created by Ovidiu Popa on 12/05/2020.
//

#ifndef READING_MANAGER_USERINTERFACE_H
#define READING_MANAGER_USERINTERFACE_H


#pragma once
#include "Controller.h"

class UserInterface {
private:
    Controller ui;
    Controller to_read;

    void loadInitialData();
    void printStartScreen();
    void printAdminOptions();
    void printUserOptions();
    void printByGenre(Controller *database, Controller *reading_list);
    void displayReadingList();
    void addBook();
    void deleteBook();
    void updateBook();
    void undo();
    void redo();

public:

    ~UserInterface();
    void displayUI();

};


#endif //READING_MANAGER_USERINTERFACE_H
