#include "Human.hpp"

void Human::print(const Printer &p) const
{
    std::clog << getName() << "\tHuman\n";
    Troop::print(p);
}

void Human::printStats(const Printer &p) const
{
    print(p);
}