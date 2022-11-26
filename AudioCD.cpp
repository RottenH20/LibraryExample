#include <iostream>
#include <string>
using namespace std;

#include "AudioCD.h"

AudioCD::AudioCD()
{
	artist = "Unknown";
	title = "Unknown";
	numTracks = -1;
	releaseDate = "Unknown";
	genre = "Unknown";
	id = -1;
	cost = -1;
	status = "Unknown"; // In, Out, Lost
	loanPeriod = -1;
}

string AudioCD::getArtist() {
	return artist;
}

string AudioCD::getTitle() {
	return title;
}

int AudioCD::getNumTracks() {
	return numTracks;
}

string AudioCD::getReleaseDate() {
	return releaseDate;
}

string AudioCD::getGenre() {
	return genre;
}

void AudioCD::setArtist(string newArtist) {
	artist = newArtist;
}

void AudioCD::setTitle(string newTitle) {
	title = newTitle;
}

void AudioCD::setNumTracks(int newNumTracks) {
	numTracks = newNumTracks;
}

void AudioCD::setReleaseDate() {
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

void AudioCD::setGenre(string newGenre) {
	genre = newGenre;
}

void AudioCD::createNewAudioCD() {
	string userString1; // Artist
	string userString2; // Title
	int userInt1; // numTracks
	// numTracks
	string userString3; // Genre
	// ID
	double userDouble1;
	// Status
	int userInt3; // Input
	int userInt2;

	cout << "Enter Artist: ";
	cin.ignore();
	getline(cin, userString1);
	setArtist(userString1);

	cout << "Enter Title: ";
	cin.ignore();
	getline(cin, userString2);
	setTitle(userString2);

	cout << "Enter Number of Tracks: ";
	cin >> userInt1;
	setNumTracks(userInt1);

	setReleaseDate();

	cout << "Enter Genre: ";
	cin.ignore();
	getline(cin, userString3);
	setGenre(userString3);

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

void AudioCD::print() {
	cout << "AudioCD" << endl;
	cout << "ID: " << id << endl;
	cout << "Artist: " << artist << endl;
	cout << "Title: " << title << endl;
	cout << "Number of Tracks: " << numTracks << endl;
	cout << "Release Date: " << releaseDate << endl;
	cout << "Genre: " << genre << endl;
	cout << "Cost: " << cost << endl;
	cout << "Status: " << status << endl;
	cout << "Loan Period: " << loanPeriod << endl;
}