//
// Created by Ovidiu Popa on 12/05/2020.
//

#ifndef READING_MANAGER_PERSISTENCEENGINE_H
#define READING_MANAGER_PERSISTENCEENGINE_H


#include "BookRepo.h"

class PersistenceEngineFromJSON {
public:
    std::vector<Book> readJSON();
    std::vector<Book> readReadingList();
    void writeToJSON(const std::vector<Book>& database);
    void writeToReadingList(const std::vector<Book>& readinglist);
};


#endif //READING_MANAGER_PERSISTENCEENGINE_H
