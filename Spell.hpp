#ifndef __SPELL_HPP
#define __SPELL_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

class Spell : public HeroEquipment
{
    float cost;

public:
    Spell(unsigned y, unsigned x, unsigned bot, unsigned top = 0, bool onBoard = true, unsigned c = 0);
    Spell *clone() const { return new Spell(*this); }
    void print() const;
    ID getID() const { return ID::SPELL; }
    float getCost() { return cost; };
};

#endif