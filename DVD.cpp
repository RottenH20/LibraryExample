#include <iostream>
#include <string>
using namespace std;

#include "DVD.h"

DVD::DVD()
{
	title = "Unknown";
	category = "Unknown";
	runTime = 0;
	studio = "Unknown";
	releaseDate = "Unknown";
	id = -1;
	cost = -1;
	status = "Unknown"; // In, Out, Lost
	loanPeriod = -1;
}

string DVD::getTitle() {
	return title;
}

string DVD::getCategory() {
	return category;
}

int DVD::getRunTime() {
	return runTime;
}

string DVD::getStudio() {
	return studio;
}

string DVD::getReleaseDate() {
	return releaseDate;
}

void DVD::setTitle(string newTitle) {
	title = newTitle;
}

void DVD::setCategory(string newCategory) {
	category = newCategory;
}

void DVD::setRunTime(int newRunTime) {
	runTime = newRunTime;
}

void DVD::setStudio(string newStudio) {
	studio = newStudio;
}

void DVD::createDVD() {
	string userString1; // Title
	string userString2; // Category
	int userInt1; // RunTime
	string userString3; // Studio
	// ReleaseDate
	// ID
	double userDouble1; // Cost
	// Status
	int userInt2; // LoanPeriod
	int userInt3; // Input

	cout << "Enter Title: ";
	cin.ignore();
	getline(cin, userString1);
	setTitle(userString1);

	cout << "Enter Category: ";
	cin.ignore();
	getline(cin, userString2);
	setCategory(userString2);

	cout << "Enter RunTime: ";
	cin >> userInt1;
	setRunTime(userInt1);

	cout << "Enter Studio: ";
	cin.ignore();
	getline(cin, userString3);
	setStudio(userString3);

	setReleaseDate();

	cout << "Enter Cost: ";
	cin >> userDouble1;
	setCost(userDouble1);

	cout << "Enter Status (1 = In, 2 = Out, 3 = Repair, 4 = Lost): ";
	cin >> userInt3;
	while (1)
	{
		if (userInt3 > 4 || userInt3 < 1)
		{
			cout << "Incorrect response, try again: ";
			cin >> userInt3;
		}
		else
		{
			break;
		}
	}
	if (userInt3 == 1)
		setStatus("In");
	if (userInt3 == 2)
		setStatus("Out");
	if (userInt3 == 3)
		setStatus("Repair");
	if (userInt3 == 4)
		setStatus("Lost");

	cout << "Enter Loan Period: ";
	cin >> userInt2;
	setLoanPeroid(userInt2);
}

void DVD::setReleaseDate() {
	cout << "Enter month (format, 1, 2, 3...): ";
	int month;
	cin >> month;
	while (month > 12)
	{
		cout << "Month can't be greater than 12, try again: ";
		cin >> month;
	}
	cout << "Enter day (format, 1, 2, 3...): ";
	int day;
	cin >> day;
	while (day > 31)
	{
		cout << "Day can't be greater than 31, try again: ";
		cin >> day;
	}
	cout << "Enter year (format, 2012, 2013...): ";
	int year;
	cin >> year;
	while (year < 0)
	{
		cout << "Year can't be less than 0, try again: ";
		cin >> year;
	}

	string complete = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

	cout << "Date set to " << complete << endl;
	cout << "Format = Day/Month/Year" << endl;

	releaseDate = complete;
}

void DVD::print() {
	cout << "DVD" << endl;
	cout << "ID: " << id << endl;
	cout << "Title: " << title << endl;
	cout << "Category: " << category << endl;
	cout << "Run Time: " << runTime << endl;
	cout << "Studio: " << studio << endl;
	cout << "Release Date: " << releaseDate << endl;
	cout << "Cost: " << cost << endl;
	cout << "Status: " << status << endl;
	cout << "Loan Period: " << loanPeriod << endl;
}