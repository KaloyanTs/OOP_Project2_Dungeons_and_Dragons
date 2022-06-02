#ifndef __EQUIPMENT_HPP
#define __EQUIPMENT_HPP
#include "Constants.hpp"
#include "MultipleImagePrinter.hpp"

class Equipment
{
    unsigned bonus;

protected:
    String name;

public:
    Equipment(unsigned _bonus = 0) : bonus(_bonus) {}
    virtual ~Equipment() = default;

    virtual Equipment *clone() const = 0;
    virtual void print() const;
    float getBonus() const { return (float)bonus / 100; }
    const String &getName() { return name; }
};

#endif