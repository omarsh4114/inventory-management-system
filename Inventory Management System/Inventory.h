#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include<sstream>
#include"Product.h"
using namespace std;
class inventory
{
private:
	 vector <Product> products;
public:
	void saveToFile(string IMS) {};
	void loadToFile(string IMS) {};

	// team A --------------------------------- team A

	      //                   rana
	void addproduct(int id, string name, double price, int quantity) {

	}
	      //                   jana
	void updatequantity(int id, int quantity){
	}
         //                    habiba
	void removeproduct(int id) {
	}
       //                      rawan 
	void displayinventory() {
	}
	double computetotalvalue() {
	}

	// TEAM B ---------------------           ------------------
	void lowstockalert(int threshold) {
	}




};

