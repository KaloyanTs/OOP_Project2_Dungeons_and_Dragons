#ifndef __EQUIPMENT_HPP
#define __EQUIPMENT_HPP
#include "MultipleImagePrinter.hpp"

class Equipment
{
    String name;
    unsigned bonus;

public:
    Equipment(unsigned _bonus = 0) : bonus(_bonus) {}
    virtual ~Equipment() {}

    virtual Equipment *clone() const = 0;
    virtual void print(const Printer &p) const = 0;
    unsigned getBonus() const { return bonus; }
    const String &getName() { return name; }
};

#endif