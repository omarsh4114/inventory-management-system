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
	Product(int id, string name, double price, int quantity);

	// --- ADDED FOR POLYMORPHISM ---
	virtual ~Product() {} // Essential for inheritance
	virtual void display() const; // This allows the override in image_5859a5.png

	int getId() const;
	string getName() const;
	double getPrice() const;
	int getQuantity() const;

	void setName(string name);
	void setPrice(double price);
	void setQuantity(int quantity);
};