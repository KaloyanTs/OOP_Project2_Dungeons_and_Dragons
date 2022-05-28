#ifndef __WEAPON_HPP
#define __WEAPON_HPP
#include "HeroEquipment.hpp"

class Weapon : public HeroEquipment
{

public:
    Weapon(unsigned y, unsigned x, bool onBoard = true) : HeroEquipment(y, x, onBoard) {}
    HeroEquipment *clone() const { return new Weapon(*this); }
    void print(const Printer &p) const;
};

#endif