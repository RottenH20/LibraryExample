#include <iostream>
#include <string>
using namespace std;

#include "Patron.h"

Patron::Patron()
{
	name = "Unknown Unknown";
	IDNum = 999999;
	FineBal = 999999;
	BooksOut = 999999;
}

Patron::Patron(string newName, int newPatron_ID, double newFineBal, int newBookBorrow) {
	name = newName;
	IDNum = newPatron_ID;
	FineBal = newFineBal;
	BooksOut = newBookBorrow;
}

void Patron::SetName(string newName) {
	name = newName;
}

void Patron::SetIDNum(int newIDNum) {
	IDNum = newIDNum;
}

void Patron::SetFineBal(double newFineBal) {
	FineBal = newFineBal;
}

void Patron::SetBooksOut(int newBooksOut) {
	BooksOut = newBooksOut;
}

string Patron::GetName() {
	return name;
}

int Patron::GetIDNum() {
	return IDNum;
}

double Patron::GetFineBal() {
	return FineBal;
}

int Patron::GetBooksOut() {
	return BooksOut;
}