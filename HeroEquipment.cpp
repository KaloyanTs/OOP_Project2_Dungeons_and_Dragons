#include "HeroEquipment.hpp"

bool HeroEquipment::action(Player *p)
{
    std::cout << "Do you want to take this item?\ne for equip\nx for ignore\n";
    char response;
    do
    {
        response = getch();
        if (response == 'e')
        {
            //p->take(*this);
            return true;
        }
    } while (response != 'e' && response != 'x');
    return false;
}