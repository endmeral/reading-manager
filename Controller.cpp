//
// Created by Ovidiu Popa on 12/05/2020.
//

#pragma once
#include "Controller.h"
#include "Book.h"
#include "PersistenceEngine.h"

Controller::~Controller() = default;

void Controller::loadData() {
    PersistenceEngineFromJSON eng;
    this->ctrl.setAll(eng.readJSON());
}

void Controller::loadReadingList() {
    PersistenceEngineFromJSON eng;
    this->ctrl.setAll(eng.readReadingList());
}

BookRepo Controller::displayAllBooks() {
    return ctrl;
}

bool Controller::addBook(std::string title, std::string author, std::string genre, int year, std::string description, std::string cover) {
    Book addedBook{ title, author, genre, year, description, cover};
    if (this->ctrl.addBook(addedBook))
    {
        this->undoStack.push(addedBook);
        this->operationListUndo.push(1);
        return true;
    }
}

std::string Controller::toString() {
    return this->ctrl.toString();
}

bool Controller::deleteBook(std::string title, std::string author) {
//    Book deletedBook;
//    deletedBook = this->ctrl.deleteBook(title, author);
//    {
//        this->undoStack.push(deletedBook);
//        this->operationListUndo.push(2);
//        return true;
}

std::vector<Book> Controller::displayByGenre(std::string genre) {
    return this->ctrl.searchByGenre(genre);
}

void Controller::saveData() {
    PersistenceEngineFromJSON eng;
    eng.writeToJSON(this->ctrl.getAllBooks());
}

void Controller::saveReadingList() {
    PersistenceEngineFromJSON eng;
    eng.writeToReadingList((this->ctrl.getAllBooks()));

}

