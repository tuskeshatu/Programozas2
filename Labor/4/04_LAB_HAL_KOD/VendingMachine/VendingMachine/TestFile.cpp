#include "VendingMachine.h"

int main()
{
	// k�la defini�l�sa
	std::string Cola("Coca-Cola");

	// TODO m�sfajta ital(ok) defini�l�sa

	// automata l�trehoz�sa
	VendingMachine coldDrinkMachine;	

	// felt�lt�s 5 Coca-col�val
	coldDrinkMachine.refill(Cola, 5);

	// ellen�rz�s
	coldDrinkMachine.print();

	// TODO v�s�rl�s �s m�sol� konstruktor kipr�b�l�sa, t�bb automata l�trehoz�sa
	
}