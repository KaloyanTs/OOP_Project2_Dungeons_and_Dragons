#include "HeroEquipment.hpp"

bool HeroEquipment::action()
{
    std::cout << "Do you want to take this item?\ne for take\nx for ignore\n";
    char response;
    do
    {
        response = getch();
        if (response == 'e')
        {
            // p->take(*this);
            return true;
        }
    } while (response != 'e' && response != 'x');
    return false;
}

void HeroEquipment::print(const Printer &p) const
{
    p(*pic);
}