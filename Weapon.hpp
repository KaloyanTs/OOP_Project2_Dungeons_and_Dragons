#ifndef __WEAPON_HPP
#define __WEAPON_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

class Weapon : public HeroEquipment
{
public:
    Weapon(unsigned y, unsigned x, unsigned bot, unsigned top = 0, bool onBoard = true);
    Weapon(unsigned bonus, const String &name)
        : HeroEquipment(bonus, name, &GameAssets::weapon_icon) {}
    Weapon *clone() const { return new Weapon(*this); }
    void print() const;
    ID getID() const { return ID::WEAPON; }
    float getCost() const { return 0; }
};

#endif