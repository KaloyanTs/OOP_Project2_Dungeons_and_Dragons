#include "Warrior.hpp"

void Warrior::print(const Printer &p) const
{
    std::clog << getName() << "\tWarrior\n";
    Troop::print(p);
}

void Warrior::printStats(const Printer &p) const
{
    print(p);
}