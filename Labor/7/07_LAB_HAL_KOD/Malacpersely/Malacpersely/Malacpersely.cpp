#include "Malacpersely.h"

void Malacpersely::bedob(int penz)
{
	osszeg += penz;
}

void Malacpersely::atont(Malacpersely &masik)
{
	osszeg += masik.osszeg;
	masik.osszeg = 0;
}

Malacpersely &Malacpersely::operator+(const int param) const
{
	Malacpersely *result = new Malacpersely(osszeg + param);
	return *result;
}

Malacpersely &Malacpersely::operator+(const Malacpersely& param) const
{
	Malacpersely *result = new Malacpersely(this->ertek() + param.ertek());
	return *result;
}

std::ostream &operator<<(std::ostream &os, const Malacpersely &persely)
{
	os << persely.ertek();
	return os;
}

Malacpersely &Malacpersely::operator+=(const int param)
{
	osszeg += param;
	return *this;
}

Malacpersely &Malacpersely::operator+=(Malacpersely &param)
{
	atont(param);
	return *this;
}