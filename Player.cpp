#include "Player.hpp"

Player::Player(unsigned posY, unsigned posX, const String &n)
    : y(posY), x(posX),
      name(n), inv(new Inventar)
{
    for (unsigned i = 0; i < Constants::EQUIPMENT_COUNT; ++i)
        equip[i] = nullptr;
}

Player::Player(std::ifstream &ifs)
    : inv(new Inventar)
{
    int buf;
    ifs >> buf;
    ifs.ignore();
    char *readName = new char[buf + 1];
    ifs.getline(readName, buf + 1);
    name = readName;

    // todo baaaad
    ifs >> y >> y >> y;
    // todo baaaad

    ifs >> y >> x;

    for (unsigned i = 0; i < Constants::EQUIPMENT_COUNT; ++i)
        equip[i] = nullptr;
    // todo read equipment and inventar
    delete[] readName;
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

void Player::printBattleState(Dragon &d) const
{
    system("cls");
    printBrief();
    Constants::STDOUT(GameAssets::battle_icon);
    d.print();
}

void Player::hit(Dragon &d)
{
    Constants::STDOUT("\nx - basic attack");
    if (equip[0])
        Constants::STDOUT(" using ")(equip[0]->getName());
    if (equip[2])
        Constants::STDOUT("\tz - cast \"")(equip[2]->getName())("\"");
    Constants::STDOUT('\n');
    char c;
    while ((c = getch()) != 'x' && (!equip[2] || c != 'z'))
    {
    }
    if (c == 'z')
    {
        printBattleState(d);
        if (payCost(equip[2]->getCost()))
        {
            Constants::STDOUT("\n\tspell attack...");
            d.takeDamage(getAttack() + equip[2]->getBonus() * getAttack());
        }
        else
        {
            Constants::STDOUT("\n\tnot enough mana...");
            hit(d);
        }
    }
    // improve
    else if (c == 'x')
    {
        printBattleState(d);
        Constants::STDOUT("\n\tmellee attack...");
        d.takeDamage(getAttack() + (equip[0] ? equip[0]->getBonus() * getAttack() : 0));
    }
}

void Player::inventar()
{
    char c;
    printInventar();
    while ((c = getch()) != 'i')
    {
        if (c == 'z' && inv->getCount())
        {
            Constants::STDOUT("\nPress z again to cancel...");
            while ((c = getch()) != 'z' && (c - '0' < 1 || c - '0' - 1 >= inv->getCount()))
            {
            }
            if (c != 'z')
                delete inv->remove(c - '0' - 1);
            printInventar();
        }
        else if (c == 'x')
        {
            Constants::STDOUT("\nPress x again to cancel...");
            while ((c = getch()) != 'x' && c - '0' < 1 && c - '0' - 1 >= Constants::EQUIPMENT_COUNT)
            {
            }
            if (c != 'x' && equip[c - '0' - 1])
            {
                inv->put(*equip[c - '0' - 1]);
                delete equip[c - '0' - 1];
                equip[c - '0' - 1] = nullptr;
            }
            printInventar();
        }
        else if (c - '0' - 1 < inv->getCount() && c - '0' >= 1)
        {
            HeroEquipment *rem = inv->remove(c - '0' - 1);
            if ((size_t)rem->getID() >= Constants::EQUIPMENT_COUNT)
            {
                regenerate(rem->getBonus());
                delete rem;
            }
            else
            {
                HeroEquipment *&tmp = getMatching(rem);

                HeroEquipment *buf = tmp;
                tmp = rem;
                rem = buf;

                if (rem)
                    inv->put(*rem);
            }
            printInventar();
        }
    }
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
            bool turn = rand() % 2; // 0 for player;   1 for player
            while (alive() && p->alive())
            {
                p->printBattleState(*this);
                if (turn)
                {
                    Constants::STDOUT("You hit...");
                    p->hit(*this);
                }
                else if (alive())
                {
                    Constants::STDOUT("Dragon hits...");
                    getch();
                    p->takeDamage(attack);
                }
                turn = !turn;
                if (!turn && alive() && p->alive())
                    getch();
            }
            Constants::STDOUT('\n')(p->alive() ? GameAssets::victory_icon : GameAssets::defeat_icon);
            getch();
            if (p->alive())
            {
                p->regenerate();
                return Constants::ACTION_STATE::SUCCESSFULL;
            }
            else
                return Constants::ACTION_STATE::FAILED;
        }
    } while (response != 'e' && response != 'b');
    return Constants::ACTION_STATE::ESCAPED;
}

void Player::save(std::ofstream &ofs) const
{
    ofs << (int)getID() << '\n';
    ofs << name.size() << ' ' << name.c_str() << '\n';
    ofs << y << ' ' << x << '\n';
    for (unsigned i = 0; i < Constants::EQUIPMENT_COUNT; ++i)
        if (equip[i])
            equip[i]->save(ofs);
        else
            ofs << -1 << '\n';

    inv->write(ofs);
}