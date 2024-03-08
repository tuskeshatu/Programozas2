#include "VendingMachine.h"

using namespace std;

int main()
{
	// k�la defini�l�sa
	string Cola("Coca-Cola");

	// TODO m�sfajta ital(ok) defini�l�sa
	string kevert("Kevert");
	string pinyo("Vodor");
	string fincsi("nem.");

	// automata l�trehoz�sa
	VendingMachine coldDrinkMachine;

	// felt�lt�s 5 Coca-col�val
	coldDrinkMachine.refill(Cola, 5);
	coldDrinkMachine.refill(kevert, 10);
	coldDrinkMachine.refill(pinyo, 3);
	coldDrinkMachine.refill(fincsi, 6);

	// ellen�rz�s
	coldDrinkMachine.print();

	coldDrinkMachine.buy(69);

	// TODO v�s�rl�s �s m�sol� konstruktor kipr�b�l�sa, t�bb automata l�trehoz�sa
	VendingMachine az_estem(coldDrinkMachine);
	coldDrinkMachine.print();

	coldDrinkMachine.~VendingMachine();

	coldDrinkMachine.buy();

	{
		VendingMachine test;
	}
}