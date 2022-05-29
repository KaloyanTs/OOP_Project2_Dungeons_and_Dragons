#ifndef __HERO_EQUIPMENT_HPP
#define __HERO_EQUIPMENT_HPP
#include "Equipment.hpp"
#include "EventGenerator.hpp"
#include "Player.hpp"

class HeroEquipment : public Equipment, public EventGenerator
{
    static const char stamp = 'T';

public:
    // todo more data!!!
    HeroEquipment(unsigned y, unsigned x, bool board = true)
        : Equipment(43433), EventGenerator(y, x, board) {}
    HeroEquipment *clone() const = 0;

    char getChar() const { return stamp; }
    bool action(Player *p);
    void print(const Printer &p) const = 0;
};

#endif