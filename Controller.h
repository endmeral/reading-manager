//
// Created by Ovidiu Popa on 12/05/2020.
//

#ifndef READING_MANAGER_CONTROLLER_H
#define READING_MANAGER_CONTROLLER_H


#pragma once
#include <vector>
#include <stack>
#include "BookRepo.h"

class Controller {
private:
    BookRepo ctrl;
    std::stack <Book> undoStack, redoStack;
    std::stack <int> operationListUndo, operationListRedo;
public:
    ~Controller();

    /* @brief - loads book database*/
    void loadData();
    void loadReadingList();

    /* @brief - displays all the books*/
    BookRepo displayAllBooks();

    /*
     * @brief - adds a new book to the repository
     * @param: title - title of the book
     * @param: author - author of the book
     * @param: genre - genre of the book
     * @param: year - year the book was published in
     * @param: description - short description of the book
     * @return: returns true if the book was added, false otherwise*/
    bool addBook(std::string title, std::string author, std::string genre, int year, std::string description, std::string cover);

    bool deleteBook(std::string title, std::string author);

    void saveData();

    void saveReadingList();

    std::vector<Book> displayByGenre(std::string genre);

    std::string toString();
};


#endif //READING_MANAGER_CONTROLLER_H
