#include "Dragon.hpp"

String Dragon::errorMsg = "You could not stand a chance against this dragon but you fought bravely and died...\n";

void Dragon::print() const
{
    Constants::STDOUT (*pic)("Dragon ")(getLevel())(".lvl\n");
    Troop::print();
}

Constants::ACTION_STATE Dragon::action(Player *p, bool &run)
{
    Constants::STDOUT("Would you try to slay this dragon?\nb for battle\ne for escape\n");
    char response;
    do
    {
        response = getch();
        if (response == 'b')
        {
            // fix must battle here
            // if died   run=false
            return Constants::ACTION_STATE::SUCCESSFULL;
        }
    } while (response != 'e' && response != 'b');
    return Constants::ACTION_STATE::ESCAPED;
}