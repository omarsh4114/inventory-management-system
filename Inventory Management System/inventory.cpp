#include "Inventory.h"
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

//===================================================           TEAM A
//     Rana
// check if ID already exists
void inventory::addproduct(int id, string name, double price, int quantity) {
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getId() == id) {
			cout << " Error! this product id already exists" << endl ;
			return;
		}
	}
	// add new product 
	Product newProduct(int id, string name, double price, int quantity);
	cout << " Product added successfully " << endl;

	// display all products ( gad3na meny )
	void displayInventory() {
		for (int i = 0; i < products.size; i++) {
			products[i].display();
		}
	}
}

//     Jana
void inventory::updatequantity(int id, int quantity) {

}
//     Habiba
void inventory::removeproduct(int id) {

}
//     rawan
void inventory::displayinventory() {

}

double inventory::computetotalvalue() {

}


//--- -------------               Team B

void inventory::lowstockalert(int threshold) {

}
