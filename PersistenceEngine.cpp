//
// Created by Ovidiu Popa on 12/05/2020.
//

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "PersistenceEngine.h"

std::vector<Book> PersistenceEngineFromJSON::readJSON() {
    std::vector<Book>(database);
    Book book;
    QFile file("/Users/ovidiupopa/CLionProjects/reading-manager/database.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();
    QJsonValue value = object.value("bookDatabase");
    QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array) {
        book.setTitle(v.toObject().value("title").toString().toUtf8().constData());
        book.setAuthor(v.toObject().value("author").toString().toUtf8().constData());
        book.setGenre(v.toObject().value("genre").toString().toUtf8().constData());
        book.setYear(v.toObject().value("year").toInt());
        book.setDescription(v.toObject().value("description").toString().toUtf8().constData());
        book.setCover(v.toObject().value("cover").toString().toUtf8().constData());
        database.push_back(book);
    }
    printf("Reading list is loaded.\n");
    return database;
}


void PersistenceEngineFromJSON::writeToJSON(const std::vector<Book>& database) {
    QJsonArray array;
    QFile file("/Users/ovidiupopa/CLionProjects/reading-manager/database.json");
    foreach(Book i, database) {
        QJsonObject bookObject;
        bookObject["title"] = QString::fromStdString(i.getTitle());
        bookObject["author"] = QString::fromStdString(i.getAuthor());
        bookObject["genre"] = QString::fromStdString(i.getGenre());
        bookObject["year"] = i.getYear();
        bookObject["description"] = QString::fromStdString(i.getDescription());
        bookObject["cover"] = QString::fromStdString(i.getCover());
        array.append(bookObject);
    }
    QJsonObject object;
    object["bookDatabase"] = array;
    QJsonDocument saveDoc(object);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(saveDoc.toJson());
    file.close();
}

void PersistenceEngineFromJSON::writeToReadingList(const std::vector<Book>& readinglist) {
    QJsonArray array;
    QFile file("/Users/ovidiupopa/CLionProjects/reading-manager/readinglist.json");
    foreach(Book i, readinglist) {
        QJsonObject bookObject;
        bookObject["title"] = QString::fromStdString(i.getTitle());
        bookObject["author"] = QString::fromStdString(i.getAuthor());
        bookObject["genre"] = QString::fromStdString(i.getGenre());
        bookObject["year"] = i.getYear();
        bookObject["description"] = QString::fromStdString(i.getDescription());
        bookObject["cover"] = QString::fromStdString(i.getCover());
        array.append(bookObject);
    }
    QJsonObject object;
    object["readingList"] = array;
    QJsonDocument saveDoc(object);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(saveDoc.toJson());
    file.close();
}

std::vector<Book> PersistenceEngineFromJSON::readReadingList() {
    std::vector<Book>(readinglist);
    Book book;
    QFile file("/Users/ovidiupopa/CLionProjects/reading-manager/readinglist.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();
    QJsonValue value = object.value("readingList");
    QJsonArray array = value.toArray();
    foreach (const QJsonValue & v, array) {
        book.setTitle(v.toObject().value("title").toString().toUtf8().constData());
        book.setAuthor(v.toObject().value("author").toString().toUtf8().constData());
        book.setGenre(v.toObject().value("genre").toString().toUtf8().constData());
        book.setYear(v.toObject().value("year").toInt());
        book.setDescription(v.toObject().value("description").toString().toUtf8().constData());
        book.setCover(v.toObject().value("cover").toString().toUtf8().constData());
        readinglist.push_back(book);
    }
    return readinglist;
}
