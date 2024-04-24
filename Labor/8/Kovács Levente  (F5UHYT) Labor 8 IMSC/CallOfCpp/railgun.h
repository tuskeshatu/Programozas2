#pragma once

#include "weapon.h"
#include <string>
#include <iostream>

class Railgun : Weapon
{
private:
    unsigned energy;

public:
    Railgun(unsigned damage = 90, unsigned energy = 100) : Weapon(damage),
                                                           energy(energy)
    {
    }
    ~Railgun() {}

    unsigned use()
    {
        // If there isn't enough energy to shoot
        if (energy < 10)
            return 0;
        // Else decrease energy and increment damage because for
        // some reason (as can be seen in provided expected output in pdf)
        // railguns are not used up by shooting them
        energy -= 10;
        setDamage(getDamage() + 1);
        return Weapon::use();
    }

    void recharge()
    {
        energy += 8;
    }

    std::string toString() const
    {
        return std::string("Weapon<|Railgun; damage of shooting=") + std::to_string(getDamage()) + "; energy=" + std::to_string(energy);
    }
};
