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
    /* @brief - destructor*/
    ~BookRepo();

    /* @brief - returns the string representation of the list of books*/
    std::string toString();

    /* @brief - returns all books from the repository*/
    std::vector<Book> getAllBooks() {
        return this->books;
    }

    /* @brief - checks for duplicate books in the database*/
    bool checkDuplicate(Book book);

    /*
     * @brief adds a new book to the repo
     * @param: book - pointer to the book
     * @return - true if successful, false otherwise*/
    bool addBook(Book &book);

    /* @brief - deletes a book from the database*/
    bool deleteBook(const std::string title, const std::string author);

    int searchBook(const std::string title, const std::string author);

    /* @brief - searched the repository by genre*/
    std::vector<Book> searchByGenre(const std::string& genre);
    bool setAll(std::vector<Book> newBookDatabase);
};


#endif //READING_MANAGER_BOOKREPO_H
