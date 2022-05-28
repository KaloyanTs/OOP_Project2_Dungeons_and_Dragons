#include "Player.hpp"

bool Player::move()
{
    char c = getch();
    if ((int)c < 0 && !isArrow)
    {
        isArrow = true;
        return false;
    }
    if ((int)c < 0)
        return;
    if (isArrow)
    {
        std::cout << "Arrow\n";
        if (c == KEYS::UP && y)
            --y;
        else if (c == KEYS::DOWN && y + 1 < limY)
            ++y;
        else if (c == KEYS::LEFT && x)
            --x;
        else if (c == KEYS::DOWN && x + 1 < limX)
            ++x;
        isArrow = false;
        return true;
    }
    return false;
}

bool operator==(char c, const KEYS &k)
{
    return (char)k == c;
}
