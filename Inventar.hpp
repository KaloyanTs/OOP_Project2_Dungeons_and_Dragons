#ifndef __INVENTAR_HPP
#define __INVENTAR_HPP
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Spell.hpp"
#include "Potion.hpp"
#include "Vector.hpp"

class Inventar : protected Vector<HeroEquipment *>
{
    size_t limit;

public:
    Inventar(size_t lim = Constants::INVENTAR_LIMIT)
        : Vector<HeroEquipment *>(lim), limit(lim) {}
    ~Inventar();
    static EventGenerator *getEquipment(unsigned index, unsigned y, unsigned x, unsigned bot, unsigned top = 0, unsigned cost = 0);
    void print(const String &owner) const;
    bool put(const HeroEquipment &el);
    HeroEquipment *remove(unsigned index);
    size_t getCount() const { return m_size; }

    void write(std::ofstream &ofs) const;
};

#endif