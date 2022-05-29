#ifndef __INVENTAR_HPP
#define __INVENTAR_HPP
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Spell.hpp"
#include "Vector.hpp"

class Inventar : protected Vector<HeroEquipment *>
{

public:
    static EventGenerator *getEquipment(unsigned index, unsigned y, unsigned x);
};

#endif