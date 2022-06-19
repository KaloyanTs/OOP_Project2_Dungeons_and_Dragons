#ifndef __CONSTANTS_HPP
#define __CONSTANTS_HPP
#include "WeaponNameGenerator.hpp"
#include "ArmorNameGenerator.hpp"
#include "SpellNameGenerator.hpp"
#include "PotionNameGenerator.hpp"
#include "DragonQuoteGenerator.hpp"
#include "GameAssets.hpp"

/// class without instances keeping all the constants in this project
class Constants
{
    Constants() {}

public:
    /// enum of values used to determine the result of action on the map
    enum class ACTION_STATE
    {
        ESCAPED,
        SUCCESSFULL,
        FAILED
    };
    /// enum of values used to determine how is the game going
    enum class LEVEL_STATE
    {
        ERROR,
        PASS,
        DIE,
        CLOSE,
        PAUSE,
        END
    };
    static std::ostream &out;
    static const unsigned INITIAL_MINIMAL_BONUS = 5;
    static const unsigned MINIMUM_BONUS_PER_LEVEL = 5;
    static const unsigned INITIAL_MAXIMAL_BONUS = 10;
    static const unsigned MAXIMAL_BONUS_PER_LEVEL = 25;
    static const unsigned INITIAL_MINIMAL_COST = 10;
    static const unsigned COST_PER_LEVEL = 10;
    static const unsigned POTION_INITIAL_MINIMAL_COST = 15;
    static const unsigned POTION_INITIAL_MAXIMAL_COST = 30;
    static const unsigned POTION_COST_PER_LEVEL = 7;
    static const unsigned LEVEL_COUNT = 4;
    static const unsigned LEVEL_UP_POINTS;
    static const unsigned XP_NEED_ACUMULATION = 5;
    static const unsigned XP_DROP_PER_LEVEL = 2;
    /// function comparing floats with precision
    static bool equal(float a, float b) { return a - b < EPS && a - b > -EPS; }
    /// function comparing floats with precision
    static bool less(float a, float b) { return a - b <= -EPS; }
    /// function comparing floats with precision
    static bool greater(float a, float b) { return a - b >= EPS; }
    static const unsigned INPUT_LIMIT = 100;
    static const unsigned DRAGON_ARMOR_INIT = 15;
    static const unsigned DRAGON_ARMOR_PER_LEVEL = 5;
    static const unsigned EQUIPMENT_COUNT = 3;
    static const unsigned DISPLAY_WIDTH = 60;
    static const unsigned HERO_TYPES = 3;
    static const unsigned INVENTAR_LIMIT = 4;
    static const unsigned HERO_LEVELUP_POINTS = 30;
    static const unsigned WARRIOR_INIT_ATTACK = 40;
    static const unsigned WARRIOR_INIT_MANA = 10;
    static const unsigned WARRIOR_INIT_HEALTH = 50;
    static const unsigned MAGE_INIT_ATTACK = 10;
    static const unsigned MAGE_INIT_MANA = 40;
    static const unsigned MAGE_INIT_HEALTH = 50;
    static const unsigned HUMAN_INIT_ATTACK = 30;
    static const unsigned HUMAN_INIT_MANA = 20;
    static const unsigned HUMAN_INIT_HEALTH = 50;
    static const unsigned MONSTER_INIT_ATTACK = 25;
    static const unsigned MONSTER_INIT_MANA = 25;
    static const unsigned MONSTER_INIT_HEALTH = 50;
    static const unsigned MONSTER_COUNT_1 = 2;
    static const unsigned MONSTER_COUNT_2 = 3;
    static const unsigned TREASURE_COUNT_1 = 2;
    static const unsigned TREASURE_COUNT_2 = 2;
    /// precision of floats
    static const float EPS;
};

#endif