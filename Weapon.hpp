#ifndef __WEAPON_HPP
#define __WEAPON_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

class Weapon : public HeroEquipment
{

public:
    Weapon(unsigned y, unsigned x, bool onBoard = true)
        : HeroEquipment(&GameAssets::attack_icon, y, x, onBoard) { Constants::weapon_name_generator.generateWord(name); }
    HeroEquipment *clone() const { return new Weapon(*this); }
    void print(const Printer &p) const;
};

#endif