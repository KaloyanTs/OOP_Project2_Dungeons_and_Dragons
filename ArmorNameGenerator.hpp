#ifndef __ARMOR_NAME_GENERATOR_HPP
#define __ARMOR_NAME_GENERATOR_HPP
#include "Grammar.hpp"

/// singleton class generating random names of armor based on CFG grammar rules
class ArmorNameGenerator : public Grammar
{
    ArmorNameGenerator();

public:
    /// get access to the only object of type ArmorNameGenerator
    static ArmorNameGenerator &getInstance();
};

#endif