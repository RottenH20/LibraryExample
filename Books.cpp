#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#include "Book.h"
#include "Books.h"

Books::Books()
{
	map<int, Book> BookList;
}

void Books::Add_Book(string newAuthor, string newTitle, int newISBNnumber, double newCost, string newCategory, int &currentTracker) {
	Book newBook(newAuthor, newTitle, newISBNnumber, currentTracker, newCost, "In", newCategory);
	BookList.insert({ currentTracker, newBook });
	cout << "Added book successfully | library ID number = " << currentTracker << endl;
	currentTracker++;
}

void Books::Edit_Book(int newlibIDnumber) {
	int userInput = 7;
	cout << "Currently" << endl << "Author = " << BookList[newlibIDnumber].GetAuthor() << ", Title = " << BookList[newlibIDnumber].GetTitle() << ", ISBNnumber = " << BookList[newlibIDnumber].GetISBN();
	cout << " , Cost = " << BookList[newlibIDnumber].GetCost() << " , CurrentStatus = " << BookList[newlibIDnumber].GetCurrentStatus() << endl;
    cout << "What to change? (1 = Author, 2 = Title, 3 = ISBNnumber, 4 = Cost, 5 = CurrentStatus, 6 = Category, 7 = Nothing): ";
	cin >> userInput;
	while (1)
	{
		if (userInput > 6 || userInput < 1)
		{
			cout << "Incorrect value, try again: ";
			cin >> userInput;
		}
		else
		{
			break;
		}
	}
	int userInput2;
	string userInput3;
	switch (userInput)
	{
	case 1:
		cout << "Enter new Author: ";
		cin.ignore();
		getline(cin, userInput3);
		BookList[newlibIDnumber].SetAuthor(userInput3);
		cout << "Author changed." << endl;
		break;
	case 2:
		cout << "Enter new Title: ";
		cin.ignore();
		getline(cin, userInput3);
		BookList[newlibIDnumber].SetTitle(userInput3);
		cout << "Title changed." << endl;
		break;
	case 3:
		cout << "Enter new ISBNnumber: ";
		cin >> userInput2;
		BookList[newlibIDnumber].SetISBN(userInput2);
		cout << "#BooksBorrowed changed." << endl;
		break;
	case 4:
		cout << "Enter new Cost: ";
		cin >> userInput2;
		BookList[newlibIDnumber].SetCost(userInput2);
		cout << "Cost changed." << endl;
		break;
	case 5:
		cout << "Enter new CurrentStatus (1 = In, 2 = Out, 3 = Repair, 4 = Lost): ";
		userInput = 0;
		cin >> userInput;
		while (1)
		{
			if (userInput > 4 || userInput < 1)
			{
				cout << "Incorrect response, try again: ";
				cin >> userInput;
			}
			else
			{
				break;
			}
		}
		if (userInput == 1)
			BookList[newlibIDnumber].SetCurrentStatus("In");
		if (userInput == 2)
			BookList[newlibIDnumber].SetCurrentStatus("Out");
		if (userInput == 3)
			BookList[newlibIDnumber].SetCurrentStatus("Repair");
		if (userInput == 4)
			BookList[newlibIDnumber].SetCurrentStatus("Lost");
		break;
	case 6:
		cout << "Enter new Category: ";
		cin.ignore();
		getline(cin, userInput3);
		BookList[newlibIDnumber].SetCategory(userInput3);
		cout << "Category changed." << endl;
		break;
	default:
		cout << "This should never be displayed!!!" << endl;
	}
}

void Books::Delete_Book(int newlibIDnumber) {
	if (BookList.find(newlibIDnumber) != BookList.end())
	{
		BookList.erase(newlibIDnumber);
		cout << "Deleted Book." << endl;
	}
	else
	{
		cout << "Book not found." << endl;
	}
}

bool Books::Search_Book(int newlibIDnumber) {
	if (BookList.find(newlibIDnumber) != BookList.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Books::GetAll_Book() {
	int i = 1;
	for (auto x : BookList) {
		cout << "Title " << i << ": " << BookList[x.first].GetTitle() << endl;
		i++;
	}
}

void Books::GetInfo_Book(int newlibIDnumber) {
	if (BookList.find(newlibIDnumber) != BookList.end())
	{
		cout << "Book Author: " << BookList[newlibIDnumber].GetAuthor() << endl;
		cout << "Book Title: " << BookList[newlibIDnumber].GetTitle() << endl;
		cout << "Book Category: " << BookList[newlibIDnumber].GetCategory() << endl;
		cout << "Book ISBNnumber: " << BookList[newlibIDnumber].GetISBN() << endl;
		cout << "Book libIDNumber: " << BookList[newlibIDnumber].GetLibID() << endl;
		cout << "Book Cost: " << BookList[newlibIDnumber].GetCost() << endl;
		cout << "Book CurrentStatus: " << BookList[newlibIDnumber].GetCurrentStatus() << endl;
	}
	else
	{
		cout << "Book not found." << endl;
	}
}

bool Books::IsBookUsed(int newlibIDnumber) {
	if (Search_Book(newlibIDnumber))
	{
		string currentStatus = BookList[newlibIDnumber].GetCurrentStatus();
		if (currentStatus != "Out" || currentStatus != "Repair" || currentStatus != "Lost")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

map<int, Book> Books::ReturnBookList() {
	return BookList;
}