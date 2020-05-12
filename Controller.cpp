//
// Created by Ovidiu Popa on 12/05/2020.
//

#pragma once
#include "Controller.h"
#include <utility>
#include "Book.h"
#include "PersistenceEngine.h"

/* default destructor*/
Controller::~Controller() = default;

/* loads data from database.json*/
void Controller::loadDatabase() {
    PersistenceEngineFromJSON eng;
    this->ctrl.setAll(eng.readJSON());
}

/* loads data from readinglist.json*/
void Controller::loadReadingList() {
    PersistenceEngineFromJSON eng;
    this->ctrl.setAll(eng.readReadingList());
}

/* returns the controller repositories*/
BookRepo Controller::displayAllBooks() {
    return ctrl;
}

/* adds a new book to the controllers repositories*/
bool Controller::addBook(std::string title, std::string author, std::string genre, int year, std::string description, std::string cover) {
    Book addedBook{ std::move(title), std::move(author), std::move(genre), year, std::move(description), std::move(cover)};
    return this->ctrl.addBook(addedBook);
}

/* string representation of the controller repositories*/
std::string Controller::toString() {
    return this->ctrl.toString();
}

/* functionality for deleting books from the repositories*/
bool Controller::deleteBook(const std::string& title, const std::string& author) {
    return this->ctrl.deleteBook(title, author);
}


/* displays books by genre*/
std::vector<Book> Controller::displayByGenre(const std::string& genre) {
    return this->ctrl.searchByGenre(genre);
}

/* saves the changes made to database.json*/
void Controller::saveDatabase() {
    PersistenceEngineFromJSON eng;
    eng.writeToJSON(this->ctrl.getAllBooks());
}

/* saves the changes made to readinglist.json*/
void Controller::saveReadingList() {
    PersistenceEngineFromJSON eng;
    eng.writeToReadingList((this->ctrl.getAllBooks()));

}

