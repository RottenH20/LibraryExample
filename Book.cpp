#include <iostream>
#include <string>
using namespace std;

#include "Book.h"

Book::Book()
{
	author = "Unknown";
	title = "Unknown";
	ISBNnumber = -1;
	id = -1;
	cost = -1;
	status = "Unknown";
	category = "Unknown";
	loanPeriod = -1;
}

Book::Book(string newAuthor, string newTitle, int newISBNnumber, int newlibIDnumber, double newCost, string newCurrentStatus, string newCategory) {
	author = newAuthor;
	title = newTitle;
	ISBNnumber = newISBNnumber;
	id = newlibIDnumber;
	cost = newCost;
	status = newCurrentStatus;
	category = newCategory;
}

void Book::SetAuthor(string	newAuthor) {
	author = newAuthor;
}

void Book::SetTitle(string newTitle) {
	title = newTitle;
}

void Book::SetISBN(int newISBN) {
	ISBNnumber = newISBN;
}

void Book::SetLibID(int newLibID) {
	id = newLibID;
}

void Book::SetCost(double newCost) {
	cost = newCost;
}

void Book::SetCurrentStatus(string newStatus) {
	status = newStatus;
}

string Book::GetAuthor() {
	return author;
}

string Book::GetTitle() {
	return title;
}

int Book::GetISBN() {
	return ISBNnumber;
}

int Book::GetLibID() {
	return id;
}

double Book::GetCost() {
	return cost;
}

string Book::GetCurrentStatus() {
	return status;
}

string Book::GetCategory() {
	return category;
}

void Book::SetCategory(string newCategory) {
	category = newCategory;
}

void Book::print() {
	cout << "ID: " << id << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "ISBN: " << ISBNnumber << endl;
	cout << "Category: " << category << endl;
	cout << "Cost: " << cost << endl;
	cout << "Status: " << status << endl;
	cout << "Loan Period: " << loanPeriod << endl;
}