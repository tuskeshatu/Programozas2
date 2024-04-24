#pragma once

#include "weapon.h"
#include <string>
#include <iostream>

class Pistol : Weapon
{
private:
    unsigned clipSize;
    unsigned bulletsInClip;
    unsigned totalBullets;

public:
    Pistol(unsigned damage = 60, unsigned clipSize = 12, unsigned totalBullets = 36) : Weapon(damage),
                                                                                       clipSize(clipSize),
                                                                                       bulletsInClip(clipSize),
                                                                                       totalBullets(totalBullets)
    {
    }
    ~Pistol() {}

    // Reload
    void reload()
    {
        // Don't have enough bullets for full reload
        if (totalBullets < clipSize - bulletsInClip)
        {
            bulletsInClip += totalBullets;
            totalBullets = 0;
            return;
        }
        // Have enough bullets to reload fully
        totalBullets -= clipSize - bulletsInClip;
        bulletsInClip = clipSize;
    }

    unsigned use()
    {
        // If no bullets are left
        if (bulletsInClip == 0)
            return 0;
        // Else decrease no. of bullets and increment damage because for
        // some reason (as can be seen in provided expected output in pdf)
        // guns are not used up by shooting them
        bulletsInClip--;
        setDamage(getDamage() + 1);
        return Weapon::use();
    }

    std::string toString() const
    {
        return std::string("Weapon<|Pistol; damage of a bullet=") + std::to_string(getDamage()) + " clipSize=" + std::to_string(clipSize) + "; bulletsInClip=" + std::to_string(bulletsInClip) + "; totalBullets=" + std::to_string(totalBullets);
    }
};
