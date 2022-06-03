#ifndef __POTION_HPP
#define __POTION_HPP
#include "HeroEquipment.hpp"

class Potion : public HeroEquipment
{
public:
    Potion(unsigned y, unsigned x, unsigned bot, unsigned top = 0, bool onBoard = true);
    Potion *clone() const { return new Potion(*this); }
    void print() const;
    ID getID() const { return ID::POTION; }
    float getCost() { return 0; }
};

#endif