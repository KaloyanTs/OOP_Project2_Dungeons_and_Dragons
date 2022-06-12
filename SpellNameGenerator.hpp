#ifndef __SPELL_NAME_GENERATOR_HPP
#define __SPELL_NAME_GENERATOR_HPP
#include "Grammar.hpp"

class SpellNameGenerator : public Grammar
{
    SpellNameGenerator();

public:
    static SpellNameGenerator &getInstance();
};

#endif