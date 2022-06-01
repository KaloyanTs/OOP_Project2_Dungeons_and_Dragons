#ifndef __DRAGON_HPP
#define __DRAGON_HPP
#include "Constants.hpp"
#include "Troop.hpp"
#include "EventGenerator.hpp"

class Player;

class Dragon : public Troop, public EventGenerator
{
    static String errorMsg;
    static const char stamp = 'M';
    const Image *pic;

public:
    Dragon(unsigned y, unsigned x, unsigned lvl = 1)
        : Troop((unsigned)determineStat(lvl, 25, 1.2),
                (unsigned)determineStat(lvl, 25, 1.2),
                (unsigned)determineStat(lvl, 50, 1.2), lvl),
          EventGenerator(y, x, errorMsg),
          pic(&GameAssets::dragon)
    {
    }
    virtual Dragon *clone() const { return new Dragon(*this); }
    char getChar() const { return stamp; }
    Constants::ACTION_STATE action(Player *, bool &);
    void print() const;
};

#endif