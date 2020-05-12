//
// Created by Ovidiu Popa on 12/05/2020.
//

#ifndef READING_MANAGER_BOOKREPO_H
#define READING_MANAGER_BOOKREPO_H


#pragma once
#include <vector>
#include "Book.h"

class BookRepo {
private:
    std::vector<Book>(books);
public:
    ~BookRepo();

    /* return the string representation of the list of books*/
    std::string toString();

    std::vector<Book> getAllBooks() {
        return this->books;
    }

    bool checkDuplicate(Book book);

    /*
     * @brief adds a new book to the repo
     * @param: book - pointer to the book
     * @return - true if successful, false otherwise*/
    bool addBook(Book &book);

    bool deleteBook(std::string title, std::string author);

    std::vector<Book> searchByGenre(std::string genre);
    bool setAll(std::vector<Book> newBookDatabase);
};


#endif //READING_MANAGER_BOOKREPO_H
