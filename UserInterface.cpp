//
// Created by Ovidiu Popa on 12/05/2020.
//

#pragma once
#include "UserInterface.h"
#include <iostream>
#include <string>

/* specialized struct to handle errors*/
struct MyException : public std::exception
{
    std::string s;
    MyException(std::string ss) : s(ss) {}
    ~MyException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};

/* function to handle user input*/
int readInt()
{
    int value;
    std::cin >> value;
    if (std::cin.fail()) /*checks for proper input*/
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw MyException("Characters are expressive but numbers work better here.");
    }
    else return value;
}

void UserInterface::loadInitialData() {
    database.loadDatabase();
    reading_list.loadReadingList();
}

void UserInterface::printStartScreen() {
    printf("Which mode would you like to use?\n");
    printf("\t1. User\n");
    printf("\t2. Administrator\n\n");
    printf("\t0. Exit the program.\n");
}

void UserInterface::printAdminOptions() {
    int option;
    printf("Select an option:\n");
    printf("\t1. Add book to database.\n");
    printf("\t2. Print all the books.\n\n");
    //printf("\t3. Update a book.\n");
    printf("\t4. Delete a book.\n\n");
    printf("\t0. Return to start screen.\n");
    printf("OPTION: ");
    option = readInt();
    printf("\n");
    switch (option) {
        case 0:
            printf("Going back...\n");
            return;
        case 1:
            addBook();
            break;
        case 2:
            for (int i = 0; i < database.displayAllBooks().getAllBooks().size(); ++i) {
                std::cout << database.displayAllBooks().getAllBooks()[i].toString();
            }
            break;
        case 3:
            break;
        case 4:
            deleteBook();
            break;
        default:
            printf("Invalid option");
    }
}

void UserInterface::printUserOptions() {
    int option;
    printf("Select an option:\n");
    printf("\t1. Search the database by genre.\n");
    printf("\t2. See your to-read list.\n\n");
    printf("\t0. Return to start screen.\n");
    printf("OPTION: ");
    option = readInt();
    printf("\n");
    switch (option) {
        case 0:
            printf("Going back...\n");
            return;
        case 1:
            this->printByGenre(&database, &reading_list);
            break;
        case 2:
            displayReadingList();
            break;
        default:
            printf("Invalid option.\n");
    }
}

void UserInterface::displayReadingList() {
    for (int i = 0; i < reading_list.displayAllBooks().getAllBooks().size(); ++i) {
        std::cout << reading_list.displayAllBooks().getAllBooks()[i].toString();
    }
}

void UserInterface::addBook() {
    std::string title, author, genre, description, cover;
    int year;
    printf("Title: ");
    std::cin.get();
    getline(std::cin, title);
    printf("\n");

    printf("Author: ");
    getline(std::cin, author);
    printf("\n");

    printf("Genre:");
    getline(std::cin, genre);
    printf("\n");

    printf("Year: ");
    year = readInt();
    printf("\n");

    printf("Description: ");
    std::cin.get();
    getline(std::cin, description);
    printf("\n");

    printf("Cover link: ");
//    std::cin.get();
    getline(std::cin, cover);
    printf("\n");

    if (database.addBook(title, author, genre, year, description, cover) == 1)
        std::cout << "Book added." << '\n';
}

void UserInterface::deleteBook() {
    std::string title, author;

    printf("Title: ");
    std::cin.get();
    getline(std::cin, title);

    printf("Author: ");
//    std::cin.get();
    getline(std::cin, author);
    std::cout << title << " " << author << '\n';
    if(database.deleteBook(title, author) == 1) {
        std::cout << "Book deleted." << '\n';
    } else std::cout <<"Can't find the book" << '\n';
}

void UserInterface::updateBook() {

}



void UserInterface::printByGenre(Controller *database, Controller *reading_list) {
    bool ok = true;
    int pos = 0, opt;
    std:: string genre;
    printf("Enter a genre(leave empty to display all books): ");
    getline(std::cin, genre);
    getline(std::cin, genre);
    if(database->displayAllBooks().searchByGenre(genre).empty()) {
        printf("Database has no books of that genre.\n");
        return;
    }
    while (ok) {
        auto currentBook = database->displayByGenre(genre)[pos];
        std::cout << currentBook.toString();
        printf("Options:\n");
        printf("\t1. Add to reading list.\n");
        printf("\t2. Go to the next book.\n");
        printf("\t3. Quit browsing.\n");
        std::cin.clear();
        std::cin >> opt;
        while (opt <= 0 || opt >= 4) {
            printf("Invalid option\n");
            printf("Options:\n");
            printf("\t1. Add to reading list.\n");
            printf("\t2. Go to the next book.\n");
            printf("\t3. Quit browsing.\n");
            std::cin >> opt;
        }
        switch (opt) {
            case 1 :
                if(reading_list->displayAllBooks().checkDuplicate(currentBook)) {
                    printf("Book is already in the reading list.\n");
                    break;
                }
                if(reading_list->addBook(currentBook.getTitle(), currentBook.getAuthor(), currentBook.getGenre(),
                                         currentBook.getYear(), currentBook.getDescription(), currentBook.getCover()))
                    printf("Book added!\n");
                break;
            case 2:
                break;
            case 3 :
                ok = false;
                break;
            default :
                break;
        }
        if(pos == database->displayByGenre(genre).size() - 1)
            pos = 0;
        else
            pos++;
    }
}

void UserInterface::displayUI() {
    int option;
    this->loadInitialData();
    do{
        try{
            this->printStartScreen();
            printf("OPTION: ");
            option = readInt();
            printf("\n");

            switch (option) {
                case 0:
                    printf("Program terminated.");
                    database.saveDatabase();
                    reading_list.saveReadingList();
                    return;
                case 1:
                    printUserOptions();
                    break;
                case 2:
                    printAdminOptions();
                    break;
                default:
                    printf("Invalid option.\n");
            }
        }
        catch (std::string error)
        {
            printf("ERROR.\n");
            std::cout << error << '\n';
            printf("\n");
        }
        catch (...)
        {
            printf("ERROR.\n\n");
        }
    } while (true);
}


UserInterface::~UserInterface() = default;

