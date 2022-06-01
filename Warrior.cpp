#include "Warrior.hpp"

void Warrior::print() const
{
    Constants::STDOUT("\nWarrior\n"); // todo print level
    Troop::print();
    printItems();
}

void Warrior::printStats() const
{
    print();
}