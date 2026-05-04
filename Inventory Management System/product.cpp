#include "Product.h"
#include <iostream>
#include <string>
using namespace std;

Product::Product(int id, string name, double price, int quantity) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

void Product::setName(string name) {
    if (name.length() >= 8 && name.length() <= 20) this->name = name;
    else cout << "Error: Name must be 8-20 characters." << endl;
}

void Product::setPrice(double price) {
    if (price >= 0) this->price = price;
    else cout << "Error: Price cannot be negative." << endl;
}

void Product::setQuantity(int quantity) {
    if (quantity >= 0) this->quantity = quantity;
    else cout << "Error: Quantity cannot be negative." << endl;
}

int Product::getId() const {
    return id; 
}
string Product::getName() const {
    return name;
}
double Product::getPrice() const {
    return price;
}
int Product::getQuantity() const { 
    return quantity; 
}
//-------------*****-------------------------
void Product::display() const {
    cout << "ID: " << id
        << " | Name: " << name
        << " | Price: $" << price
        << " | Qty: " << quantity << endl;
}