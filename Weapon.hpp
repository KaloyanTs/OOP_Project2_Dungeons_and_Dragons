#ifndef __WEAPON_HPP
#define __WEAPON_HPP
#include "HeroEquipment.hpp"
#include "Constants.hpp"

/// class representing weapon which can be worn by a player, improving his attack power by some percentage
class Weapon : public HeroEquipment
{
public:
    /// constructor, placing the weapon on certain position on the board and setting bounds for the given bonus, name is randomly generated
    Weapon(unsigned y, unsigned x, unsigned bot, unsigned top = 0, bool onBoard = true);
    /// constructor, creating weapon owned by a hero and having only bonus and name
    Weapon(unsigned bonus, const String &name)
        : HeroEquipment(bonus, name, &GameAssets::weapon_icon) {}
    /// virtual clone function
    Weapon *clone() const { return new Weapon(*this); }
    /// printing image, name and bonus of this weapon
    void print() const;
    /// getter for the ID (used in saving and reading equipment)
    ID getID() const { return ID::WEAPON; }
    /// getter for the cost of the usage of this weapon (it is always 0)
    float getCost() const { return 0; }
};

#endif