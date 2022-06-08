#include "Troop.hpp"

void Troop::print(float attackBonus) const
{
    // p(GameAssets::stats_header, GameAssets::stats_count);
    Constants::STDOUT("HEALTH\tATTACK\tMANA\n")(health)('\t')((1 + attackBonus) * attack)('\t')(mana)('\n');
}

float Troop::determineStat(unsigned lvl, float init, float perLevel) const
{
    for (unsigned i = 1; i < lvl; ++i)
        init *= perLevel;
    return init;
}

void Troop::takeDamage(float dmg)
{
    if (Constants::greater(dmg, health))
        health = 0;
    health -= dmg;
}

bool Troop::payMana(float points)
{
    if (Constants::less(mana, points))
        return false;
    mana -= points;
    return true;
}

void Troop::regen(float percentage)
{
    if (!percentage)
    {
        if (health < maxHealth / 2)
            health = maxHealth / 2;
    }
    else
    {
        health += percentage * maxHealth;
        if (Constants::greater(health, maxHealth))
            health = maxHealth;
    }
}
