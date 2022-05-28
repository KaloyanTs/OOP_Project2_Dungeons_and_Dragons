#include "Troop.hpp"

void Troop::print(const Printer &p) const
{
    // p(GameAssets::stats_header, GameAssets::stats_count);
    std::cout << "HEALTH\tATTACK\tMAGIC\n"
              << health << '\t'
              << attack << '\t'
              << mana << '\n';
}

float Troop::determineStat(unsigned lvl, float init, float perLevel) const
{
    for (unsigned i = 1; i < lvl; ++i)
        init *= perLevel;
    return init;
}
