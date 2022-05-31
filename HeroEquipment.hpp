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
    String name;

public:
    // todo more data!!!
    HeroEquipment(const Image *p, unsigned y, unsigned x, bool board = true)
        : Equipment(43433), EventGenerator(y, x, errorMsg, board), pic(p) {}
    HeroEquipment *clone() const = 0;

    char getChar() const { return stamp; }
    Constants::ACTION_STATE action(Player *, bool &run);
    void print(const Printer &p) const;
};

#endif