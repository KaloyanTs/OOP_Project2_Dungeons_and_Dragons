#ifndef __ARMOR_HPP
#define __ARMOR_HPP
#include "HeroEquipment.hpp"

class Armor : public HeroEquipment
{

public:
    Armor(unsigned y, unsigned x, bool onBoard = true) : HeroEquipment(y, x, onBoard) {}
    HeroEquipment *clone() const { return new Armor(*this); }
    void print(const Printer &p) const;
};

#endif