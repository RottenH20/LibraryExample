#ifndef LOANS_H
#define LOANS_H

#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include "Loan.h"
#include "Patrons.h";
#include "Books.h"
using namespace std;

class Loans {
private:
    tm *dt;
    map<int, Loan> LoanList;
public:
    Loans(tm *time);
    void CheckOutBook(Patrons &PatronList, Books &BookList);
    void CheckInBook(Patrons& PatronList, Books& BookList);
    void ListAllOverdue();
    void ListBooksForPatron(int patronID);
    void UpdateLoanStatus(Books BookList, Patrons PatronList);
    void ReCheckBook(Patrons& PatronList, Books& BookList);
    void EditLoan(int patronID);
    void ReportLost(Patrons& PatronList, Books& BookList);
};

#endif