// Kayla Stiver
// CIS 1202 800
// April 25th 2022

#include <iostream>
#include <string>
#include "Publication.h"

using namespace std;

void Publication::storePublication(string itemTitle, string itemPublisher, float itemPrice, int itemYear, PublicationType itemType, int itemStock) {
	//if enum class is used the << operator breaks later in the program
	title = itemTitle;
	publisher = itemPublisher;
	price = itemPrice;
	year = itemYear;
	type = itemType;
	stock = itemStock;
}
void Publication::displayInfo() {
	Publication item;
	cout << "Title: " << item.title;
	cout << endl;
	cout << "Publisher: " << item.publisher;
	cout << endl;
	cout << "Price: " << item.price;
	cout << endl;
	cout << "Year: " << item.year;
	cout << endl;
	cout << "Type: " << item.type;
	cout << endl;
	cout << "Stock: " << item.stock;
	cout << endl;
}
void Publication::checkOut() {
	if (stock != 0) {
		stock--;
	}
}
void Publication::checkIn() {
	stock++;
}
string Publication::getTitle() {
	return title;
}
int Publication::getStock() {
	return stock;
}
