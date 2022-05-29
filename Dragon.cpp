#include "Dragon.hpp"

void Dragon::print(const Printer &p) const
{
    p(*pic);
    p("Dragon ")(level)(".lvl\n");
    Troop::print(p);
}

bool Dragon::action()
{
    std::cout << "Would you try to slay this dragon?\nb for battle\ne for escape\n";
    char response;
    do
    {
        response = getch();
        if (response == 'b')
        {
            return true;
        }
    } while (response != 'e' && response != 'b');
    return false;
}