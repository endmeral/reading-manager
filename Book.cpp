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

Book::Book(std::string ti, std::string au, std::string ge, int y, std::string de, std::string co) {
    this->title = ti;
    this->author = au;
    this->genre = ge;
    this->year = y;
    this->description = de;
    this->cover = co;
}

Book::Book(const Book &book) {
    this->title = book.title;
    this->author = book.author;
    this->genre = book.genre;
    this->year = book.year;
    this->description = book.description;
    this->cover = book.cover;
}

Book::~Book() = default;

void Book::setTitle(std::string ti) {
    this->title = ti;
}

void Book::setAuthor(std::string au) {
    this->author = au;
}

void Book::setGenre(std::string ge) {
    this->genre = ge;
}

void Book::setYear(int y) {
    this->year = y;
}

void Book::setDescription(std::string de) {
    this->description = de;
}

void Book::setCover(std::string co) {
    this->cover = co;
}

std::string Book::toString() {
    std::stringstream str;
    str << this->title << " by " << this->author <<"\n\tGenre: " << this->genre << "\n\tPublished in: " << this->year
        << "\n\tDescription: " << this->description << "\nCover: " << this->cover << '\n';
    return str.str();
}
bool Book::compare(Book other){
    return this->title == other.title && this->author == other.author && this->genre == other.genre &&
           this->year == other.year && this->description == other.description;
}
