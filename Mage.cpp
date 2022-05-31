#include "Mage.hpp"

void Mage::print(const Printer &p) const
{
    std::clog << getName() << "\nMage\n"; // todo print level
    Troop::print(p);
    printItems(p);
}

void Mage::printStats(const Printer &p) const
{
    print(p);
}