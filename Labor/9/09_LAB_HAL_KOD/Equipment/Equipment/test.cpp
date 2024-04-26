#include <iostream>
#include "display.h"
#include "printer.h"
#include "equipment.h"

using namespace std;

int main()
{
	const unsigned maxEquipment = 4;

	// Itt hozzunk létre 4 eszközt, az alábbi kimenetek meghatározzák a paramétereiket.
	// Heterogén kollekcióban akarjuk őket tárolni (közös tömbben)

	Equipment *equipments[maxEquipment];
	equipments[0] = new Equipment(123);
	equipments[1] = new Printer(1234, 69, 420);
	equipments[2] = new Equipment(69420);
	equipments[3] = new Printer(897, 64, 540);

	/************************Elvárt kimenet**************************\
	 Serial Number:1 Price:200 HUF
	 Serial Number:2 Price:12000 HUF Cartridge Price (Printer):12000
	 Serial Number:3 Price:2000 HUF Age (Display): 6
	 Serial Number:4 Price:312000 HUF Cartridge Price (Printer):51000
	\****************************************************************/
	for (int i = 0; i < maxEquipment; i++)
	{
		// Itt ki kell írnunk mindegyiknek az adatát
		std::cout << *equipments[i] << endl;
	}

	for (int i = 0; i < maxEquipment; i++)
	{
		delete equipments[i];
	}

	Printer p(1, 2, 3);
	Printer p2 = p;

	return 0;
}