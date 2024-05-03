#pragma once
#include "equipment.h"

//Displayeket �s Printereket k�z�s t�mbben szeretn�nk valahogy t�rolni
class Display : public Equipment
{
	unsigned price;
	unsigned age;
public:
	Display(unsigned serialNumber, unsigned price, unsigned age);

	void setAge(unsigned age);
	unsigned getAge() const;

	void print() const;
};
