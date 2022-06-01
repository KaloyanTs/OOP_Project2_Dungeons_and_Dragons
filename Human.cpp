#include "Human.hpp"

void Human::print() const
{
    Constants::STDOUT("\nHuman\n"); // todo print level
    Troop::print();
    printItems();
}

void Human::printStats() const
{
    print();
}