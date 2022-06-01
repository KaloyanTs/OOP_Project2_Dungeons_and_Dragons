#include "GameAssets.hpp"

const Image GameAssets::empty_slot("assets\\emptySlot.dnd");
const Image GameAssets::health_icon("assets\\health.dnd");
const Image GameAssets::attack_icon("assets\\weapon.dnd");
const Image GameAssets::magic_icon("assets\\spell.dnd");
const Image GameAssets::dragon("assets\\dragon.dnd");
const Image GameAssets::weapon_icon("assets\\weapon.dnd");
const Image GameAssets::armor_icon("assets\\armor.dnd");
const Image GameAssets::spell_icon("assets\\spell.dnd");
const Image *GameAssets::stats_header[] = {
    &health_icon, &attack_icon, &magic_icon};