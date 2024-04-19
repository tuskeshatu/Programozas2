#pragma once

class Railgun : Weapon
{
private:
    unsigned energy;

public:
    Railgun(unsigned damage = 90, unsigned energy = 100) :
        Weapon(damage),
        energy(energy)
    {
        
    }
    ~Railgun();

    unsigned use()
    {
        if (energy < 10)
            return 0;
        
        energy -= 10;
        return Weapon::use();
    }

    void recharge()
    {
        energy += 8;
    }
};
