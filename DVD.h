#ifndef DVD_H
#define DVD_H

#include <string>
#include <iostream>
#include <vector>
#include "LibraryItem.h"

using namespace std;

class DVD : public LibraryItem {
private:
    string title;
    string category;
    int runTime;
    string studio;
    string releaseDate;
public:
    DVD();
    void createDVD();
    string getTitle();
    string getCategory();
    int getRunTime();
    string getStudio();
    string getReleaseDate();
    void setTitle(string newTitle);
    void setCategory(string newCategory);
    void setRunTime(int newRunTime);
    void setStudio(string newStudio);
    void setReleaseDate();
    void print();
};

#endif