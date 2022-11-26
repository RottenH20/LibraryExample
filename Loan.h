#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <iostream>
using namespace std;

class Loan {
private:
    bool rechecked;
    int loanID;
    int bookID;
    int patronID;
    string dueDate;
    string currentStatus;
public:
    Loan();
    Loan(int newLoanID, int newBookID, int newPatronID, string newDueDate, string newCurrentStatus);
    void SetLoanID(int newLoanID);
    void SetBookID(int newBookID);
    void SetPatronID(int newPatronID);
    void SetDueDate(string newDueDate);
    void SetCurrentStatus(string newCurrentStatus);
    int GetLoanID();
    int GetBookID();
    int GetPatronID();
    string GetDueDate();
    string GetCurrentStatus();
    void FlopRechecked();
    bool GetRechecked();
};

#endif