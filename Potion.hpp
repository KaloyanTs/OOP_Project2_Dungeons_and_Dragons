#ifndef __POTION_HPP
#define __POTION_HPP
#include "HeroEquipment.hpp"

/// class representing potion which a player can drink in order to gain some health
class Potion : public HeroEquipment
{

public:
    /// construct a potion on the board by its position, bounds for the health it gives and visibility
    Potion(unsigned y, unsigned x, unsigned bot, unsigned top = 0, bool onBoard = true);
    /// constructor, creating potion owned by a hero and having only bonus and name
    Potion(unsigned bonus, const String &name)
        : HeroEquipment(bonus, name, &GameAssets::potion_icon) {}
    /// virtual clone function
    Potion *clone() const { return new Potion(*this); }
    /// printing image, name and bonus of this potion
    void print() const;
    /// getter for the ID (used in saving and reading equipment)
    ID getID() const { return ID::POTION; }
    /// getter for the cost of the usage of this potion (it is always 0)
    float getCost() const { return 0; }
};

#endif