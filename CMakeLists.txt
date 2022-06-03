cmake_minimum_required(VERSION 3.0.0)
project(DungeonsAndDragons VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(DungeonsAndDragons main.cpp Potion.cpp PotionNameGenerator.cpp Equipment.cpp Mage.cpp Human.cpp Warrior.cpp ArmorNameGenerator.cpp SpellNameGenerator.cpp WeaponNameGenerator.cpp Constants.cpp Grammar.cpp Inventar.cpp String.cpp Armor.cpp Weapon.cpp Spell.cpp HeroEquipment.cpp Player.cpp Map.cpp Image.cpp MultipleImagePrinter.cpp Troop.cpp GameAssets.cpp Dragon.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
