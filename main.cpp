#include <string>
#include <list>
#include <iostream>
#include <ctime>
using namespace std;

#pragma warning(disable : 4996)

#include "Books.h"
#include "Book.h"
#include "Patron.h"
#include "Loan.h"
#include "Patrons.h"
#include "Loans.h"
#include "LibraryItem.h"
#include "DVD.h"
#include "AudioCD.h"

void printAudioCD(map<int, AudioCD> &AudioCDitems) {
	for (int i = 0; i < AudioCDitems.size(); i++) {
		if (AudioCDitems[i].getID() == -1)
		{

		}
		else
		{
			AudioCDitems[i].print();
			cout << "------------------------------" << endl;
		}
	}
}

void insertAudioCD(AudioCD item, map<int, AudioCD> &AudioCDitems, int tracker) { // Remember to increase Tracker
	AudioCDitems.insert({ tracker, item });
}

void addAudioCD(int tracker, map<int, AudioCD> &AudioCDitems) { 
	AudioCD newAudioCD;
	newAudioCD.createNewAudioCD();
	newAudioCD.setID(tracker);
	insertAudioCD(newAudioCD, AudioCDitems, tracker);
	cout << "Created new AudioCD with unique ID: " << tracker << endl;
}

void editAudioCD(int newlibIDnumber, map<int, AudioCD> &AudioCDitems) {
	int userInput = 9;

	if (AudioCDitems.find(newlibIDnumber) != AudioCDitems.end())
	{

	}
	else
	{
		cout << "AudioCD not found." << endl;
		return;
	}

	cout << "Currently" << endl;
	AudioCDitems[newlibIDnumber].print();

	cout << "What to change? (1 = Artist, 2 = Title, 3 = NumTracks, 4 = Release Date, 5 = Genre, 6 = Cost, 7 = Status, 8 = Loan Period, 9 = Nothing): ";
	cin >> userInput;
	while (1)
	{
		if (userInput > 9 || userInput < 1)
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
	double userDouble1;
	switch (userInput)
	{
	case 1:
		cout << "Enter new Artist: ";
		cin.ignore();
		getline(cin, userInput3);
		AudioCDitems[newlibIDnumber].setArtist(userInput3);
		cout << "Artist changed." << endl;
		break;
	case 2:
		cout << "Enter new Title: ";
		cin.ignore();
		getline(cin, userInput3);
		AudioCDitems[newlibIDnumber].setTitle(userInput3);
		cout << "Title changed." << endl;
		break;
	case 3:
		cout << "Enter new NumTracks: ";
		cin >> userInput2;
		AudioCDitems[newlibIDnumber].setNumTracks(userInput2);
		cout << "NumTracks changed." << endl;
		break;
	case 4:
		AudioCDitems[newlibIDnumber].setReleaseDate();
		break;
	case 7:
		cout << "Enter new CurrentStatus (1 = In, 2 = Out, 3 = Repair, 4 = Lost): ";
		userInput = 0;
		cin >> userInput;
		while (1)
		{
			if (userInput > 4 || userInput < 1)
			{
				cout << "Incorrect response, try again: ";
				cin >> userInput;
			}
			else
			{
				break;
			}
		}
		if (userInput == 1)
			AudioCDitems[newlibIDnumber].setStatus("In");
		if (userInput == 2)
			AudioCDitems[newlibIDnumber].setStatus("Out");
		if (userInput == 3)
			AudioCDitems[newlibIDnumber].setStatus("Repair");
		if (userInput == 4)
			AudioCDitems[newlibIDnumber].setStatus("Lost");
		break;
	case 5:
		cout << "Enter new Genre: ";
		cin.ignore();
		getline(cin, userInput3);
		AudioCDitems[newlibIDnumber].setGenre(userInput3);
		cout << "Genre changed." << endl;
		break;
	case 6:
		cout << "Enter new Cost: ";
		cin >> userDouble1;
		AudioCDitems[newlibIDnumber].setCost(userDouble1);
		cout << "Cost changed." << endl;
	case 8:
		cout << "Enter new Loan Period: ";
		cin >> userInput2;
		AudioCDitems[newlibIDnumber].setLoanPeroid(userInput2);
		cout << "Loan Period changed." << endl;
	default:
		cout << endl;
	}
}

//---------------------------------------------------------

void printDVD(map<int, DVD> &DVDitems) {
	for (int i = 0; i < DVDitems.size(); i++) {
		if (DVDitems[i].getID() == -1)
		{

		}
		else
		{
			DVDitems[i].print();
			cout << "------------------------------" << endl;
		}
	}
}

void insertDVD(DVD item, map<int, DVD> &DVDitems, int tracker) { // Remember to increase Tracker
	DVDitems.insert({ tracker, item });
}

void addDVD(int tracker, map<int, DVD> &DVDitems) {
	DVD newDVD;
	newDVD.createDVD();
	newDVD.setID(tracker);
	insertDVD(newDVD, DVDitems, tracker);
	cout << "Created new DVD with unique ID: " << tracker << endl;
}

void editDVD(int newlibIDnumber, map<int, DVD> &DVDitems) {
	int userInput = 9;

	if (DVDitems.find(newlibIDnumber) != DVDitems.end())
	{

	}
	else
	{
		cout << "DVD not found." << endl;
		return;
	}

	cout << "Currently" << endl;
	DVDitems[newlibIDnumber].print();

	cout << "What to change? (1 = Title, 2 = Category, 3 = Run Time, 4 = Studio, 5 = Release Date, 6 = Cost, 7 = Status, 8 = Loan Period, 9 = Nothing): ";
	cin >> userInput;
	while (1)
	{
		if (userInput > 9 || userInput < 1)
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
	double userDouble1;
	switch (userInput)
	{
	case 1:
		cout << "Enter new Title: ";
		cin.ignore();
		getline(cin, userInput3);
		DVDitems[newlibIDnumber].setTitle(userInput3);
		cout << "Title changed." << endl;
		break;
	case 2:
		cout << "Enter new Category: ";
		cin.ignore();
		getline(cin, userInput3);
		DVDitems[newlibIDnumber].setCategory(userInput3);
		cout << "Category changed." << endl;
		break;
	case 3:
		cout << "Enter new RunTime: ";
		cin >> userInput2;
		DVDitems[newlibIDnumber].setRunTime(userInput2);
		cout << "RunTime changed." << endl;
		break;
	case 4:
		cout << "Enter new Studio: ";
		cin.ignore();
		getline(cin, userInput3);
		DVDitems[newlibIDnumber].setStudio(userInput3);
		cout << "Studio changed." << endl;
		break;
	case 7:
		cout << "Enter new CurrentStatus (1 = In, 2 = Out, 3 = Repair, 4 = Lost): ";
		userInput = 0;
		cin >> userInput;
		while (1)
		{
			if (userInput > 4 || userInput < 1)
			{
				cout << "Incorrect response, try again: ";
				cin >> userInput;
			}
			else
			{
				break;
			}
		}
		if (userInput == 1)
			DVDitems[newlibIDnumber].setStatus("In");
		if (userInput == 2)
			DVDitems[newlibIDnumber].setStatus("Out");
		if (userInput == 3)
			DVDitems[newlibIDnumber].setStatus("Repair");
		if (userInput == 4)
			DVDitems[newlibIDnumber].setStatus("Lost");
		break;
	case 5:
		DVDitems[newlibIDnumber].setReleaseDate();
		break;
	case 6:
		cout << "Enter new Cost: ";
		cin >> userDouble1;
		DVDitems[newlibIDnumber].setCost(userDouble1);
		cout << "Cost changed." << endl;
	case 8:
		cout << "Enter new Loan Period: ";
		cin >> userInput2;
		DVDitems[newlibIDnumber].setLoanPeroid(userInput2);
		cout << "Loan Period changed." << endl;
	default:
		cout << endl;
	}
}

//---------------------------------------------------------------------------

int main() {
	map<int, AudioCD> AudioCDitems;
	map<int, DVD> DVDitems;

	int tracker32 = 1; // Not 32 different trackers, just needed unique name

	time_t now = time(0);
	tm *dt = localtime(&now);
	
	Loans LoansList(dt);
	Patrons Patronslist;
	Books Bookslist;

	string userString;
	string userString2;
	string userString5;
	int userInt;
	int userInt2;
	int userInt3;

	//------------------------------------------------------------------------

	while (1)
	{
		cout << "-----------------------------------------------" << endl;
		cout << "Welcome to library system!" << endl;
		cout << "(Loans = 1, Patrons = 2, LibraryItems = 3)" << endl;
		cout << "What would you like to do?: ";
		cin >> userInt;
		switch (userInt)
		{
			case 1:
				cout << "-------------" << endl;
				cout << "Loans Menu" << endl;
				cout << "(1 = List all overdue, 2 = Update Loan Status (system clock), 3 = List Owed for Patron, 4 = Check-In Item, 5 = Check-Out Item, 6 = Re-Check Item, 7 = Report Item Lost, 8  = Go back)" << endl;
				cout << "What would you like to do?: ";
				cin >> userInt;
				switch (userInt)
				{
					case 1:
						LoansList.ListAllOverdue();
						break;
					case 2:
						LoansList.UpdateLoanStatus(Bookslist, Patronslist);
						break;
					case 3:
						cout << "Enter Patron ID: ";
						cin >> userInt;
						LoansList.ListBooksForPatron(userInt);
						break;
					case 4:
						LoansList.CheckInBook(Patronslist, Bookslist);
						break;
					case 5:
						LoansList.CheckOutBook(Patronslist, Bookslist);
						break;
					case 6:
						LoansList.ReCheckBook(Patronslist, Bookslist);
						break;
					case 7:
						LoansList.ReportLost(Patronslist, Bookslist);
						break;
					default:
						break;
				}
				break;
			case 2:
				cout << "-------------" << endl;
				cout << "Patrons Menu" << endl;
				cout << "(1 = Add Patron, 2 = Delete Patron, 3 = Edit Patron, 4 = Display All Patrons, 5 = Display A Patron, 6 = Go back)" << endl;
				cout << "What would you like to do? ";
				cin >> userInt;
				switch (userInt)
				{
				case 1:
					cout << "Enter name for new Patron: ";
					cin.ignore();
					getline(cin, userString);
					Patronslist.Add_Patron(userString);
					break;
				case 2:
					cout << "Enter patron ID: ";
					cin >> userInt;
					Patronslist.Delete_Patron(userInt);
					break;
				case 3:
					cout << "Enter patron ID: ";
					cin >> userInt;
					Patronslist.Edit_Patron(userInt);
					break;
				case 4:
					Patronslist.GetAll_Patron();
					break;
				case 5:
					cout << "Enter patron ID: ";
					cin >> userInt;
					Patronslist.GetInfo_Patron(userInt);
					break;
				default:
					break;
				}
				break;
			case 3:
				cout << "-------------" << endl;
				cout << "Library Items Menu" << endl;
				cout << "(1 = Audio CD, 2 = DVD, 3 = Book, 4 = Print all items, 5 = Go back)" << endl;
				cout << "What would you like to do? ";
				cin >> userInt;
				switch (userInt)
				{
					case 1:
						cout << "-------------" << endl;
						cout << "Audio CD Menu" << endl;
						cout << "(1 = Add Audio CD, 2 = Delete Audio CD, 3 = Edit Audio CD, 4 = Display All Audio CD's, 5 = Display A Audio CD, 6 = Go back)" << endl;
						cout << "What would you like to do? ";
						cin >> userInt;
						switch (userInt)
						{
							case 1:
								addAudioCD(tracker32, AudioCDitems);
								tracker32++;
								break;
							case 2:
								cout << "Enter AudioCD ID: ";
								cin >> userInt;
								if (AudioCDitems.find(userInt) != AudioCDitems.end())
								{
									AudioCDitems.erase(userInt);
									cout << "Deleted AudioCD." << endl;
								}
								else
								{
									cout << "AudioCD not found." << endl;
								}
								break;
							case 3:
								cout << "Enter AudioCD ID: ";
								cin >> userInt;
								editAudioCD(userInt, AudioCDitems);
								break;
							case 4:
								printAudioCD(AudioCDitems);
								break;
							case 5:
								cout << "Enter AudioCD ID: ";
								cin >> userInt;
								if (AudioCDitems.find(userInt) != AudioCDitems.end())
								{
									AudioCDitems[userInt].print();
								}
								else
								{
									cout << "AudioCD not found." << endl;
								}
								break;
							default:
								break;
						}
						break;
					case 2:
						cout << "-------------" << endl;
						cout << "DVD Menu" << endl;
						cout << "(1 = Add DVD, 2 = Delete DVD, 3 = Edit DVD, 4 = Display All DVD's, 5 = Display A DVD, 6 = Go back)" << endl;
						cout << "What would you like to do? ";
						cin >> userInt;
						switch (userInt)
						{
							case 1:
								addDVD(tracker32, DVDitems);
								tracker32++;
								break;
							case 2:
								cout << "Enter DVD ID: ";
								cin >> userInt3;
								if (DVDitems.find(userInt3) != DVDitems.end())
								{
									DVDitems.erase(userInt3);
									cout << "Deleted DVD." << endl;
								}
								else
								{
									cout << "DVD not found." << endl;
								}
								break;
							case 3:
								cout << "Enter DVD ID: ";
								cin >> userInt;
								editDVD(userInt, DVDitems);
								break;
							case 4:
								printDVD(DVDitems);
								break;
							case 5:
								break;
							default:
								break;
						}
						break;
					case 3:
						cout << "-------------" << endl;
						cout << "Book Menu" << endl;
						cout << "(1 = Add Book, 2 = Delete Book, 3 = Edit Book, 4 = Display All Books, 5 = Display A Book, 6 = Go back)" << endl;
						cout << "What would you like to do? ";
						cin >> userInt;
						switch (userInt)
						{
						case 1:
							cout << "Enter Author: ";
							cin.ignore();
							getline(cin, userString);
							cout << "Enter Title: ";
							cin.ignore();
							getline(cin, userString2);
							cout << "Enter ISBNnumber: ";
							cin >> userInt;
							cout << "Enter Cost: ";
							cin >> userInt2;
							cout << "Enter Category: ";
							cin.ignore();
							getline(cin, userString5);
							Bookslist.Add_Book(userString, userString2, userInt, userInt2, userString5, tracker32);
							break;
						case 2:
							cout << "Enter Book ID: ";
							cin >> userInt;
							Bookslist.Delete_Book(userInt);
							break;
						case 3:
							cout << "Enter Book ID: ";
							cin >> userInt;
							Bookslist.Edit_Book(userInt);
							break;
						case 4:
							Bookslist.GetAll_Book();
							break;
						case 5:
							cout << "Enter Book ID: ";
							cin >> userInt;
							Bookslist.GetInfo_Book(userInt);
							break;
						default:
							break;
						}
						break;
					case 4:
						printAudioCD(AudioCDitems);
						printDVD(DVDitems);
					default:
						break;
				}
				break;
			default:
				cout << "Not a valid option!" << endl;
				break;
		}
	}

	return 0;
}