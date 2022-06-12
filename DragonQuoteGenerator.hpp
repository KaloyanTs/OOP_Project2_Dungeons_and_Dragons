#ifndef __DRAGON_QUOTE_GENERATOR_HPP
#define __DRAGON_QUOTE_GENERATOR_HPP
#include "Grammar.hpp"

/// singleton class generating random quotes of dragons based on CFG grammar rules
class DragonQuoteGenerator : public Grammar
{
    DragonQuoteGenerator();

public:
    /// get access to the only object of type DragonQuoteGenerator
    static DragonQuoteGenerator &getInstance();
};

#endif