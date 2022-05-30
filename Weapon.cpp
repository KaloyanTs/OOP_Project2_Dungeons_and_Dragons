#include "Weapon.hpp"

void Weapon::print(const Printer &p) const
{
    HeroEquipment::print(p);
    p(name)('\n');
}