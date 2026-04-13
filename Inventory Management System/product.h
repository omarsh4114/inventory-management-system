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
	Product(int id, string name, double price, int quantity) ;

	int getId() const;
	string getName() const;
	double getPrice() const;
	int getQuantity() const;
	
	void setName(string name) {};
	void setPrice(double price) {};
	void setQuantity(int quantity) {};

};

