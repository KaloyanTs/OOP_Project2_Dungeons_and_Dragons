#ifndef __POTION_NAME_GENERATOR_HPP
#define __POTION_NAME_GENERATOR_HPP
#include "Grammar.hpp"

/// singleton class generating random names of potions based on CFG grammar rules
class PotionNameGenerator : public Grammar
{
    PotionNameGenerator();

public:
    /// get access to the only object of type PotionNameGenerator
    static PotionNameGenerator &getIntance();
};

#endif