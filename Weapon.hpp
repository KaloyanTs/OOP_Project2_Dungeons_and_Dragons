#ifndef __WEAPON_HPP
#define __WEAPON_HPP
#include "HeroEquipment.hpp"

class Weapon : public HeroEquipment
{
    const Image *pic;

public:
    Weapon(unsigned y, unsigned x, bool onBoard = true)
        : HeroEquipment(y, x, onBoard), pic(&GameAssets::attack_icon) {}
    HeroEquipment *clone() const { return new Weapon(*this); }
    void print(const Printer &p) const;
};

#endif