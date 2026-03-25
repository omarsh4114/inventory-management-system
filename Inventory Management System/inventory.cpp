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
void Inventory::addproduct(int id, string name, double price, int quantity) {
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getId() == id) {
			cout << " Error! this product id already exists" << endl ;
			return;
		}
	}
	// add new product 
	Product newProduct(id, name, price, quantity);
	products.push_back(newProduct);
	cout << " Product added successfully " << endl;

}

//     Jana
void Inventory::updatequantity(int id, int quantity) {

}
//     Habiba
void Inventory::removeproduct(int id) {

}
//     rawan
void Inventory::displayinventory() {

}

double Inventory::computetotalvalue() {
	return 0.0;
}


//--- -------------               Team B

void Inventory::lowstockalert(int threshold) {

}

