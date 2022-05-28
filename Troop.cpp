#include "Troop.hpp"

void Troop::print(const Printer &p) const
{
    // p(GameAssets::stats_header, GameAssets::stats_count);
    std::cout << "HEALTH\tATTACK\tMAGIC\n"
              << health << '\t'
              << attack << '\t'
              << mana << '\n';
}
