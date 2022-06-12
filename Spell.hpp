#ifndef __SPELL_HPP
#define __SPELL_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

/// class representing a spell which can be cast dealing some damage to an enemy
class Spell : public HeroEquipment
{
    float cost;

public:
    /// constructor, placing the spell on certain position on the board, cost and setting bounds for the given bonus, name is randomly generated
    Spell(unsigned y, unsigned x, unsigned bot, unsigned top = 0, bool onBoard = true, unsigned c = 0);
    /// constructor, creating spell owned by a hero and having only bonus, cost and name
    Spell(unsigned bonus, unsigned c, const String &name)
        : HeroEquipment(bonus, name, &GameAssets::spell_icon), cost(c) {}
    /// virtual clone function
    Spell *clone() const { return new Spell(*this); }
    /// printing image, name, bonus and cost of this spell
    void print() const;
    /// getter for the ID (used in saving and reading equipment)
    ID getID() const { return ID::SPELL; }
    /// getter for the cost for casting the spell
    float getCost() const { return cost; };
};

#endif