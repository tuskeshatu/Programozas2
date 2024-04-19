#pragma once

class Knife : Weapon
{
private:
    double sharpness;

public:
    Knife(unsigned damage = 30, double sharpness = 0.8) :
        Weapon(damage),
        sharpness(sharpness)
    {

    }
    ~Knife();

    unsigned use()
    {
        unsigned dmg = Weapon::use();
        sharpness *= 0.95;
        return dmg * sharpness;
    }

    double sharpen()
    {
        sharpness *= 1.1;
        return sharpness;
    }

};
