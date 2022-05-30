#ifndef __SPELL_HPP
#define __SPELL_HPP
#include "HeroEquipment.hpp"

class Spell : public HeroEquipment
{

public:
    Spell(unsigned y, unsigned x, bool onBoard = true)
        : HeroEquipment(&GameAssets::spell_icon, y, x, onBoard) {}
    HeroEquipment *clone() const { return new Spell(*this); }
    void print(const Printer &p) const;
};

#endif