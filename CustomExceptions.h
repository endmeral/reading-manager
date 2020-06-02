//
// Created by Ovidiu Popa on 27/05/2020.
//

#ifndef READING_MANAGER_CUSTOMEXCEPTIONS_H
#define READING_MANAGER_CUSTOMEXCEPTIONS_H

#pragma once
#include <exception>
#include <string>

class BaseException: public std::exception
{
public:
    const char* what() const noexcept override {
        return "Exception.";
    };
};

class BookException : public BaseException
{
private:
    std::string error_message;

public:
    BookException(std::string error) {
        error_message = "Book exception caught: " + error;
    }
    const char* what() const noexcept override {
        return error_message.c_str();
    }
};

class AdminException : public BaseException
{
private:
    std::string error_message;

public:
    AdminException(std::string error) {
        error_message = "Administrator exception caught: " + error;
    }

    const char* what() const noexcept override {
        return error_message.c_str();
    }

};
class UserException: public BaseException
{
private:
    std::string error_message;

public:
    UserException(std::string error) {
        error_message = "User exception caught: " + error;
    }

    const char* what() const noexcept override {
        return error_message.c_str();
    }
};

class FileException: public BaseException
{
private:
    std::string error_message;
    std::string file_name;

public:
    FileException(std::string error, std::string file): file_name(file) {
        error_message = "File exception caught: " + error + "\nFile where it occured: " + file_name + "\n\n";
    }
};
#endif //READING_MANAGER_CUSTOMEXCEPTIONS_H
