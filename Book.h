//
// Created by Ovidiu Popa on 12/05/2020.
//

#ifndef READING_MANAGER_BOOK_H
#define READING_MANAGER_BOOK_H


#pragma once
#include <string>

/*
 * @brief - creates instances of the type book
 * @param: title - title of the book;
 * @param: author - author of the book;
 * @param: genre - genre of the book;
 * @param: year - year the book was published;
 * @param: description - briefly describes the book;
 * */
class Book {
private:
    std::string title;
    std::string author;
    std::string genre;
    int year;
    std::string description;
    std::string cover;

public:
    /* @brief - default constructor*/
    explicit Book(std::string ti = "", std::string au = "", std::string ge = "fiction", int y = 2020, std::string de = "", std::string co = "");

    /* @brief - copy constructor */
    Book(const Book& book);

    /* @brief - destructor*/
    ~Book();

    /* Getter methods*/
    std::string getTitle(){
        return this->title;
    }
    std::string getAuthor(){
        return this->author;
    }
    std::string getGenre(){
        return this->genre;
    }
    int getYear() const{
        return this->year;
    }
    std::string getDescription(){
        return this->description;
    }
    std::string getCover(){
        return this->cover;
    }

    /* Setter methods*/
    void setTitle(std::string ti);
    void setAuthor(std::string au);
    void setGenre(std::string ge);
    void setYear(int y);
    void setDescription(std::string de);
    void setCover(std::string co);

    /* @brief - returns the string representation of a book*/
    std::string toString();

    /*
     * @brief - compares two books
     * @param: other - the book to be compared with
     * @return - true if is books are the same, false otherwise*/
    bool compare(const Book& other);
};


#endif //READING_MANAGER_BOOK_H
