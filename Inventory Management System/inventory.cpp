#include "Inventory.h"
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include<sstream>
#include <iomanip>
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
    if (products.empty()) {
        cout << "No products in inventory." << endl;
        return;
    }
    cout << left << setw(8) << "ID"
        << setw(20) << "Name"
        << setw(10) << "Price"
        << setw(10) << "Quantity" << endl;
    cout << string(48, '-') << endl;
    for (int i = 0; i < products.size(); i++) {
        cout << left << setw(8) << products[i].getId()
            << setw(20) << products[i].getName()
            << setw(10) << products[i].getPrice()
            << setw(10) << products[i].getQuantity() << endl;
    }
    cout << string(48, '-') << endl;

}

double Inventory::computetotalvalue() {
    double total = 0.0;
    for (int i = 0; i < products.size(); i++) {
        total += products[i].getPrice() * products[i].getQuantity();
    }
return total;
}


//--- -------------               Team B

void Inventory::lowstockalert(int threshold) {

}

