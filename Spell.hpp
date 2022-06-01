#ifndef __SPELL_HPP
#define __SPELL_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

class Spell : public HeroEquipment
{

public:
    Spell(unsigned y, unsigned x, bool onBoard = true);
    HeroEquipment *clone() const;
    void print(const Printer &p) const;
    ID getID() const { return ID::SPELL; }
};

#endif