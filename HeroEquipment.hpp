#ifndef __HERO_EQUIPMENT_HPP
#define __HERO_EQUIPMENT_HPP
#include "Equipment.hpp"
#include "EventGenerator.hpp"

class HeroEquipment : public Equipment, public EventGenerator
{
    static String errorMsg;
    static const char stamp = 'T';
    const Image *pic;

protected:
    enum class ID
    {
        WEAPON = 0,
        ARMOR = 1,
        SPELL = 2,
        POTION = 3
    };

public:
    // todo more data!!!
    HeroEquipment(const Image *p, unsigned y, unsigned x, unsigned top = 0, unsigned bottom = 0, bool board = true)
        : Equipment((top ? rand() % (top - bottom + 1) + bottom : bottom)), EventGenerator(y, x, errorMsg, board), pic(p) {}
    HeroEquipment *clone() const = 0;

    char getChar() const { return stamp; }
    Constants::ACTION_STATE action(Player *, bool &run);
    void print() const;
    virtual ID getID() const = 0;
    virtual float getCost() = 0;
};

#endif