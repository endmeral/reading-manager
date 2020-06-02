//
// Created by Ovidiu Popa on 13/05/2020.
//

#include "UserWindow.h"
#include "MainWindow.h"
#include "../Controller.h"
#include "../Book.h"
#include "../UserInterface.h"
#include <vector>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFormLayout>

UserWindow::UserWindow(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("User Mode");

    this->readingListController.loadReadingList();
    this->databaseController.loadDatabase();

    QWidget *centralWidget = createCentralWidget();
    this->setCentralWidget(centralWidget);

}


QWidget *UserWindow::createCentralWidget() {
    QWidget* filterByGenreWidget = createFilterByGenreWidget();
    QWidget* databaseAndToListenWidget = createDatabaseAndToListenWidget();
    populateReadingList();

    auto* line =  new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    auto* vBoxLayout = new QVBoxLayout;
    vBoxLayout->addWidget(filterByGenreWidget);
    vBoxLayout->addWidget(line);
    vBoxLayout->addWidget(databaseAndToListenWidget);

    auto* widget=new QWidget(this);
    widget->setLayout(vBoxLayout);

    return widget;
}

void UserWindow::createDatabaseTableWidget() {
    databaseTableWidget=new QTableWidget(this);
    databaseTableWidget->setColumnCount(6);
    databaseTableWidget->setSortingEnabled(true);
    databaseTableWidget->setStyleSheet("color:#144017");
    databaseTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color:#b3b3b3; color:#0a7311}");
    databaseTableWidget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color:#b3b3b3; color:#0a7311}");
    databaseTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cover"));
    databaseTableWidget->horizontalHeader()->setMinimumSectionSize(160);
    databaseTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Title"));
    databaseTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Author"));
    databaseTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Publication year"));
    databaseTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Genre"));
    databaseTableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Description"));

    connect(databaseTableWidget->verticalHeader(), &QHeaderView::sectionDoubleClicked, this, &UserWindow::addBook);
}

void UserWindow::createReadingListTableWidget() {
    readingListTableWidget = new  QTableWidget(this);
    readingListTableWidget->setColumnCount(6);
    readingListTableWidget->setSortingEnabled(true);
    readingListTableWidget->setStyleSheet("color=#144017");
    readingListTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color:#b3b3b3; color:#0a7311}");
    readingListTableWidget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color:#b3b3b3; color:#0a7311}");
    readingListTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cover"));
    readingListTableWidget->horizontalHeader()->setMinimumSectionSize(160);
    readingListTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Title"));
    readingListTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Author"));
    readingListTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Publication year"));
    readingListTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Genre"));
    readingListTableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Description"));

    connect(readingListTableWidget->verticalHeader(), &QHeaderView::sectionDoubleClicked, this, &UserWindow::deleteBook);
}

QWidget *UserWindow::createFilterByGenreWidget() {
    auto *label = new QLabel("Search by genre:", this);
    genreForFilter = new QLineEdit(this);
    auto *buttonSearch = new QPushButton("Search",this);

    auto* grid = new QGridLayout(this);
    grid->addWidget(label,0,0);
    grid->addWidget(genreForFilter,0,1);
    grid->addWidget(buttonSearch,0,2);

    connect(buttonSearch, &QPushButton:: pressed, this, &UserWindow:: populateDatabase );

    auto *widget=new QWidget(this);
    widget->setLayout(grid);

    return widget;
}

QWidget *UserWindow::createDatabaseAndToListenWidget() {
    createDatabaseTableWidget();
    createReadingListTableWidget();
    auto *repo = new QLabel("Book repository:", this);
    auto *toListen = new QLabel("To listen list:", this);
    auto* buttonAdd = new QPushButton("Add",this);
    auto *buttonDelete = new QPushButton("Delete",this);

    auto *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(repo,0,0);
    gridLayout->addWidget(toListen,0,2);
    gridLayout->addWidget(databaseTableWidget,1,0);
    gridLayout->addWidget(readingListTableWidget,1,2);
    gridLayout->addWidget( buttonAdd,2,0);
    gridLayout->addWidget(buttonDelete,2,2);

    auto* widget=new QWidget(this);
    widget->setLayout(gridLayout);

    connect(buttonAdd, &QPushButton:: pressed, this, &UserWindow:: addBookButtonPressed );
    connect(buttonDelete, &QPushButton:: pressed, this, &UserWindow:: deleteBookButtonPressed );

    return widget;
}

