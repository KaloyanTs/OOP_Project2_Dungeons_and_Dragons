#include "Inventar.hpp"

EventGenerator *Inventar::getEquipment(unsigned index, unsigned y, unsigned x)
{
    if (!index)
        return new Weapon(y, x);
    else if (index == 1)
        return new Armor(y, x);
    else if (index == 2)
        return new Spell(y, x);
    return nullptr;
}