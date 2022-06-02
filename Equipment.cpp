#include "Equipment.hpp"

void Equipment::print() const
{
    Constants::STDOUT("Bonus: ")(bonus)('%');
}
