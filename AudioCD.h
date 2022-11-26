#ifndef AUDIOCD_H
#define AUDIOCD_H

#include <string>
#include <iostream>
#include <vector>
#include "LibraryItem.h"

using namespace std;

class AudioCD : public LibraryItem {
private:
    string artist;
    string title;
    int numTracks;
    string releaseDate;
    string genre;
public:
    AudioCD();
    string getArtist();
    string getTitle();
    int getNumTracks();
    string getReleaseDate();
    string getGenre();
    void setArtist(string newArtist);
    void setTitle(string newTitle);
    void setNumTracks(int newNumTracks);
    void setReleaseDate();
    void setGenre(string newGenre);
    void print();
    void createNewAudioCD();
};

#endif