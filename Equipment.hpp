#ifndef __EQUIPMENT_HPP
#define __EQUIPMENT_HPP
#include "Constants.hpp"

/// abstract class representing equipment having name and giving some bonus to the owner's stats
class Equipment
{

protected:
    unsigned bonus;
    String name;
    Equipment(unsigned b, const String &n)
        : bonus(b), name(n) {}

public:
    /// construct equipment with bonus (in percents) and no name
    Equipment(unsigned _bonus = 0) : bonus(_bonus) {}
    /// virtual destructor
    virtual ~Equipment() = default;
    /// pure virtual clone function
    virtual Equipment *clone() const = 0;
    /// print equipment's bonus
    virtual void print() const;
    /// get bonus (as a multiplier)
    float getBonus() const { return (float)bonus / 100; }
    /// get this equipment's name
    const String &getName() { return name; }
};

#endif