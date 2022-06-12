#ifndef __GAME_ASSETS_HPP
#define __GAME_ASSETS_HPP
#include "Image.hpp"

/// class without instances keeping all images used in this project
class GameAssets
{
private:
    GameAssets() {}

public:
    static const Image potion_icon;
    static const Image victory_icon;
    static const Image defeat_icon;
    static const Image battle_icon;
    static const Image game_logo;
    static const Image empty_slot;
    static const Image health_icon;
    static const Image attack_icon;
    static const Image magic_icon;
    static const Image weapon_icon;
    static const Image armor_icon;
    static const Image spell_icon;
    static const Image dragon;
    static const size_t stats_count = 3;
    static const Image *stats_header[stats_count];
};

#endif