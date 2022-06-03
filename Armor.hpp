#ifndef __ARMOR_HPP
#define __ARMOR_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

class Armor : public HeroEquipment
{

public:
    Armor(unsigned y, unsigned x, unsigned bot, unsigned top = 0, bool onBoard = true);
    HeroEquipment *clone() const;
    void print() const;
    ID getID() const { return ID::ARMOR; }
    float getCost() { return 0; }
};

#endif