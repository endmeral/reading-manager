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
    this->undoStack.push({addedBook, 1});
    return this->ctrl.addBook(addedBook);
}

/* string representation of the controller repositories*/
std::string Controller::toString() {
    return this->ctrl.toString();
}

/* functionality for deleting books from the repositories*/
bool Controller::deleteBook(std::string title, std::string author) {
    Book book = this->ctrl.deleteBook(title, author);
    this->undoStack.push({book, 2});
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

bool Controller::updateBook(std::string title, std::string author, std::string genre, std::string description, int year, std::string cover) {
    return this->ctrl.updateBook(title, author, genre, description, year, cover);
}

std::vector<Book> Controller::returnReadingList() {
    return ctrl.getAllBooks();
}

bool Controller::undo() {
    if(!undoStack.empty()) {
        Book b = this->undoStack.top().first;
        switch (this->undoStack.top().second) {
            case 1:
                //addition
                this->ctrl.deleteBook(b.getTitle(), b.getAuthor());
                this->redoStack.push({b, 1});
                break;
            case 2:
                //deletion
                this->ctrl.addBook(b);
                this->redoStack.push({b, 2});
                break;
            default:
                throw std::string("Impossible undo operation.");
        }
        this->undoStack.pop();
        return true;
    }
    else throw std::string("There are no undo operations possible.");
}

bool Controller::redo() {
    if (!redoStack.empty()) {
        Book b = this->redoStack.top().first;
        switch (this->redoStack.top().second) {
            case 1:
                this->ctrl.addBook(b);
                this->undoStack.push({b, 1});
                break;
            case 2:
                this->ctrl.deleteBook(b.getTitle(), b.getAuthor());
                this->undoStack.push({b, 2});
                break;
            default:
                throw std::string("Impossible redo operation.");
        }
        this->redoStack.pop();
        return true;
    }
    else throw std::string("There are no redo operations possible");
}
