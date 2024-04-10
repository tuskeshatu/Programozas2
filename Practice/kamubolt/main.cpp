#include "product.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Product king_cock(35000);

   Product::setSalePercent(50);

    int fasz = 100;
    int anyad = 250;

    king_cock += fasz += anyad;

    std::cout << king_cock.getCurrentPrice();

    return 0;
}
