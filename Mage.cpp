#include "Mage.hpp"

void Mage::print(const Printer &p) const
{
    std::clog << getName() << "\tMage\n";
    Troop::print(p);
}

void Mage::printStats(const Printer &p) const
{
    print(p);
}