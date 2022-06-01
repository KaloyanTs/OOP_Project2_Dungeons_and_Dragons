#include "Mage.hpp"

void Mage::print() const
{
    Constants::STDOUT(getName())("\nMage\tlevel ")(getLevel())('\n');
    Troop::print();
    printItems();
}

void Mage::printStats() const
{
    print();
}