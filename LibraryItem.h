#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LibraryItem
{
    protected:
        int id;
        double cost;
        string status; // In, Out, Lost
        int loanPeriod;
    public:
        LibraryItem();
        LibraryItem(int newID, double newCost, string newStatus, int newLoanPeriod);
        int getID();
        double getCost();
        string getStatus();
        int getLoanPeroid();
        void setID(int newID);
        void setCost(double newCost);
        void setStatus(string newStatus);
        void setLoanPeroid(int newLoanPeroid);
        virtual void print();
};

#endif