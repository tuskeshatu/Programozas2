#include <iostream>
#include "printer.h"

using namespace std;

//A serialNo �s a price param�tereket is el kell t�rolnunk valahol
Printer::Printer(unsigned serialNo, unsigned price, unsigned cartridgePrice): cartridgePrice(cartridgePrice){}

void Printer::setCartridgePrice(unsigned cartridgePrice)
{
	this->cartridgePrice = cartridgePrice;
}

unsigned Printer::getCartridgePrice() const
{
	return cartridgePrice;
}

void Printer::print() const
{
	cout << " Cartridge Price (Printer):" << cartridgePrice;
}
