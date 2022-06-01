#include "Mage.hpp"

void Mage::print() const
{
    printBrief();
    printItems();
}

void Mage::printStats() const
{
    print();
}

void Mage::printBrief() const
{
    Constants::STDOUT(getName())("\nMage\tlevel ")(getLevel())('\n');
    Troop::print();
}