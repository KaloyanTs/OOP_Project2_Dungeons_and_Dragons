#include "Troop.hpp"

Troop::Troop(std::ifstream &ifs)
{
    ifs >> level >> maxHealth >> maxMana >> attack >> mana >> health >> xpNeeded;
}

void Troop::print(float attackBonus) const
{
    // p(GameAssets::stats_header, GameAssets::stats_count);
    Constants::out << "HEALTH\t\tATTACK\tMANA\n"
                   << health << '\\' << maxHealth;
    Constants::out << '\t' << (1 + attackBonus) * attack << '\t' << mana << '\\' << maxMana << '\n';
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

void Troop::gainXP(unsigned gain)
{
    if (xpNeeded <= gain)
    {
        do
        {
            levelUp();
            gain -= xpNeeded;
            xpNeeded = level * Constants::XP_NEED_ACUMULATION;
        } while (gain >= xpNeeded);
        xpNeeded -= gain;
    }
    else
        xpNeeded -= gain;
}

void Troop::levelUp()
{
    system("cls");
    unsigned sum = 0;
    unsigned a, h, m;
    Constants::out << "You are now level " << ++level << "\n\tChoose how to distribute " << Constants::LEVEL_UP_POINTS << " points...\n";
    Constants::out << "\tPoints improving attack\t(currently " << attack << "): ";
    std::cin >> a;
    while (sum + a > Constants::LEVEL_UP_POINTS)
    {
        Constants::out << "Too much power gained! Try again...\n";
        std::cin >> a;
    }
    sum += a;

    Constants::out << "\tPoints improving health\t(currently " << maxHealth << "): ";
    std::cin >> h;
    while (sum + h > Constants::LEVEL_UP_POINTS)
    {
        Constants::out << "Too much power gained! Try again...\n";
        std::cin >> h;
    }
    sum += h;

    Constants::out << "\tPoints improving mana\t(currently " << maxMana << "): ";
    std::cin >> m;
    while (sum + m > Constants::LEVEL_UP_POINTS)
    {
        Constants::out << "Too much power gained! Try again...\n";
        std::cin >> m;
    }
    maxHealth += h;
    health = maxHealth;
    attack += a;
    maxMana += m;
    mana = maxMana;
}

void Troop::save(std::ofstream &ofs) const
{
    ofs << level << ' ' << maxHealth << ' ' << maxMana << '\n'
        << attack << ' ' << mana << ' ' << health << '\n'
        << xpNeeded << '\n';
}