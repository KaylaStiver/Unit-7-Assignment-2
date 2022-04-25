// Kayla Stiver
// CIS 1202 800
// April 25th 2022

#include <iostream>
#include <string>
#include "Publication.h"

using namespace std;

void getPublicationInfo(Publication&);
//void getPublications(Publication[], int&);
//void showPublications(Publication[], int);
//void showTitles(Publication[], int);
//int findPublication(Publication[], int, string);
//int getMenuChoice();

int main() {

	return 0;
}
void getPublicationInfo(Publication& item) {

	string itemTitle = "";
	string itemPublisher = "";
	double itemPrice = 0.0;
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