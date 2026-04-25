#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;

int main() {
    Inventory myInv;
    string filename = "el_makhzan.csv";
    myInv.loadFromFile(filename);

    int choice;
    do {
        cout << "\n=== Inventory Management System ===" << endl;
        cout << "1. Add Product\n2. Update Quantity\n3. Remove Product\n4. Display Inventory" << endl;
        cout << "5. Low Stock Alert\n6. Compute Total Value\n7. Save & Exit" << endl;
        cout << "====================================" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) { // Safety check if user types a letter
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(); // Clears the 'Enter' after the choice

        if (choice == 1) {
            int id, qty; string name; double price;

            cout << "Enter Product ID: ";
            cin >> id;
            cin.ignore(); // Clears 'Enter' after ID so it doesn't skip name

            cout << "Enter Product Name: ";
            getline(cin, name);

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> qty;
            cin.ignore(); // Clear the final Enter

            myInv.addproduct(id, name, price, qty);
            cout << "--- Product Added Successfully ---" << endl;
        }
        else if (choice == 2) {
            int id, qty;
            cout << "Enter ID and New Quantity: ";
            cin >> id >> qty;
            myInv.updatequantity(id, qty);
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            myInv.removeproduct(id);
        }
        else if (choice == 4) {
            myInv.displayinventory();
        }
        else if (choice == 5) {
            int threshold;
            cout << "Enter threshold: "; cin >> threshold;
            myInv.lowStockAlert(threshold);
        }
        else if (choice == 6) {
            double total = myInv.computetotalvalue();
            cout << "Total Inventory Value: $" << total << endl;
        }
        else if (choice == 7) {
            myInv.saveToFile(filename);
            cout << "Data saved to " << filename << ". Closing..." << endl;
        }

    } while (choice != 7);

    return 0;
}