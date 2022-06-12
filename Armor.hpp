#ifndef __ARMOR_HPP
#define __ARMOR_HPP
#include <algorithm>
#include "HeroEquipment.hpp"
#include "Constants.hpp"

/// class representing armor of the player protecting him from enemies damage with some bonus
class Armor : public HeroEquipment
{

public:
    /// constructor, placing the armor on certain position on the board and setting bounds for the given bonus, name is randomly generated
    Armor(unsigned y, unsigned x, unsigned bot, unsigned top = 0, bool onBoard = true);
    /// constructor, creating armor owned by a hero and having only bonus and name
    Armor(unsigned bonus, const String &name)
        : HeroEquipment(bonus, name, &GameAssets::armor_icon) {}
    /// virtual clone function
    Armor *clone() const { return new Armor(*this); }
    /// printing image, name and bonus of this armor
    void print() const;
    /// getter for the ID (used in saving and reading equipment)
    ID getID() const { return ID::ARMOR; }
    /// getter for the cost of the usage of this armor (it is always 0)
    float getCost() const { return 0; }
};

#endif