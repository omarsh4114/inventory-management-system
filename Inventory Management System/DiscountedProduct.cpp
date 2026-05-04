#include "DiscountedProduct.h"
#include <iostream>

using namespace std;

DiscountedProduct::DiscountedProduct(int id, string name, double price, int quantity, double disc)
    : Product(id, name, price, quantity) { // Calling the parent constructor
    this->discountPercent = disc;
}

void DiscountedProduct::display() const {
    double finalPrice = getPrice() * (1 - (discountPercent / 100.0));
    cout << "[SALE] ID: " << getId()
        << " | Name: " << getName()
        << " | Original: $" << getPrice()
        << " | Sale: $" << finalPrice
        << " (" << discountPercent << "% OFF)" << endl;
}