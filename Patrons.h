#ifndef PATRONS_H
#define PATRONS_H

#include <string>
#include <iostream>
#include <map>
using namespace std;

#include "Patron.h"

class Patrons {
private:
    int currentTracker;
    map<int, Patron> PatronList;
public:
    Patrons();
    void Add_Patron(string newName);
    void Edit_Patron(int newPatron_ID);
    void Delete_Patron(int newPatronID);
    bool Search_Patron(int newPatron_ID);
    void GetAll_Patron();
    void GetInfo_Patron(int newPatronID);
    int GetTrackerCount();
    void IncreaseTrackerCount();
    void PayFines(int newPatronID);
    map<int, Patron>& ReturnPatronList();
};

#endif