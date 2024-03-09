#pragma once
#include <string>

class VendingMachine
{
	int drinkNumber;
	std::string *drinks;

public:
	VendingMachine();
	VendingMachine(const VendingMachine &);

	int getDrinkNumber() const;

	std::string removeOne();
	bool buy(int = 1);
	bool refill(const std::string &, int);

	void print() const;

	~VendingMachine();
};