#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
using namespace std;

#pragma warning(disable : 4996)

#include "Loan.h"
#include "Loans.h"
#include "Patrons.h"
#include "Patron.h"
#include "Books.h"
#include "Book.h"

int nthOccurrence(const string& str, const string& findMe, int nth)
{
	size_t  pos = 0;
	int     cnt = 0;

	while (cnt != nth)
	{
		pos += 1;
		pos = str.find(findMe, pos);
		if (pos == std::string::npos)
			return -1;
		cnt++;
	}
	return pos;
}

Loans::Loans(tm *time) {
	
	dt = time;
	map<int, Loan> LoanList;
}

void Loans::CheckOutBook(Patrons &PatronList, Books &BookList) {
	int patronID;
	int bookID;
	cout << "Enter Patron ID: ";
	cin >> patronID;
	if (PatronList.Search_Patron(patronID))
	{
		// Do nothing! yay!
	}
	else
	{
		cout << "Patron not found." << endl;
		cout << "Exiting option." << endl;
		return;
	}
	PatronList.GetInfo_Patron(patronID);
	cout << "----------------------" << endl;
	//BookList.GetAll_Book();
	//cout << "----------------------" << endl;
	cout << "Enter library ID to check-out: ";
	cin >> bookID;
	if (BookList.IsBookUsed(bookID))
	{
		// Do nothing! yay!
	}
	else
	{
		cout << "Book is unavailible (Book is not -In-)" << endl;
		cout << "Exiting option." << endl;
		return;
	}
	if (PatronList.ReturnPatronList()[patronID].GetBooksOut() > 5)
	{
		cout << "To many books out! Please return some!" << endl;
		return;
	}
	string newCurrentStatusYear = to_string(1900 + (int)(dt->tm_year));
	string newCurrentStatusMonth = to_string(1 + (int)(dt->tm_mon));
	string newCurrentStatusDay = to_string((int)(dt->tm_mday));

	string newCurrentStatus = newCurrentStatusDay + "/" + newCurrentStatusMonth + "/" + newCurrentStatusYear;
	string newDueDate = to_string(stoi(newCurrentStatusDay) + 10) + "/" + newCurrentStatusMonth + "/" + newCurrentStatusYear;
	
	// Day/Month/year format

	BookList.ReturnBookList()[bookID].SetCurrentStatus("Out");
	PatronList.ReturnPatronList()[patronID].SetBooksOut(PatronList.ReturnPatronList()[patronID].GetBooksOut() + 1);
	Loan newLoan(bookID, bookID, patronID, newDueDate, newCurrentStatus);
	LoanList.insert({ bookID, newLoan });
	PatronList.ReturnPatronList()[patronID].SetFineBal(PatronList.ReturnPatronList()[patronID].GetFineBal() + 0.25);
	cout << "Loan added for patronID = " << patronID << endl;
}

void Loans::CheckInBook(Patrons &PatronList, Books &BookList) {
	int patronID;
	int bookID;
	cout << "Enter Patron ID: ";
	cin >> patronID;
	if (PatronList.Search_Patron(patronID))
	{
		// Do nothing! yay!
	}
	else
	{
		cout << "Patron not found." << endl;
		cout << "Exiting option." << endl;
		return;
	}
	PatronList.GetInfo_Patron(patronID);
	cout << "----------------------" << endl;
	BookList.GetAll_Book();
	cout << "----------------------" << endl;
	cout << "Enter Book ID: ";
	cin >> bookID;
	if (BookList.Search_Book(bookID))
	{
		// Do nothing yay!
	}
	else
	{
		cout << "Book is unavailible (Book does not exist)" << endl;
		cout << "Exiting option." << endl;
		return;
	}
	if (PatronList.ReturnPatronList()[patronID].GetFineBal() > 0)
	{
		cout << "There is a fine of " << PatronList.ReturnPatronList()[patronID].GetFineBal() << endl;
		cout << "Before you return, you must pay fine." << endl;
		return;
	}
	if (LoanList.find(bookID) == LoanList.end())
	{
		cout << "You do not have that book checked out." << endl;
		return;
	}
	LoanList.erase(bookID);
	cout << "Successfully returned book!" << endl;
}

void Loans::ListAllOverdue() {
	for (auto it = LoanList.begin(); it != LoanList.end(); it++)
	{
		cout << "Loan ID: "
			<< it->first
			<< " : "
			<< "Patron ID: "
			<< LoanList[it->first].GetPatronID()   // string's value 
			<< " : "
			<< "Status: " << LoanList[it->first].GetCurrentStatus()
			<< endl;
	}
}

void Loans::ListBooksForPatron(int patronID) {
	for (auto it = LoanList.begin(); it != LoanList.end(); it++)
	{
		if (LoanList[it->first].GetPatronID() == patronID)
		{
			cout << "Book ID: " << LoanList[it->first].GetBookID() << endl;
		}
	}
}

