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
    std::stack<std::pair<Book, int>> undoStack, redoStack; // 1- add, 2 - delete, 3 - update
public:
    /* @brief - default destructor*/
    ~Controller();

    /* @brief - loads book database*/
    void loadDatabase();
    /* @brief - loads reading list*/
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

    /*
     * @brief - adds a new book to the repository
     * @param: title - title of the book
     * @param: author - author of the book
     * @return: true if the book was deleted, false otherwise*/
    bool deleteBook(std::string title, std::string author);

    /* @brief - saves changes to the book database*/
    void saveDatabase();

    /* @brief - saves changes to the reading list*/
    void saveReadingList();

    /* @brief - displays books by genre*/
    std::vector<Book> displayByGenre(const std::string& genre);

    std::vector<Book> returnReadingList();

    bool updateBook(std::string title, std::string author, std::string genre, std::string description, int year, std::string cover);

    /* @brief - string representation of the database*/
    std::string toString();

    bool undo();
    bool redo();
};


#endif //READING_MANAGER_CONTROLLER_H
