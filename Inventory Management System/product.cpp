#include "Product.h"
#include<iostream>
#include<string>
using namespace std;

Product::Product(int id, string name,double price ,int quantity ) {
	this->id = id;
	this->name = name;
	this->price = price;
	this->quantity = quantity;
};
    // ====================                 setters
void Product::setName(string name) {
	if (name.length() >= 8 && name.length()  <= 20) 
		this->name = name;
	else
		cout << "name cannot be less than 8 and more than 20";
}
void Product::setPrice(double price) {
	if (price >= 0)
		this->price = price;
	else
		cout << "error : Price cannot be negative";
	
}
void Product::setQuantity(int quantity) {
	if (quantity >= 0)
		this->quantity = quantity;
	else
		cout << "error : Quantity cannot be negative";
}
//         =============              getters
int Product::getId() {
	return id;
}
string Product::getName() {
	return name;
}
double Product::getPrice() {
	return price;
}
int Product::getQuantity() {
	return quantity;
}


