#pragma once

class Pistol : Weapon
{
private:
    unsigned clipSize;
    unsigned bulletsInClip;
    unsigned totalBullets;
public:
    Pistol(unsigned damage = 60, unsigned clipSize, unsigned totalBullets) :
    Weapon(damage),
    clipSize(clipSize),
    bulletsInClip(clipSize),
    totalBullets(totalBullets)
    {

    }
    ~Pistol();

    void reload()
    {
        bulletsInClip = clipSize;
    }
};
