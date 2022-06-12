#ifndef __SPELL_NAME_GENERATOR_HPP
#define __SPELL_NAME_GENERATOR_HPP
#include "Grammar.hpp"

/// singleton class generating random names of spells based on CFG grammar rules
class SpellNameGenerator : public Grammar
{
    SpellNameGenerator();

public:
    /// get access to the only object of type SpellNameGenerator
    static SpellNameGenerator &getInstance();
};

#endif