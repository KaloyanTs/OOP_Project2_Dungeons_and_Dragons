#include "Troop.hpp"

Troop::Troop(std::ifstream &ifs)
{
    std::cout << "reading stats...";
    getch();
    ifs >> maxHealth >> maxMana >> attack >> mana >> health >> xpNeeded;
}

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

void Troop::gainXP(unsigned gain)
{
    if (xpNeeded <= gain)
    {
        do
        {
            levelUp();
            gain -= xpNeeded;
            xpNeeded = level * XP_NEED_ACUMULATION;
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
    Constants::STDOUT("You are now level ")(++level)("\n\tChoose how to distribute ")(LEVEL_UP_POINTS)(" points...\n");
    Constants::STDOUT("\tPoints improving attack\t(currently ")(attack)("): ");
    std::cin >> a;
    while (sum + a > LEVEL_UP_POINTS)
    {
        Constants::STDOUT("Too much power gained! Try again...\n");
        std::cin >> a;
    }
    sum += a;

    Constants::STDOUT("\tPoints improving health\t(currently ")(health)("): ");
    std::cin >> h;
    while (sum + h > LEVEL_UP_POINTS)
    {
        Constants::STDOUT("Too much power gained! Try again...\n");
        std::cin >> h;
    }
    sum += h;

    Constants::STDOUT("\tPoints improving mana\t(currently ")(mana)("): ");
    std::cin >> m;
    while (sum + m > LEVEL_UP_POINTS)
    {
        Constants::STDOUT("Too much power gained! Try again...\n");
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
    ofs << maxHealth << ' ' << maxMana << '\n'
        << attack << ' ' << mana << ' ' << health << '\n'
        << xpNeeded << '\n';
}