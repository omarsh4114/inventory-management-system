#pragma once
#include "Product.h"

// --- INHERITANCE ---
class DiscountedProduct : public Product {
private:
    double discountPercent;

public:
    DiscountedProduct(int id, string name, double price, int quantity, double disc);

    // --- POLYMORPHISM ---
    // Overriding the base display to show the sale price
    void display() const override;
};