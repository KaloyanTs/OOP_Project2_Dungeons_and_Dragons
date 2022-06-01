#include "Human.hpp"

void Human::print() const
{
    printBrief();
    printItems();
}

void Human::printStats() const
{
    print();
}

void Human::printBrief() const
{   
    //todo add equipments
    Constants::STDOUT(getName())("\nHuman\tlevel ")(getLevel())('\n');
    Troop::print();
}