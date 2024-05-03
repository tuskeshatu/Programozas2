#pragma once
#include "weapon.h"
#include <iostream>

class Railgun : public Weapon
{
	unsigned energy; // lövéshez szükséges energia: [0;100]
public:
	Railgun(unsigned damage = 90, unsigned energy = 100);
	~Railgun() {}
	
	unsigned getEnergy() const;

	unsigned use() override;
	void recharge(); // fegyver feltöltése

	std::string toString() const override;
};

