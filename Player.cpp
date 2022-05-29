#include "Player.hpp"

bool operator==(char c, const KEYS &k)
{
    return (char)k == c;
}

bool Player::take(const HeroEquipment &eq) const
{
    return true;
    //inv.put(eq);
}
