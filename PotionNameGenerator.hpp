#ifndef __POTION_NAME_GENERATOR_HPP
#define __POTION_NAME_GENERATOR_HPP
#include "Grammar.hpp"

class PotionNameGenerator : public Grammar
{
    PotionNameGenerator();

public:
    static PotionNameGenerator &getIntance();
};

#endif