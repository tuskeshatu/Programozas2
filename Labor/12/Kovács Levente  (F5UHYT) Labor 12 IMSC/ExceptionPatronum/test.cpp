#include <vector>
#include <stdexcept>
#include <iostream>
#include  <algorithm>

#include "element_not_found.hpp"

using namespace std;

vector<char> v = {'h', 'a', 'r', 'r', 'y'};

char f1(unsigned pos)
{
	// Dobj kivételt, ha túl kicsi, vagy túl nagy indexet adott meg!
	if (pos >= v.size())
		throw std::out_of_range("f1: Harry is too short!");

	return v[pos];
}

vector<int *> f2()
{
	vector<int *> pInts;
	// A kivételt a new dobja.
	try {
		for (int i = 0; i < 10000000; pInts.push_back(new int[10000]), i++)
			;
	} catch (const std::bad_alloc& e) {
		throw; // Rethrow the exception if new throws
	}
	return pInts;
}

char f3()
{
	vector<char>::iterator it = find(v.begin(), v.end(), 'g');
	if (it == v.end())
		throw element_not_found<char>('g');

	// Dobj saját kivételt (element_not_found<char>('g')), ha nem található a keresett elem.
	return *it;
}

void f4()
{
	// Dobj kivételt, ha az 1. karakter már 'H'.
	if (v[0] == 'H')
		throw std::runtime_error("First character is 'H'!");

	v[4] = 'H';
}

extern "C" char bonus(unsigned pos)
{
	// - Ez egy C függvény, tehát itt nem tudsz kivételt használni.
	// - Milyen más megoldást ismersz, ami nem hagyományos kiíratás?
	// - Mire kell vigyázni vele kapcsolatban?
	if (pos >= v.size())
		return -1;

	return v[pos];
}

int main()
{
	// A)
	try
	{
		f1(6);
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}

	// B)
	vector<int *> pInts;
	try
	{
		pInts = f2();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	for (vector<int *>::iterator it = pInts.begin(); it != pInts.end(); delete *it, ++it)
		;

	// C)
	try
	{
		f3();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// D)
	try
	{
		f4();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// E) - Szorgalmi.
	if (bonus(6) == -1)
		std::cerr << "Invalid index." << std::endl;

	cin.get();
}