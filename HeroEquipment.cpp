#include "HeroEquipment.hpp"

bool HeroEquipment::action()
{
    std::cout << "Do you want to equip this item?\ne for equip\nx for ignore\n";
    char response;
    do
    {
        response = getch();
        if (response == 'e')
        {
            return true;
        }
    } while (response != 'e' && response != 'x');
    return false;
}