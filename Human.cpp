#include "Human.hpp"

void Human::print() const
{
    Constants::STDOUT(getName())("\nHuman\tlevel ")(getLevel())('\n');
    Troop::print();
    printItems();
}

void Human::printStats() const
{
    print();
}