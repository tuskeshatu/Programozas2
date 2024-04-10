#include "product.h"

void Product::setSalePercent(double discount)
{
    if (discount >= 100)
        throw "Discount bigger than legal!";

    sale_percent = discount;
}

Product::Product(double param)
{
    if (param < 0)
        throw "Set price is negative!";

    price = param;
}

double Product::sale_percent = 0;