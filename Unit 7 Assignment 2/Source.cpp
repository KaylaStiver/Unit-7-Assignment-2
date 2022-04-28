// Kayla Stiver
// CIS 1202 800
// April 25th 2022

#include <iostream>
#include <string>
#include <fstream>
#include "Publication.h"

using namespace std;

void getPublicationInfo(Publication&);
void getPublications(Publication[], int&);
void showPublications(Publication[], int);
void showTitles(Publication[], int);
int findPublication(Publication[], int, string);
int getMenuChoice();

ifstream inputFile;

int main() {
	inputFile.open("itemlist.txt");
	if (!inputFile.fail()) { 
	cout << "File open" << endl;
	}

	int count = 0;
	int titlePos = 0;
	int userChoice = 0;
	string userTitle = "";
	Publication itemList[6] = {};
	getPublications(itemList, count);
	
	do {

		if (userChoice == 1) showPublications(itemList, count);

		if (userChoice == 2) showTitles(itemList, count);

		if (userChoice == 3) findPublication(itemList, count, userTitle);

		if (userChoice == 4) {
			cout << "Enter title you wish to search for: ";
			titlePos = findPublication(itemList, count, userTitle);
			if (titlePos == -1) {
				cout << "Title not found." << endl;
			}
			if (titlePos != -1) {
				itemList[titlePos].checkOut();
			}
		}

		if (userChoice == 5) {
			cout << "Enter title you wish to search for: ";
			titlePos = findPublication(itemList, count, userTitle);
			if (titlePos == -1) {
				cout << "Title not found." << endl;
			}
			if (titlePos != -1) {
				itemList[titlePos].checkOut();
			}
		}
		if (userChoice == 6) exit;

		if (userChoice > 6 || userChoice < 0) {
			cout << "Invalid menu choice. Returning to main menu." << endl;
			cout << endl;
		}

		userChoice = getMenuChoice();

	} while (userChoice != 6);


	inputFile.close();
	return 0;
}
int getMenuChoice() {
	int selection = 0;
	cout << "Publication Data - Main Menu" << endl;
	cout << "1. Display all publications." << endl;
	cout << "2. Display publication titles." << endl;
	cout << "3. Find a publication." << endl;
	cout << "4. Check out." << endl;
	cout << "5. Check in." << endl;
	cout << "6. Exit program." << endl;
	cin >> selection;
	cin.ignore();
	cout << endl;
	return selection;
}
void getPublications(Publication itemList[6], int& i) {
	string itemTitle = "";
	string itemPublisher = "";
	float itemPrice = 0.0;
	int itemYear = 2000;
	PublicationType itemType = BOOK;
	int itemTypeNum = 0;
	int itemStock = 0;

	while (inputFile >> itemTitle >> itemPublisher >> itemPrice >> itemYear >> itemTypeNum >> itemStock) {

		Publication p[6];

		if (itemTypeNum == 0) { // converts file inputted int into corresponding enum value
			itemType = BOOK;
		}
		if (itemTypeNum == 1) {
			itemType = MAGAZINE;
		}
		if (itemTypeNum == 2) {
			itemType = NEWSPAPER;
		}
		if (itemTypeNum == 3) {
			itemType = AUDIO;
		}
		if (itemTypeNum == 4) {
			itemType = VIDEO;
		}

		p[i].storePublication(itemTitle, itemPublisher, itemPrice, itemYear, itemType, itemStock);
		itemList[i] = p[i];
		i++;
	}
}
void showPublications(Publication itemList[6], int i) {
	for (i = 0; i < 6; i++) {
		itemList[i].displayInfo();
		cout << endl;
	}
}
void showTitles(Publication itemList[6], int i) {
	for (i = 0; i < 6; i++) {
		cout << "Title: " << itemList[i].getTitle() << endl;
	}
	cout << endl;
}
int findPublication(Publication itemList[6], int i, string userTitle) {
	getline(cin, userTitle);
	cout << "User Title: " << userTitle << endl;
	string currTitle = "";
	for (i = 0; i < 6; i++) {
		currTitle = itemList[i].getTitle();
		if (userTitle == currTitle) {
			itemList[i].displayInfo();
			cout << endl;
			return i;
		}
	}
	return -1;
}

void getPublicationInfo(Publication& item) {

	string itemTitle = "";
	string itemPublisher = "";
	float itemPrice = 0.0;
	int itemYear = 2000;
	string itemTypeString = "";
	int itemStock = 0;
	PublicationType itemType = BOOK;

	cout << "Please enter item information: " << endl;
	cout << "Title: ";
	getline(cin, itemTitle);
	cout << "Publisher: ";
	getline(cin, itemPublisher);
	cout << "Price: ";
	cin >> itemPrice;
	cout << "Year: ";
	cin >> itemYear;
	cout << "Type: ";
	cin >> itemTypeString;
	cout << "Stock: ";
	cin >> itemStock;
	cout << endl;

	if (itemTypeString == "Book") { // converts user inputted string into corresponding enum value
		itemType = BOOK;
	}
	if (itemTypeString == "Magazine") {
		itemType = MAGAZINE;
	}
	if (itemTypeString == "Newspaper") {
		itemType = NEWSPAPER;
	}
	if (itemTypeString == "Audio") {
		itemType = AUDIO;
	}
	if (itemTypeString == "Video") {
		itemType = VIDEO;
	}

	item.storePublication(itemTitle, itemPublisher, itemPrice, itemYear, itemType, itemStock);
}
