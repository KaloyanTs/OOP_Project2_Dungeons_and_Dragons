#include "Player.hpp"

Player::Player(unsigned posY, unsigned posX, const String &n)
    : y(posY), x(posX),
      name(n), inv(new Inventar)
{
    for (unsigned i = 0; i < Constants::EQUIPMENT_COUNT; ++i)
        equip[i] = nullptr;
}

bool operator==(char c, const KEYS &k)
{
    return (char)k == c;
}

bool Player::take(const HeroEquipment &eq) const
{
    return inv->put(eq);
}

Player::~Player()
{
    for (unsigned i = 0; i < Constants::EQUIPMENT_COUNT; ++i)
        delete equip[i];
    delete inv;
}

void Player::printItems(const Printer &p) const
{
    p("Your equipment:\n\n");
    unsigned spaces = Constants::DISPLAY_WIDTH / 2;

    for (unsigned i = 0; i < spaces; ++i)
        std::cout << '<';
    for (unsigned i = 0; i < spaces; ++i)
        std::cout << '>';
    std::cout << '\n';

    for (unsigned i = 0; i < Constants::EQUIPMENT_COUNT; ++i)
    {
        if (equip[i])
            equip[i]->print(p);
        else
            p(GameAssets::empty_slot);
        for (unsigned i = 0; i < spaces; ++i)
            std::cout << '<';
        for (unsigned i = 0; i < spaces; ++i)
            std::cout << '>';
        std::cout << '\n';
    }
    std::cout << '\n';
}

HeroEquipment *&Player::getMatching(const HeroEquipment *ptr)
{
    return equip[(unsigned)ptr->getID()];
}

void Player::printInventar() const
{
    system("cls");
    printStats(lazy);
    inv->print(lazy, name);
    lazy("\nTo equip an item enter its number in the list.\nIf slot is taken items will be swapped.\n\nTo disequip an item enter x and the number of the equiped item in the list\n");
}

Constants::ACTION_STATE HeroEquipment::action(Player *p, bool &run)
{
    std::cout << "Do you want to take this item?\ne for take\nx for ignore\n";
    char response;
    do
    {
        response = getch();
        if (response == 'e')
        {
            if (!p->take(*this))
                return Constants::ACTION_STATE::FAILED;
            else
                return Constants::ACTION_STATE::SUCCESSFULL;
        }
    } while (response != 'e' && response != 'x');
    return Constants::ACTION_STATE::ESCAPED;
}