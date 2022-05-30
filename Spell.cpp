#include "Spell.hpp"

void Spell::print(const Printer &p) const
{
    HeroEquipment::print(p);
    p("spell\n");
}