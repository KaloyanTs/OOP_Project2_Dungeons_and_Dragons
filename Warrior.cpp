#include "Warrior.hpp"

void Warrior::print() const
{
    printBrief();
    printItems();
}

void Warrior::printStats() const
{
    print();
}

void Warrior::printBrief() const
{
    Constants::STDOUT(getName())("\nWarrior\tlevel ")(getLevel())('\n');
    Troop::print();
}