#include "Armor.hpp"

void Armor::print(const Printer &p) const
{
    HeroEquipment::print(p);
    p(name)('\n');
}