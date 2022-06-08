#ifndef __CONSTANTS_HPP
#define __CONSTANTS_HPP
#include "WeaponNameGenerator.hpp"
#include "ArmorNameGenerator.hpp"
#include "SpellNameGenerator.hpp"
#include "PotionNameGenerator.hpp"
#include "DragonQuoteGenerator.hpp"
#include "MultipleImagePrinter.hpp"

#define INITIAL_MINIMAL_BONUS 5
#define MINIMUM_BONUS_PER_LEVEL 5

#define INITIAL_MAXIMAL_BONUS 10
#define MAXIMAL_BONUS_PER_LEVEL 25

#define INITIAL_MINIMAL_COST 10
#define COST_PER_LEVEL 10

#define POTION_INITIAL_MINIMAL_COST 15
#define POTION_INITIAL_MAXIMAL_COST 30
#define POTION_COST_PER_LEVEL 7

#define EPS 1e-3

class Constants
{
    Constants() {}

public:
    enum class ACTION_STATE
    {
        ESCAPED,
        SUCCESSFULL,
        FAILED
    };
    enum class LEVEL_STATE
    {
        ERROR,
        PASS,
        DIE,
        CLOSE,
        PAUSE
    };
    static bool equal(float a, float b) { return a - b < EPS && a - b > -EPS; }
    static bool less(float a, float b) { return a - b <= -EPS; }
    static bool greater(float a, float b) { return a - b >= EPS; }
    static const Printer STDOUT;
    static const MultipleImagePrinter STDOUT_MULTI;
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
    static const WeaponNameGenerator weapon_name_generator;
    static const ArmorNameGenerator armor_name_generator;
    static const SpellNameGenerator spell_name_generator;
    static const PotionNameGenerator potion_name_generator;
    static const DragonQuoteGenerator dragon_quote_generator;
};

#endif