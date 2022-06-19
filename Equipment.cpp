#include "Equipment.hpp"

void Equipment::print() const
{
    Constants::out << "Bonus: " << bonus << '%';
}
