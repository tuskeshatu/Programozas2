#include "vector.h"
using namespace std;

int main()
{
	Vector v1;
	// insert tesztel�se
	for (int i = 1; i < 10; i++)
		v1.insert(i, i);

	// A ki�r�s (operator<<) �s az at() f�ggv�ny tesztel�se
	cout << v1 << endl;
	// Helyes eredm�ny: 0 1 2 3 4 5 6 7 8 9

	// M�sol� konstruktor tesztel�se
	Vector v2(v1); // Lehetne: Vector v2=v1;

	// operator= tesztel�se
	Vector v3;
	v3 = v2;

	// erase tesztel�se (megv�ltoztatjuk v1-t)
	v1.erase(0);
	// v1.erase(9); // Ennek assertelni kell
	cout << endl
		 << v1 << endl
		 << v2 << endl
		 << v3 << endl;
	// Helyes eredm�ny:
	// 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9

	// insert tesztel�se
	v2.insert(0, -1);
	cout << v2 << endl;
	// Helyes eredm�ny: -1 0 1 2 3 4 5 6 7 8 9

	v2.insert(10, -1);
	cout << v2 << endl;
	// Helyes eredm�ny: -1 0 1 2 3 4 5 6 7 8 -1 9

	v2.insert(12, -1);
	cout << v2 << endl;
	// Helyes eredm�ny: -1 0 1 2 3 4 5 6 7 8 -1 9 -1

	v2.insert(15, -1);
	cout << v2 << endl;
	// Helyes eredm�ny: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -1

	// operator[] tesztel�se
	v2[15] = -2;
	cout << v2 << endl;
	// Helyes eredm�ny: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -2
	//v2[16]=3; // Ennek assertelni kell


// IMSC INNEN KEZDODIK


	// operator*= tesztel�se
	v2 *= 10;
	cout << v2 << endl;
	// Helyes eredm�ny: -10 0 10 20 30 40 50 60 70 80 -10 90 -10 0 0 -20

	// rendez�s tesztel�se
	v2.sort();
	cout << v2 << endl;
	// Helyes eredm�ny: -20 -10 -10 -10 0 0 0 10 20 30 40 50 60 70 80 90

	v2.sort(Sorters::descend);
	cout << v2 << endl;
	// Helyes eredm�ny: 90 80 70 60 50 40 30 20 10 0 0 0 -10 -10 -10 -20

	// t�mb felt�lt�s oper�tor t�lterhel�ssel
	Vector v4(5);
	cin >> v4;
	cout << endl
		 << v4 << endl;

	// operator+= tesztelese
	v4 += 1;
	cout << v4 << endl;

	return 0;
}