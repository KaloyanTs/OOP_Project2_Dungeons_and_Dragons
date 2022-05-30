#ifndef __INVENTAR_HPP
#define __INVENTAR_HPP
#include "Constants.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Spell.hpp"
#include "Vector.hpp"

class Inventar : protected Vector<HeroEquipment *>
{
    size_t limit;

public:
    Inventar(size_t lim = Constants::INVENTAR_LIMIT)
        : Vector<HeroEquipment *>(lim), limit(lim) {}
    ~Inventar();
    static EventGenerator *getEquipment(unsigned index, unsigned y, unsigned x);
    void print(const Printer &p) const;
    bool put(const HeroEquipment &el);
};

#endif