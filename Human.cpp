#include "Human.hpp"

void Human::print(const Printer &p) const
{
    std::clog << getName() << "\nHuman\n"; // todo print level
    Troop::print(p);
    printItems(p);
}

void Human::printStats(const Printer &p) const
{
    print(p);
}