//                goumana 
#include "Inventory.h"
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void Inventory::lowstockalert(int threshold) {

}


void printHeader(string title) {
    cout << "\n--- " << title << " ---" << endl;
}

int main() {
    Inventory myInv;

    // 1. Add Product
    printHeader("Add Product");
    myInv.addproduct(101, "Laptop", 10, 1200.0);
    cout << "Product 101 added." << endl;

    // 2. Duplicate ID
    printHeader("Duplicate ID Check");
    myInv.addproduct(101, "Keyboard", 5, 50.0);
    cout << "Attempted to add duplicate 101." << endl;

    // 3. Update Quantity
    printHeader("Update Quantity");
    myInv.updatequantity(101, 5);
    myInv.updatequantity(101, -100);
    cout << "Quantities updated (Check logic for negative values)." << endl;

    // 4. Low Stock Alert
    printHeader("Low Stock Alert");
    myInv.addproduct(102, "Mouse", 2, 20.0);
    myInv.lowstockalert(5);

    // 5. Display
    printHeader("Display Inventory");
    myInv.displayinventory();

    // 6. Save and Remove
    printHeader("File & Remove Operations");
    myInv.saveToFile("data.txt");
    myInv.removeproduct(101);
    myInv.removeproduct(999);
    cout << "Save and Remove operations executed." << endl;

    // 7. Integration Test
    printHeader("FULL INTEGRATION TEST");
    Inventory finalTest;
    finalTest.addproduct(1, "bbbb", 50, 1.5);
    finalTest.addproduct(2, "aaaa", 2, 3.0);
    finalTest.updatequantity(1, -10);
    finalTest.displayinventory();
    finalTest.lowstockalert(10);

    cout << "\n>>> ALL TESTS EXECUTED <<<" << endl;

    return 0;
}