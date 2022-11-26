#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <iostream>
using namespace std;

class Patron {
private:
    string name;
    int IDNum;
    double FineBal;
    int BooksOut;
public:
    Patron();
    Patron(string newName, int newPatron_ID, double newFineBal, int newBookBorrow);
    void SetName(string newName);
    void SetIDNum(int newIDNum);
    void SetFineBal(double newFineBal);
    void SetBooksOut(int newBooksOut);
    string GetName();
    int GetIDNum();
    double GetFineBal();
    int GetBooksOut();
};

#endif