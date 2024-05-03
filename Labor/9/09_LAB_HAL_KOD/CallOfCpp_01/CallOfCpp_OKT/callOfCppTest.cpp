#include <iostream>
#include "weapon.h"
#include "knife.h"
#include "pistol.h"
#include "railgun.h"

using namespace std;

int main()
{

	Weapon excalibur(100);
	Knife knife;
	Pistol pistol;
	Railgun railgun;

	// Tárold a fenti fegyvereket közös tömbben (hetereogén kollekció)
	Weapon *weapons[]{&excalibur, &knife, &pistol, &railgun};

	// Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekció felhasználásával!
	for (int i = 0; i < 4; i++)
	{
		std::cout << *weapons[i] << std::endl;
	}

	cout << endl;

	// Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekcióból!
	cout << "Damage caused with excalibur: " << excalibur.use() << endl;
	cout << "Damage caused with knife: " << knife.use() << endl;
	cout << "Damage caused with pistol: " << pistol.use() << endl;
	cout << "Damage caused with railgun: " << railgun.use() << endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Damage caused: " << weapons[i]->use() << std::endl;
	}

#if 0
	knife.sharpen();
	pistol.reload();
	railgun.recharge();


	cout << endl;

	//Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekcióból!
	cout << excalibur.toString() << endl;
	cout << knife.toString() << endl;
	cout << pistol.toString() << endl;
	cout << railgun.toString() << endl;
#endif
	return 0;
}
