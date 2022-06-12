#ifndef __ARMOR_NAME_GENERATOR_HPP
#define __ARMOR_NAME_GENERATOR_HPP
#include "Grammar.hpp"

class ArmorNameGenerator : public Grammar
{
    ArmorNameGenerator();
public:
    static ArmorNameGenerator &getInstance();
};

#endif