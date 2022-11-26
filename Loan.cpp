#include <iostream>
#include <string>
using namespace std;

#include "Loan.h"

Loan::Loan()
{
	// Never will be created with these, just here to test (if you see any of these something went wrong)
	rechecked = false;
	loanID = 999999;
	bookID = 999999;
	patronID = 999999;
	dueDate = "00/00/0000";
	currentStatus = "Unknown";
}

Loan::Loan(int newLoanID, int newBookID, int newPatronID, string newDueDate, string newCurrentStatus) {
	loanID = newLoanID;
	bookID = newBookID;
	patronID = newPatronID;
	dueDate = newDueDate;
	currentStatus = newCurrentStatus;
}

void Loan::SetLoanID(int newLoanID) {
	loanID = newLoanID;
}

void Loan::SetBookID(int newBookID) {
	bookID = newBookID;
}

void Loan::SetPatronID(int newPatronID) {
	patronID = newPatronID;
}

void Loan::SetDueDate(string newDueDate) {
	dueDate = newDueDate;
}

void Loan::SetCurrentStatus(string newCurrentStatus) {
	currentStatus = newCurrentStatus;
}

int Loan::GetLoanID() {
	return loanID;
}

int Loan::GetBookID() {
	return bookID;
}

int Loan::GetPatronID() {
	return patronID;
}

string Loan::GetDueDate() {
	return dueDate;
}

string Loan::GetCurrentStatus() {
	return currentStatus;
}

void Loan::FlopRechecked() {
	rechecked = !rechecked;
}

bool Loan::GetRechecked() {
	return rechecked;
}