void Loans::UpdateLoanStatus(Books BookList, Patrons PatronList) {
	time_t now = time(0);
	tm* dx = localtime(&now);

	if (1900 + dx->tm_year > 1900 + dt->tm_year)
	{
		
	}
	else if (1 + dx->tm_mon > 1 + dt->tm_mon)
	{

	}
	else if (dt->tm_mday > dt->tm_mday)
	{
		
	}
	else
	{
		cout << "Can not update, has not been 1 day!!!" << endl;
		return;
	}
	for (auto it = LoanList.begin(); it != LoanList.end(); it++)
	{
		string stopChar = "/";
		int days = stoi(LoanList[it->first].GetDueDate().substr(0, LoanList[it->first].GetDueDate().find("/")));
		int months = stoi(LoanList[it->first].GetDueDate().substr(LoanList[it->first].GetDueDate().find("/"), nthOccurrence(LoanList[it->first].GetDueDate(), "/", 2)));
		int years = stoi(LoanList[it->first].GetDueDate().substr(nthOccurrence(LoanList[it->first].GetDueDate(), "/", 2)));

		if (dt->tm_mday > days)
			if (dt->tm_mon + 1 > months || dt->tm_mon + 1 == months)
				if (dt->tm_year + 1900 > years || dt->tm_year + 1900 == years)
				{
					LoanList[it->first].SetCurrentStatus("Overdue");
					cout << "Loan ID " << LoanList[it->first].GetLoanID() << " is now overdue!!!" << endl;

				}
				else
				{

				}
			else
			{

			}
		else
		{

		}
		cout << "Updated loan status for loan ID: " << LoanList[it->first].GetBookID() << endl;
	}
	for (auto itt = PatronList.ReturnPatronList().begin(); itt != PatronList.ReturnPatronList().end(); itt++)
	{
		PatronList.ReturnPatronList()[itt->first].SetFineBal(PatronList.ReturnPatronList()[itt->first].GetFineBal() + 0.25);
	}
	dt = dx;
}

void Loans::ReCheckBook(Patrons& PatronList, Books& BookList) {
	int patronID;
	int bookID;
	cout << "Enter Patron ID: ";
	cin >> patronID;
	if (PatronList.Search_Patron(patronID))
	{
		// Do nothing! yay!
	}
	else
	{
		cout << "Patron not found." << endl;
		cout << "Exiting option." << endl;
		return;
	}
	PatronList.GetInfo_Patron(patronID);
	cout << "----------------------" << endl;
	BookList.GetAll_Book();
	cout << "----------------------" << endl;
	cout << "Enter Book ID: ";
	cin >> bookID;
	if (BookList.IsBookUsed(bookID))
	{
		// Do nothing! yay!
	}
	else
	{
		cout << "Book is not checked by patron." << endl;
		cout << "Exiting option." << endl;
		return;
	}
	if (LoanList[bookID].GetPatronID() != patronID)
	{
		cout << "Book is not checked by patron." << endl;
		cout << "Exiting option." << endl;
		return;
	}
	if (LoanList[bookID].GetRechecked())
	{
		cout << "Book has already been rechecked, can not be rechecked!" << endl;
		cout << "Exiting option." << endl;
		return;
	}

	if (dt != NULL)
	{
	
		string newCurrentStatusYear = to_string(1900 + (int)(dt->tm_year));
		string newCurrentStatusMonth = to_string(1 + (int)(dt->tm_mon));
		string newCurrentStatusDay = to_string((int)(dt->tm_mday));
			
		string newCurrentStatus = newCurrentStatusDay + "/" + newCurrentStatusMonth + "/" + newCurrentStatusYear;
		string newDueDate = to_string(stoi(newCurrentStatusDay) + 20) + "/" + newCurrentStatusMonth + "/" + newCurrentStatusYear;

	// Day/Month/year format

		Loan newLoan(bookID, bookID, patronID, newDueDate, newCurrentStatus);
		PatronList.ReturnPatronList()[patronID].SetFineBal(PatronList.ReturnPatronList()[patronID].GetFineBal());
		LoanList[bookID] = newLoan;
		LoanList[bookID].FlopRechecked();
		cout << "Loan changed for patronID = " << patronID << endl;

	}
}

void Loans::EditLoan(int patronID) {
	// Not needed, here for clarity
	// All edit loans are made in other files, if u need to edit it you can do so from other places
	// Nothing needed here
}

void Loans::ReportLost(Patrons& PatronList, Books& BookList) {
	int patronID;
	int bookID;
	cout << "Enter Patron ID: ";
	cin >> patronID;
	if (PatronList.Search_Patron(patronID))
	{
		// Do nothing! yay!
	}
	else
	{
		cout << "Patron not found." << endl;
		cout << "Exiting option." << endl;
		return;
	}
	PatronList.GetInfo_Patron(patronID);
	cout << "----------------------" << endl;
	BookList.GetAll_Book();
	cout << "----------------------" << endl;
	cout << "Enter Book ID: ";
	cin >> bookID;
	if (BookList.IsBookUsed(bookID))
	{
		// Do nothing! yay!
	}
	else
	{
		cout << "Book is not checked by patron." << endl;
		cout << "Exiting option." << endl;
		return;
	}
	if (LoanList[bookID].GetPatronID() != patronID)
	{
		cout << "Book is not checked by patron." << endl;
		cout << "Exiting option." << endl;
		return;
	}
	PatronList.ReturnPatronList()[patronID].SetFineBal(PatronList.ReturnPatronList()[patronID].GetFineBal() + BookList.ReturnBookList()[bookID].GetCost());
	BookList.ReturnBookList()[bookID].SetCurrentStatus("Lost");
	cout << "Updated!" << endl;
}