void UserWindow::addBookButtonPressed() {
    int selectedRow = databaseTableWidget->currentRow();
    if(selectedRow < 0) {
        return;
    }
    std::vector<Book> database = this->databaseController.displayByGenre(genreForFilter->text().toStdString());
    Book book = database[selectedRow];
    readingListController.addBook(book.getTitle(), book.getAuthor(), book.getGenre(), book.getYear(), book.getDescription(), book.getCover());

    populateReadingList();
}

void UserWindow::deleteBookButtonPressed() {
    int selectedRow = readingListTableWidget->currentRow();
    if(selectedRow < 0) {
        return;
    }
    std::vector<Book> database = this->readingListController.returnReadingList();
    Book book = database[selectedRow];
    readingListController.deleteBook(book.getTitle(), book.getAuthor());

    populateReadingList();
}

void UserWindow::addBook(int row) {
    std::vector<Book> database = this->databaseController.displayByGenre(genreForFilter->text().toStdString());
    Book book = database[row];
    readingListController.addBook(book.getTitle(), book.getAuthor(), book.getGenre(), book.getYear(), book.getDescription(), book.getCover());

    populateReadingList();
}

void UserWindow::deleteBook(int row) {
    readingListController.deleteBook(readingListTableWidget->item(row, 1)->text().toStdString(), readingListTableWidget->item(row, 2)->text().toStdString());

    populateReadingList();
}

void UserWindow::populateDatabase() {
    databaseTableWidget->clearContents();

    std::string genre = genreForFilter->text().toStdString();
    std::vector<Book> database = this->databaseController.displayByGenre(genre);
    databaseTableWidget->setRowCount(database.size());

    int i=0;
    for(auto book: database){
        auto *icon=new QIcon(book.getCover().c_str());
        databaseTableWidget->setItem(i,0,new QTableWidgetItem(*icon,book.getCover().c_str()));
        databaseTableWidget->setItem(i,1,new QTableWidgetItem(book.getTitle().c_str()));
        databaseTableWidget->setItem(i,2,new QTableWidgetItem(book.getAuthor().c_str()));
        databaseTableWidget->setItem(i,3,new QTableWidgetItem(std::to_string(book.getYear()).c_str()));
        databaseTableWidget->setItem(i,4,new QTableWidgetItem(book.getGenre().c_str()));
        databaseTableWidget->setItem(i,5,new QTableWidgetItem(book.getDescription().c_str()));
        i++;
        printf("Added Book");
    }
}

void UserWindow::populateReadingList() {
    readingListTableWidget->clearContents();

    std::vector<Book> reading_list = this->readingListController.returnReadingList();
    readingListTableWidget->setRowCount(reading_list.size());

    int i=0;
    for(auto book: reading_list){
        auto *icon=new QIcon(book.getCover().c_str());
        readingListTableWidget->setItem(i,0,new QTableWidgetItem(*icon,book.getCover().c_str()));
        readingListTableWidget->setItem(i,1,new QTableWidgetItem(book.getTitle().c_str()));
        readingListTableWidget->setItem(i,2,new QTableWidgetItem(book.getAuthor().c_str()));
        readingListTableWidget->setItem(i,3,new QTableWidgetItem(std::to_string(book.getYear()).c_str()));
        readingListTableWidget->setItem(i,4,new QTableWidgetItem(book.getGenre().c_str()));
        readingListTableWidget->setItem(i,5,new QTableWidgetItem(book.getDescription().c_str()));
        i++;
    }
}

UserWindow::~UserWindow() {
    databaseController.saveDatabase();
    readingListController.saveReadingList();
}
