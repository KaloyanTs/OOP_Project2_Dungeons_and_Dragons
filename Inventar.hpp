#ifndef __INVENTAR_HPP
#define __INVENTAR_HPP
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Spell.hpp"
#include "Potion.hpp"
#include "Vector.hpp"
#include "MyException.hpp"

/// class representing inventar of a player (container for his equipment)
class Inventar : protected Vector<HeroEquipment *>
{
    size_t limit;

public:
    /// construct inventar with initial capacity
    Inventar(size_t lim = Constants::INVENTAR_LIMIT)
        : Vector<HeroEquipment *>(lim), limit(lim) {}
    ~Inventar();
    /// get new equipment recognized by its ID (parameter 1)
    static EventGenerator *getEquipment(unsigned index, unsigned y, unsigned x, unsigned bot, unsigned top = 0, unsigned cost = 0);
    /// get new equipment recognized by its ID and read from text file
    static HeroEquipment *readEquipment(std::ifstream &ifs, unsigned buf);
    /// print some player's inventar knowing his name
    void print(const String &owner) const;
    /// add new equipment to the inventar
    bool put(const HeroEquipment &el);
    /// remove the equipment at certain index from the inventar (returned as a result)
    HeroEquipment *remove(unsigned index);
    size_t getCount() const { return m_size; }
    /// write info into a text file
    void write(std::ofstream &ofs) const;
};

#endif