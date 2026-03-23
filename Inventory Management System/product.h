#pragma once
#include <iostream>
#include <string>
using namespace std;
class Product
{
private:
	int id;
	string name;
	double price;
	int quantity;
public:
	Product(int id, string name, double price, int quantity) {};

	int getId() {
		return id;
	};
	string getName() {
		return name;
	};
	double getPrice() {
		return price;
	};
	int getQuantity() {
		return quantity;
	};

	
	void setName(string name) {};
	void setPrice(double price) {};
	void setQuantity(int quantity) {};

};

