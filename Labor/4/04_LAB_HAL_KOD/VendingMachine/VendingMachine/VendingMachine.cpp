#include "VendingMachine.h"
#include <cstdio>

// alap�rtelmezett konstruktor
// kezdetben �res a g�p
VendingMachine::VendingMachine()
{
	drinkNumber = 0;
	drinks = nullptr;
}

// TODO
// m�sol� konstruktor
VendingMachine::VendingMachine(const VendingMachine & other)
{
	
}

int VendingMachine::getDrinkNumber()
{
	return drinkNumber;
}

VendingMachine::~VendingMachine()
{
	// fel kell szabad�tani az italoknak lefoglalt mem�riater�letet
	delete[] drinks;
}

// els� ital kiv�tele
// visszat�r a nev�vel
std::string VendingMachine::removeOne()
{
	// ellen�rz�s, hogy van-e m�g �d�t� az automat�ban
	if (drinkNumber <= 0)
		return "Empty";

	// visszat�r�si �rt�k, els� elem
	std::string value = drinks[0];

	// kisebb m�ret� t�mb lefoglal�sa
	std::string* tmp;
	tmp = new std::string[drinkNumber - 1];

	// els� ut�ni elemek �tm�sol�sa
	for (int i = 1; i < drinkNumber; i++)
		tmp[i-1] = drinks[i];

	// darabsz�m cs�kkent�se
	drinkNumber = drinkNumber - 1;

	// r�gi t�mb felszabad�t�sa
	delete[] drinks;

	// �j t�mb be�r�sa az oszt�lyba
	drinks = tmp;

	// visszat�r�s
	return value;
}

// v�s�rl�s
// egyszerre t�bb italt is lehet v�s�rolni, alap�rtelmezetten 1
// ha t�bbet venn�nk, mint amennyi k�szleten van, hamissal t�r vissza, egy�bk�nt igazzal
// sikeres v�s�rl�s eset�n cs�kkenteni kell a darabsz�mot, �s t�r�lni az elemeket
bool VendingMachine::buy(int num)
{
	if (num > drinkNumber)
		return false;
	for (int i = 0; i < num; i++)
	{
		printf("Vasarolt ital: %s\n", removeOne().c_str());
	}
	return true;

}

// TODO
// automata felt�lt�se
// meg kell adni az ital nev�t, �s hogy mennyit rakunk bel�le a g�pbe
bool VendingMachine::refill(std::string pName, int pQty)
{
	// csak pozit�v �rt�kkel m�k�dj�n
	
	//nagyobb t�mb lefoglal�sa
	
	// megl�v� elemek �tm�sol�sa
	
	// �j elemek bet�lt�se
	
	// darabsz�m fel�l�r�sa

	// r�gi t�mb t�rl�se
	
	// �j t�mb �t�r�sa

	return true;
}

// k�szlet ki�r�sa
void VendingMachine::print()
{
	printf("Keszlet: %d\n", drinkNumber);
	for (int i = 0; i < drinkNumber; i++)
		printf("%s\n", drinks[i].c_str());
	printf("---Lista vege---\n\n");
}


