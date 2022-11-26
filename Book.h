#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "LibraryItem.h"

using namespace std;

class Book : public LibraryItem {
private:
    string author;
    string title;
    int ISBNnumber;
    string category;
public:
    Book();
    Book(string newAuthor, string newTitle, int newISBNnumber, int newlibIDnumber, double newCost, string newCurrentStatus, string newCategory);
    void SetAuthor(string newAuthor);
    void SetTitle(string newTitle);
    void SetISBN(int newISBN);
    void SetLibID(int newLibID);
    void SetCost(double newCost);
    void SetCurrentStatus(string newStatus);
    string GetAuthor();
    string GetTitle();
    int GetISBN();
    int GetLibID();
    double GetCost();
    string GetCurrentStatus();
    string GetCategory();
    void SetCategory(string newCategory);
    void print();
};

#endif