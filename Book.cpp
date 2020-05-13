//
// Created by Ovidiu Popa on 12/05/2020.
//

#pragma once
#include "Book.h"
#include <sstream>
#include <cstring>
#include <utility>

/* specialized struct to handle errors*/
struct MyException : public std::exception
{
    std::string s;
    MyException(std::string ss) : s(ss) {}
    ~MyException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};

/* default constructor*/
Book::Book(std::string ti, std::string au, std::string ge, int y, std::string de, std::string co) {
    this->title = std::move(ti);
    this->author = std::move(au);
    this->genre = std::move(ge);
    this->year = y;
    this->description = std::move(de);
    this->cover = std::move(co);
}
/* copy constructor*/
Book::Book(const Book &book) {
    this->title = book.title;
    this->author = book.author;
    this->genre = book.genre;
    this->year = book.year;
    this->description = book.description;
    this->cover = book.cover;
}
/* default destructor*/
Book::~Book() = default;


/* setters*/
void Book::setTitle(std::string ti) {
    this->title = std::move(ti);
}

void Book::setAuthor(std::string au) {
    this->author = std::move(au);
}

void Book::setGenre(std::string ge) {
    this->genre = std::move(ge);
}

void Book::setYear(int y) {
    this->year = y;
}

void Book::setDescription(std::string de) {
    this->description = std::move(de);
}

void Book::setCover(std::string co) {
    this->cover = std::move(co);
}

/* string representation of a book
 * order: title > author > genre > date > description > cover
 * */
std::string Book::toString() {
    std::stringstream str;
    str << this->title << " by " << this->author <<"\n\tGenre: " << this->genre << "\n\tPublished in: " << this->year
        << "\n\tDescription: " << this->description << "\nCover: " << this->cover << '\n';
    return str.str();
}

/* compare functionality for books
 * compares current book to a different book
 * takes into account everything but the cover link
 * */
bool Book::compare(const Book& other){
    return this->title == other.title && this->author == other.author && this->genre == other.genre &&
           this->year == other.year && this->description == other.description;
}
