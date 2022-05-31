#include "Warrior.hpp"

void Warrior::print(const Printer &p) const
{
    std::clog << getName() << "\nWarrior\n"; // todo print level
    Troop::print(p);
}

void Warrior::printStats(const Printer &p) const
{
    print(p);
}