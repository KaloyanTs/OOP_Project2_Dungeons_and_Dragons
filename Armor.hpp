#ifndef __ARMOR_HPP
#define __ARMOR_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

class Armor : public HeroEquipment
{

public:
    Armor(unsigned y, unsigned x, bool onBoard = true)
        : HeroEquipment(&GameAssets::armor_icon, y, x, onBoard) { Constants::armor_name_generator.generateWord(name); }
    HeroEquipment *clone() const { return new Armor(*this); }
    void print(const Printer &p) const;
};

#endif