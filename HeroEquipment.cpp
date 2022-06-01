#include "HeroEquipment.hpp"

String HeroEquipment::errorMsg = "Your inventar is full!\nRemove an item first.\n";

void HeroEquipment::print() const
{
    Constants::STDOUT(*pic);
}