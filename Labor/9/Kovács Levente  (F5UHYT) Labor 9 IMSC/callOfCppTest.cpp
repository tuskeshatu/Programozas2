﻿#include <iostream>
#include "player.h"
#include "knife.h"
#include "pistol.h"
#include "railgun.h"

using namespace std;

void printPlayers(const Player &p1, const Player &p2, const Player &enemy)
{
	cout << '\t' << p1 << endl;
	cout << '\t' << p2 << endl;
	cout << '\t' << enemy << endl
		 << endl;
}

int main()
{

	// A Weapon legyen absztrakt osztály (tehát ne lehessen példányosítani).
	// Weapon excalibur(100);

	Player p1("Player#1");

	// HEAPEN KELL LENNIE!!
	// DROP UNKNOWN SIGNALT DOB MERT NEM POINTEREK TÖMBJEKÉNT KÉNE TÁROLNI
	// A FEGYVEREKET, KÜLÖNBEN VÉLETLEN STACKEN LÉTEZŐ OBJECT LESZ DELETELVE
	Railgun *railgun1 = new Railgun;
	Player p2("Player#2", 50, 5, railgun1);
	Player enemy("Enemy#1");

	// TODO p1 kapjon egy pisztolyt és egy kést
	Knife* knife = new Knife;
	Pistol* pistol = new Pistol;
	p1.equipWeapon(pistol);
	p1.equipWeapon(knife);

	cout << "Init state" << endl;
	printPlayers(p1, p2, enemy);
	/***************************ELVÁRT KIMENET**********************************\
	| Player#1 is alive; health : 100; has 2 weapon(s); selected Knife          |
	| Player#2 is alive; health : 50; has 1 weapon(s); selected Railgun         |
	| Enemy#1 is alive; health : 100; has 0 weapon(s); selected no weapon       |
	\***************************************************************************/

	cout << "Player#1 switches to next weapon:" << endl;
	// TODO p1 váltson a következő fegyverre
	p1.switchToNextWeapon();

	printPlayers(p1, p2, enemy);
	/***************************ELVÁRT KIMENET**********************************\
	| Player#1 is alive; health: 100; has 2 weapon(s); selected Pistol          |
	| Player#2 is alive; health: 50; has 1 weapon(s); selected Railgun          |
	| Enemy#1 is alive; health: 100; has 0 weapon(s); selected no weapon        |
	\***************************************************************************/

	cout << "Player#2 attacks Enemy#1:" << endl;
	// TODO p2 támadja meg az enemy-t
	p2.attack(enemy);

	printPlayers(p1, p2, enemy);
	/***************************ELVÁRT KIMENET**********************************\
	| Player#1 is alive; health: 100; has 2 weapon(s); selected Pistol          |
	| Player#2 is alive; health: 50; has 1 weapon(s); selected Railgun          |
	| Enemy#1 is alive; health: 10; has 0 weapon(s); selected no weapon         |
	\***************************************************************************/

	cout << "Player#2 drops selected weapon:" << endl;
	// TODO p2 dobja el a kiválasztott fegyvert
	p2.dropSelected();

	printPlayers(p1, p2, enemy);
	/***************************ELVÁRT KIMENET**********************************\
	| Player#1 is alive; health: 100; has 2 weapon(s); selected Pistol          |
	| Player#2 is alive; health: 50; has 0 weapon(s); selected no weapon        |
	| Enemy#1 is alive; health: 10; has 0 weapon(s); selected no weapon         |
	\***************************************************************************/

	cout << "Player#2 attacks Enemy#1:" << endl;
	// TODO p1 támadja meg az enemy-t
	p1.attack(enemy);

	printPlayers(p1, p2, enemy);
	/***************************ELVÁRT KIMENET**********************************\
	| Player#1 killed Enemy#1 with a(n) Pistol                                  |
	| Player#1 is alive; health: 100; has 2 weapon(s); selected Pistol          |
	| Player#2 is alive; health: 50; has 0 weapon(s); selected no weapon        |
	| Enemy#1 is not alive; health: 0; has 0 weapon(s); selected no weapon      |
	\***************************************************************************/

	// TODO ne legyen memóriaszivárgás

	return 0;
}
