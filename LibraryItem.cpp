#include "LibraryItem.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

LibraryItem::LibraryItem() 
{
    id = 0;
    cost = 0;
    status = "Unknown"; // In, Out, Lost
    loanPeriod = 0;
}

LibraryItem::LibraryItem(int newID, double newCost, string newStatus, int newLoanPeriod) : id(newID), cost(newCost), status(newStatus), loanPeriod(newLoanPeriod)  {
    id = newID;
    cost = newCost;
    status = newStatus;
    loanPeriod = newLoanPeriod;
}

int LibraryItem::getID() {
    return id;
}

double LibraryItem::getCost() {
    return cost;
}

string LibraryItem::getStatus() {
    return status;
}

int LibraryItem::getLoanPeroid() {
    return loanPeriod;
}

void LibraryItem::setID(int newID) {
    id = newID;
}

void LibraryItem::setCost(double newCost) {
    cost = newCost;
}

void LibraryItem::setStatus(string newStatus) {
    status = newStatus;
}

void LibraryItem::setLoanPeroid(int newLoanPeriod) {
    loanPeriod = newLoanPeriod;
}

void LibraryItem::print() {
    cout << 0;
}