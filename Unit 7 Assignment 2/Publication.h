// Kayla Stiver
// CIS 1202 800
// April 25th 2022

#pragma once
#include <iostream>
#include <string>

using namespace std;

enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

class Publication {
private:
	string title = "Example Title";
	string publisher = "Example Publisher";
	float price = 9.99;
	int year = 2000;
	PublicationType type = BOOK; //if enum class is used the << operator breaks later in the program
	int stock = 10;

public:
	void storePublication(string itemTitle, string itemPublisher, float itemPrice, int itemYear, PublicationType itemType, int itemStock);
	void displayInfo();
	void checkOut();
	void checkIn();
	string getTitle();
	int getStock();
};