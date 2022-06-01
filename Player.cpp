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

void Player::printItems() const
{
    Constants::STDOUT("Your equipment:\n\n");
    unsigned spaces = Constants::DISPLAY_WIDTH / 2;

    for (unsigned i = 0; i < spaces; ++i)
        Constants::STDOUT('<');
    for (unsigned i = 0; i < spaces; ++i)
        Constants::STDOUT('>');
    Constants::STDOUT('\n');

    for (unsigned i = 0; i < Constants::EQUIPMENT_COUNT; ++i)
    {
        if (equip[i])
            equip[i]->print();
        else
            Constants::STDOUT(GameAssets::empty_slot);
        for (unsigned i = 0; i < spaces; ++i)
            Constants::STDOUT('<');
        for (unsigned i = 0; i < spaces; ++i)
            Constants::STDOUT('>');
        Constants::STDOUT('\n');
    }
    Constants::STDOUT('\n');
}

HeroEquipment *&Player::getMatching(const HeroEquipment *ptr)
{
    return equip[(unsigned)ptr->getID()];
}

void Player::printInventar() const
{
    system("cls");
    printStats();
    inv->print(name);
    Constants::STDOUT("\nTo equip an item enter its number in the list.\nIf slot is taken items will be swapped.\n\nTo disequip an item enter x and the number of the equiped item in the list.\n\nTo throw away an item press z and the number of the item in the inventary list.\n");
}

void Player::hit(Dragon &d) const
{
    // todo attack + equipment + way of attack (mellee/spell)
}

Constants::ACTION_STATE HeroEquipment::action(Player *p, bool &run)
{
    Constants::STDOUT("Do you want to take this item?\ne for take\nx for ignore\n");
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

Constants::ACTION_STATE Dragon::action(Player *p, bool &run)
{
    Constants::STDOUT("Would you try to slay this dragon?\nb for battle\ne for escape\n");
    char response;
    do
    {
        response = getch();
        if (response == 'b')
        {
            system("cls");
            p->printBrief();
            Constants::STDOUT(GameAssets::battle_icon);
            print();
            bool turn = rand() % 2; // 0 for player;   1 for player
            // // // while (alive() && p->alive())
            // // // {
            // // //     p->hit(*this);
            // // //     p->takeDamage(Troop::attack);
            // // //     turn = !turn;
            // // // }
            getch();
            return Constants::ACTION_STATE::SUCCESSFULL;
        }
    } while (response != 'e' && response != 'b');
    return Constants::ACTION_STATE::ESCAPED;
}