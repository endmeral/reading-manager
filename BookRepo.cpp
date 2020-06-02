//
// Created by Ovidiu Popa on 12/05/2020.
//

#pragma once
#include "BookRepo.h"
#include <sstream>
#include <vector>

/* specialized struct to handle errors*/
struct MyException : public std::exception
{
    std::string s;
    MyException(std::string ss) : s(ss) {}
    ~MyException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};

/* function for returning the string representation of the repository
 * returns a stringstream string
 * uses toStrin from Book for each book in the database*/
std::string BookRepo::toString() {
    std::stringstream str;
    str << "The Book list is: \n" << '\n';
    for (int i = 0; i < this->books.size(); i++)
    {
        str << this->books[1].toString() << '\n';
    }
    return str.str();
}

/* adds a new book to the repository
 * compares the book to-be-added with the database, searching for duplicates
 * if none are found, the book is added
 * otherwise, an exception is thrown, function returns false*/
bool BookRepo::addBook(Book& book)
{
    for (auto & i : this->books)
        if (i.compare(book))
            throw MyException("Duplicate book!");
    this->books.insert(books.end(), book);
    return true;
}

/* deletes a book from the repository
 * searches the repository for a book with a matching title & author
 * if such a book is found, the book is removed from the repo
 * otherwise, an exception is thrown, function returns false*/
Book BookRepo::deleteBook(std::string title, std::string author) {
    int it = searchBook(std::move(title), std::move(author));
    if (it == this->books.size())
        printf("Can't delete this book.\n");
    Book book = this->books[it];
    this->books.erase(this->books.begin()+it);
    return book;
}

bool BookRepo::updateBook(std::string title, std::string author, std::string genre, std::string description, int year, std::string cover)
{
    int it = searchBook(title, author);
    if (it == this->books.size())
        return false;
    else {
        if (genre != "")
            this->books[it].setGenre(genre);
        if (description != "")
            this->books[it].setDescription(description);
        if (year != 0)
            this->books[it].setYear(year);
        if (cover != "")
            this->books[it].setCover(cover);
    }
    return true;
}

int BookRepo::searchBook(std::string title, std::string author) {
    int it = 0;
    while (it != this->books.size()){
        if (this->books[it].getTitle() == title && this->books[it].getAuthor() == author)
            return it;
        it++;
    }
    return it;
}

/* searches the repository for books with the matching genre
 * if the genre field is left empty, returns the entire repository
 * otherwise, searches for books with said genre */
std::vector<Book> BookRepo::searchByGenre(const std::string& genre) {
    std::vector<Book>(genre_books);
    if(genre.empty()) {
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
    for (auto & i : this->books) {
        if(i.getTitle() == book.getTitle() || i.getAuthor() == book.getAuthor() ||
           i.getGenre() == book.getGenre() || i.getYear() == book.getYear() ||
           i.getDescription() == book.getDescription())
            return true;
    }
    return false;
}

/* used for moving the books from the JSON file to the repository*/
bool BookRepo::setAll(std::vector<Book> newBookDatabase) {
    this->books = std::move(newBookDatabase);
    return true;
}

BookRepo::~BookRepo() = default;