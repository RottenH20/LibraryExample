#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#include "Patron.h"
#include "Patrons.h"

Patrons::Patrons()
{
	currentTracker = 100000;
	map<int, Patron> PatronList;
}

void Patrons::Add_Patron(string newName) {
	string name;
	Patron newPatron(newName, currentTracker, 0, 0);
	PatronList.insert({ currentTracker, newPatron });
	cout << "Added patron successfully | Patron ID = " << currentTracker << endl;
	IncreaseTrackerCount();
}

void Patrons::Edit_Patron(int newPatronID) {
	int userInput = 5;
	cout << "What to change? (1 = Name, 2 = FineBalance, 3 = #BooksBorrowed, 4 = Nothing): ";
	cin >> userInput;
	while (1)
	{
		if (userInput > 4 || userInput < 1)
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
			cout << "Enter new name: ";
			cin.ignore();
			getline(cin, userInput3);
			PatronList[newPatronID].SetName(userInput3);
			cout << "Name changed." << endl;
			break;
		case 2:
			cout << "Enter new FineBalance: ";
			cin >> userInput2;
			PatronList[newPatronID].SetFineBal(userInput2);
			cout << "FineBalance changed." << endl;
			break;
		case 3:
			cout << "Enter new #BooksBorrowed: ";
			cin >> userInput2;
			PatronList[newPatronID].SetBooksOut(userInput2);
			cout << "#BooksBorrowed changed."<< endl;
			break;
		case 4:
			break;
		default:
			cout << "This should never be displayed!!!" << endl;
	}
}

void Patrons::Delete_Patron(int newPatronID) {
	if (PatronList.find(newPatronID) != PatronList.end())
	{
		PatronList.erase(newPatronID);
		cout << "Deleted Patron." << endl;
	}
	else
	{
		cout << "Patron not found." << endl;
	}
}

bool Patrons::Search_Patron(int newPatronID) {
	if (PatronList.find(newPatronID) != PatronList.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Patrons::GetAll_Patron() {
	int i = 1;
	for (auto x : PatronList) {
		cout << "Name " << i << ": " << PatronList[x.first].GetName() << endl;
		i++;
	}
}

void Patrons::GetInfo_Patron(int newPatronID) {
	if (PatronList.find(newPatronID) != PatronList.end())
	{
		cout << "Patron Name: " << PatronList[newPatronID].GetName() << endl;
		cout << "Patron ID: " << PatronList[newPatronID].GetIDNum() << endl;
		cout << "Patron Bal: " << PatronList[newPatronID].GetFineBal() << endl;
		cout << "Patron #BooksOut: " << PatronList[newPatronID].GetBooksOut() << endl;
	}
	else
	{
		cout << "Patron not found." << endl;
	}
}

int Patrons::GetTrackerCount() {
	return currentTracker;
}

void Patrons::IncreaseTrackerCount() {
	currentTracker++;
}

void Patrons::PayFines(int newPatronID) {
	PatronList[newPatronID].SetFineBal(0);
}

map<int, Patron>& Patrons::ReturnPatronList() {
	map<int, Patron>& PatronLists = PatronList;
	return PatronLists;
}