#include "Warrior.hpp"

void Warrior::print() const
{
    Constants::STDOUT(getName())("\nWarrior\tlevel ")(getLevel())('\n');
    Troop::print();
    printItems();
}

void Warrior::printStats() const
{
    print();
}