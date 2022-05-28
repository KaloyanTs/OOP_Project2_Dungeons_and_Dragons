#ifndef __DRAGON_HPP
#define __DRAGON_HPP
#include "Troop.hpp"
#include "EventGenerator.hpp"

class Dragon : public Troop, public EventGenerator
{
    static const char stamp = 'M';
    unsigned level;
    const Image *pic;

public:
    Dragon(unsigned y, unsigned x)
        : Troop(25, 25, 50), EventGenerator(y, x),
          level(1), pic(&GameAssets::dragon)
    {
    }
    virtual Dragon *clone() const { return new Dragon(*this); }
    char getChar() const { return stamp; }
    void print(const Printer &p) const;
};

#endif