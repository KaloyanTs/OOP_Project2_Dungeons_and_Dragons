#include "Mage.hpp"

void Mage::print() const
{
    Constants::STDOUT(getName());
    Constants::STDOUT("\nMage\n"); // todo print level
    Troop::print();
    printItems();
}

void Mage::printStats() const
{
    print();
}