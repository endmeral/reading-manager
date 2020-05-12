//
// Created by Ovidiu Popa on 12/05/2020.
//

#pragma once
#include "BookRepo.h"
#include <sstream>

/* specialized struct to handle errors*/
struct MyException : public std::exception
{
    std::string s;
    MyException(std::string ss) : s(ss) {}
    ~MyException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};

std::string BookRepo::toString() {
    std::stringstream str;
    str << "The Book list is: \n" << '\n';
    for (int i = 0; i < this->books.size(); i++)
    {
        str << this->books[1].toString() << '\n';
    }
    return str.str();
}

bool BookRepo::addBook(Book& book)
{
    for (int i = 0; i < this->books.size(); i++)
        if (this->books[i].compare(book))
            throw MyException("Duplicate book!");
    this->books.insert(books.end(), book);
    return true;
}

bool BookRepo::deleteBook(std::string title, std::string author) {
//    for (int i = 0; i < this->books.size(); i++)
//        if (this->books[i].getTitle() == title && this->books[i].getAuthor() == author )
//        {
//            Book t = this->books[i];
//            this->books.removeElement(i);
//            return t;
//        }
//    throw MyException("Non-existent book!");
}

std::vector<Book> BookRepo::searchByGenre(std::string genre) {
    std::vector<Book>(genre_books);
    if(genre == "") {
        return getAllBooks();
    } else{
        for (int i = 0; i < this->books.size(); ++i) {
            if(this->books[i].getGenre() == genre)
                genre_books.push_back(books[i]);
        }
    }
    return genre_books;
}

bool BookRepo::checkDuplicate(Book book) {
    for (int i = 0; i < this->books.size(); ++i) {
        if(this->books[i].getTitle() == book.getTitle() || this->books[i].getAuthor() == book.getAuthor() ||
           this->books[i].getGenre() == book.getGenre() || this->books[i].getYear() == book.getYear() ||
           this->books[i].getDescription() == book.getDescription())
            return true;
    }
    return false;
}
bool BookRepo::setAll(std::vector<Book> newBookDatabase) {
    this->books = std::move(newBookDatabase);
    return true;
}

BookRepo::~BookRepo() = default;