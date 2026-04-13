#include "Inventory.h"
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include<sstream>
#include <iomanip>
#include "Product.h"
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
void Inventory::updatequantity(int id, int quantity)
{
    // Check if quantity is negative
    if (quantity < 0)
    {
        cout << "Error: Quantity cannot be negative." << endl;
        return;
    }

    // Search for the product by ID
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getId() == id)
        {
            products[i].setQuantity(quantity);
            cout << "Quantity updated successfully." << endl;
            return;
        }
    }

    // If product not found
    cout << "Error: Product with ID " << id << " not found." << endl;
}
//     Habiba
void Inventory::removeproduct(int id) {
    // Search for the product using an iterator
    auto it = products.begin();
    bool found = false;

    while (it != products.end()) {
        if (it->getId() == id) {
            //  Product found: remove it
            it = products.erase(it);
            cout << "Product ID " << id << " removed successfully." << endl;
            found = true;
            break; // Stop searching once found and removed
        }
        else {
            ++it;
        }
    }
    // Error Handling: if the loop finishes without finding the ID
    if (!found) {
        cout << "Error: Product ID " << id << " not found." << endl;
    }
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


//--- -------------   hoss            Team B
void Inventory::lowStockAlert(int threshold) {
    bool foundLowStock = false;

    for (const Product& p : products) {
        if (p.getQuantity() <= threshold) {
            cout << "LOW STOCK ALERT!\n";
            cout << "ID: " << p.getId() << endl;
            cout << "Name: " << p.getName() << endl;
            cout << "Price: " << p.getPrice() << endl;
            cout << "Quantity: " << p.getQuantity() << endl;
            cout << "------------------------\n";
            foundLowStock = true;
        }
    }

    if (!foundLowStock) {
        cout << "All products are sufficiently stocked.\n";
    }
}



