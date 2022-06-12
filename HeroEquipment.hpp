#ifndef __HERO_EQUIPMENT_HPP
#define __HERO_EQUIPMENT_HPP
#include "Equipment.hpp"
#include "EventGenerator.hpp"

/// class representing equipment owned by a hero
class HeroEquipment : public Equipment, public EventGenerator
{
    static String errorMsg;
    static const char stamp = 'T';
    const Image *pic;

protected:
    HeroEquipment(unsigned bonus, const String &name, const Image *p)
        : Equipment(bonus, name), EventGenerator(0, 0, false), pic(p) {}

public:
    /// ID's of all hero equipments (used in saving/loading game)
    enum class ID
    {
        WEAPON = 0,
        ARMOR = 1,
        SPELL = 2,
        POTION = 3
    };
    /// constructor of hero equipment by picture, position on the board and bounds for the given bonus
    HeroEquipment(const Image *p, unsigned y, unsigned x, unsigned top = 0, unsigned bottom = 0, bool board = true)
        : Equipment((top ? rand() % (top - bottom + 1) + bottom : bottom)), EventGenerator(y, x, errorMsg, board), pic(p) {}
    /// pure virtual clone function
    HeroEquipment *clone() const = 0;
    /// get the repreenting character on the board
    char getChar() const { return stamp; }
    /// execute the action evolving some equipment and the player (player takes the equipment if possible)
    Constants::ACTION_STATE action(Player *, bool &run);
    /// print info about the equipment (picture, bonus, cost (if has) and name)
    void print() const;
    virtual ID getID() const = 0;
    virtual float getCost() const = 0;
    /// write info about the equipment into a text file (used for saving/loading the map)
    inline void write(std::ofstream &ofs) const
    {
        ofs << "e " << (int)getID() << ' ' << getY() << ' ' << getX() << ' ' << bonus << ' ' << getCost() << '\n';
    }
    /// write info about the equipment into a text file (used for saving/loading the player)
    inline void save(std::ofstream &ofs) const
    {
        ofs << (int)getID() << ' ' << getCost() << ' ' << bonus << ' '
            << name.size() << ' ' << name.c_str() << '\n';
    }
};

#endif