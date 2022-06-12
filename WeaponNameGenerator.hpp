#ifndef __WEAPON_NAME_GENERATOR_HPP
#define __WEAPON_NAME_GENERATOR_HPP
#include "Grammar.hpp"

class WeaponNameGenerator : public Grammar
{
    WeaponNameGenerator();

public:
    static WeaponNameGenerator &getInstance();
};

#endif