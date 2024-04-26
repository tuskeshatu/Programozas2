#pragma once
#include "equipment.h"
#include <iostream>

// Displayeket �s Printereket k�z�s t�mbben szeretn�nk valahogy t�rolni
class Printer : public Equipment
{
	unsigned price;
	unsigned cartridgePrice;

public:
	Printer(unsigned serialNumber = 0, unsigned price = 0, unsigned cartridgePrice = 0)
		: Equipment(serialNumber), price(price), cartridgePrice(cartridgePrice)
	{
	}

	Printer(const Printer &other) : Equipment(other), price(other.price)
	{
	}

	void setCartridgePrice(unsigned cartridgePrice);
	unsigned getCartridgePrice() const;

	void print(std::ostream &os) const override;

	Printer &operator=(const Printer &other)
	{
		Equipment::operator=(other);
		price = other.price;
	}
};

std::ostream &operator<<(std::ostream &os, const Printer &p);