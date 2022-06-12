#ifndef __WEAPON_NAME_GENERATOR_HPP
#define __WEAPON_NAME_GENERATOR_HPP
#include "Grammar.hpp"

/// singleton class generating random names of weapons based on CFG grammar rules
class WeaponNameGenerator : public Grammar
{
    WeaponNameGenerator();

public:
    /// get access to the only object of type WeaponNameGenerator
    static WeaponNameGenerator &getInstance();
};

#endif