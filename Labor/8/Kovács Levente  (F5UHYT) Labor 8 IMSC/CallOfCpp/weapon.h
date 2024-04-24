#pragma once

#include "weapon.h"
#include <string>
#include <iostream>

class Weapon
{
private:
    unsigned damage;
public:
    Weapon(unsigned damage = 10) : damage(damage){}
    ~Weapon() {}
    
    unsigned getDamage() const { return damage; }
    void setDamage(const unsigned paramDamage) { damage = paramDamage; }

    std::string toString() const
    {
        return std::string("Weapon; damage can be caused=") + std::to_string(damage);
    }

    // Decrement damage to simulate weardown
    unsigned use()
    {
        damage--;
        return damage;
    }
};
