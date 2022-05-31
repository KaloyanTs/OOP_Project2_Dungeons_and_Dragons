#ifndef __ARMOR_HPP
#define __ARMOR_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

class Armor : public HeroEquipment
{

public:
    Armor(unsigned y, unsigned x, bool onBoard = true);
    HeroEquipment *clone() const;
    void print(const Printer &p) const;
};

#endif