#include <iostream>
#include "printer.h"

using namespace std;

// A serialNo �s a price param�tereket is el kell t�rolnunk valahol

unsigned Printer::getCartridgePrice() const
{
	return cartridgePrice;
}

void Printer::print(std::ostream &os) const
{
	Equipment::print(os);
	os << " Printer; price: " << price << " cartridge price: " << cartridgePrice;
}

std::ostream &operator<<(std::ostream& os, const Printer &p)
{
	p.print(os);
	return os;
}