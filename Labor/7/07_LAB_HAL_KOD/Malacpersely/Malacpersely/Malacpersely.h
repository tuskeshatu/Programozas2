#pragma once
#include <iostream>

class Malacpersely
{
	int osszeg;
public:
	Malacpersely(const int penz=0) : osszeg(penz) {}
	void bedob(const int penz);
	void atont(Malacpersely& masik);
	int ertek() const { return osszeg; }

	Malacpersely& operator+(const int) const;
	Malacpersely& operator+(const Malacpersely&) const;
	Malacpersely& operator+=(const int);
	Malacpersely& operator+=(Malacpersely&);
};

std::ostream& operator<<(std::ostream&, const Malacpersely&);