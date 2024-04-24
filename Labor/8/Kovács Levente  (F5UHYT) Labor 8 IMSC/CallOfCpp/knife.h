#pragma once

#include "weapon.h"
#include <string>
#include <iostream>

class Knife : Weapon
{
private:
    double sharpness;

public:
    Knife(unsigned damage = 30, double sharpness = 0.8) : Weapon(damage),
                                                          sharpness(sharpness)
    {
    }
    ~Knife() {}

    unsigned use()
    {
        // Increment damage by one because the damage we're doing is not the already
        // decreased amount by Weapon::use()
        unsigned dmg = Weapon::use() + 1;
        // Calculate current damage before setting sharpness
        unsigned curDmg = dmg * sharpness;
        sharpness *= 0.95;
        return curDmg;
    }

    // Increase sharpness by 10%
    double sharpen()
    {
        sharpness *= 1.1;
        return sharpness;
    }

    std::string toString() const
    {
        return std::string("Weapon<|Knife; damage can be caused when stabbing=")
        + std::to_string(getDamage() * sharpness) + "; sharpness=" + std::to_string(sharpness);
    }
};
