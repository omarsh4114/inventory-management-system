#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include<sstream>
#include"Product.h"
using namespace std;
class Inventory
{
private:
	 vector <Product> products;
public:
	void saveToFile(string IMS) ;
	void loadFromFile(string IMS);

	// team A --------------------------------- team A

	      //                   
	void addproduct(int id, string name, double price, int quantity);
	      //                   
	void updatequantity(int id, int quantity);

	void removeproduct(int id);

	void displayinventory();

	double computetotalvalue();

	// team B --------------------------------- team B
	void lowStockAlert(int threshold);




};

