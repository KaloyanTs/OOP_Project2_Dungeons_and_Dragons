#include "Player.hpp"

Player::Player(unsigned posY, unsigned posX, const String &n)
    : y(posY), x(posX),
      w(nullptr), a(nullptr), sp(nullptr), name(n), inv(new Inventar)
{
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
    delete w;
    delete a;
    delete sp;
    delete inv;
}

void Player::printItems(const Printer &p) const
{
    p("Your equipment:\n\n");
    if (w)
        w->print(p);
    if (a)
        a->print(p);
    if (sp)
        sp->print(p);
}

HeroEquipment *&Player::getMatching(const HeroEquipment *ptr)
{
    if (!w || w->getID() == ptr->getID())
        return w;
    else if (!a || a->getID() == ptr->getID())
        return a;
    else if (!sp || sp->getID() == ptr->getID())
        return sp;

    // fix error handling
    return w;
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