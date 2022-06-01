#ifndef __WEAPON_HPP
#define __WEAPON_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

class Weapon : public HeroEquipment
{

public:
    Weapon(unsigned y, unsigned x, bool onBoard = true);
    HeroEquipment *clone() const;
    void print() const;
    ID getID() const { return ID::WEAPON; }
};

#endif