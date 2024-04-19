#pragma once

#include <iostream>

class Weapon
{
private:
    unsigned damage;
public:
    Weapon(unsigned damage = 10) : damage(damage){}
    ~Weapon();
    
    unsigned getDamage() const { return damage; }
    void setDamage(const unsigned paramDamage) { damage = paramDamage; }

    std::string toString()
    {
        return std::string("Weapon damage: ") + std::to_string(damage) + ".";
    }

    std::ostream& operator<<(std::ostream& os);

    unsigned use()
    {
        damage--;
        return damage;
    }
};
