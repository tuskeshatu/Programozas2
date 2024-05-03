#pragma once
#include <string>
#include <iostream>

class Weapon
{
protected:
	unsigned damage; // sebzés
public:
	Weapon(unsigned damage = 10);
	
	unsigned getDamage() const;
	void setDamage(unsigned damage);

	virtual unsigned use(); // visszaadja a csökkentett sebzést
	
	virtual std::string toString() const;
};

std::ostream& operator<<(std::ostream&, const Weapon&);