#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <iostream>
#include <map>
#include "Book.h"
using namespace std;

class Books {
private:
    map<int, Book> BookList;
public:
    Books();
    void Add_Book(string newAuthor, string newTitle, int newISBNnumber, double newCost, string newCategory, int &currentTracker);
    void Edit_Book(int newlibIDnumber);
    void Delete_Book(int newlibIDnumber);
    bool Search_Book(int newlibIDnumber);
    void GetAll_Book();
    void GetInfo_Book(int newlibIDnumber);
    bool IsBookUsed(int newlibIDnumber);
    map<int, Book> ReturnBookList();
};

#endif