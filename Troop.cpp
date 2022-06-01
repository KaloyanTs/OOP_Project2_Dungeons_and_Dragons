#include "Troop.hpp"

void Troop::print() const
{
    // p(GameAssets::stats_header, GameAssets::stats_count);
    Constants::STDOUT("HEALTH\tATTACK\tMAGIC\n");
    Constants::STDOUT(health);
    Constants::STDOUT('\t');
    Constants::STDOUT(attack);
    Constants::STDOUT('\t');
    Constants::STDOUT(mana);
    Constants::STDOUT('\n');
}

float Troop::determineStat(unsigned lvl, float init, float perLevel) const
{
    for (unsigned i = 1; i < lvl; ++i)
        init *= perLevel;
    return init;
}
