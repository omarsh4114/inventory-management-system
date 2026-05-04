#include "Inventory.h"
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include<sstream>
#include <iomanip>
#include<iomanip>
using namespace std;


void Inventory::saveToFile(string IMS) {
    ofstream outFile(IMS);
    if (!outFile) {
        cout << "Error: Could not save to file!" << endl;
        return;
    }
    for (const auto& p : products) {
        outFile << p.getId() << "," << p.getName() << ","
            << p.getPrice() << "," << p.getQuantity() << endl;
    }
    outFile.close();
}

void Inventory::loadFromFile(string IMS) {
    ifstream inFile(IMS);

    // 1. Connection Check: Tell the user if the file exists
    if (!inFile) {
        cout << "Notice: Could not open '" << IMS << "'. Creating new database." << endl;
        return;
    }

    products.clear(); // Clear memory so we don't double the items on reload
    string line;
    int count = 0;

    // 2. Line-by-Line Reading
    while (getline(inFile, line)) {
        if (line.empty()) continue; // Skip blank lines at the end of the file

        stringstream ss(line);
        string idStr, name, priceStr, qtyStr;

        // 3. Parsing using Comma as the Delimiter
        if (getline(ss, idStr, ',') &&
            getline(ss, name, ',') &&
            getline(ss, priceStr, ',') &&
            getline(ss, qtyStr, ',')) {

            try {
                // Convert strings to actual numbers
                int id = stoi(idStr);
                double price = stod(priceStr);
                int qty = stoi(qtyStr);

                // Add to our vector
                products.push_back(Product(id, name, price, qty));
                count++;
            }
            catch (...) {
                cout << "Error: Skipping a corrupted line in file." << endl;
            }
        }
    }

    inFile.close();
    cout << "Success: Loaded " << count << " items from " << IMS << endl;
}
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
        cout << "Inventory is empty." << endl;
        return;
    }
    cout << "\n--- Current Inventory ---" << endl;
    for (const auto& p : products) {
        cout << "ID: " << p.getId()
            << " | Name: " << p.getName()
            << " | Price: " << p.getPrice()
            << " | Qty: " << p.getQuantity() << endl;
    }
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

    for (const Product& product : products) {
        if (product.getQuantity() <= threshold) {
            cout << "LOW STOCK ALERT!\n";
            cout << "ID: " << product.getId() << endl;
            cout << "Name: " << product.getName() << endl;
            cout << "Price: " << product.getPrice() << endl;
            cout << "Quantity: " << product.getQuantity() << endl;
            cout << "------------------------\n";
            foundLowStock = true;
        }
    }

    if (!foundLowStock) {
        cout << "All products are sufficiently stocked.\n";
    }
}

void Inventory::searchById(int id) {
    for (const auto& p : products) {
        if (p.getId() == id) {
            cout << "Product Found: " << p.getName() << " | Price: $" << p.getPrice() << endl;
            return;
        }
    }
    cout << "ID " << id << " not found in the system." << endl;
}

int Inventory::countTotalProducts() {
    return products.size(); // Returns the count of items in your vector
}

