#include "WeaponNameGenerator.hpp"

WeaponNameGenerator::WeaponNameGenerator()
{
    addRule("S->the(1)DESCRIPTION(0)|DESCRIPTION(0)");
    addRule("DESCRIPTION->ADJ(0)NOUN(0)ENDING(0)|RARITY(0)OTHER(0)");
    addRule("OTHER->ENEMY(0)DAMAGE(0)|NOUN(0)of(1)CREATORS(0)");
    addRule("ENEMY->zombie(1)|dragon(1)|troll(1)|orc(1)|tiger(1)");
    addRule("DAMAGE->slayer(1)|killer(1)|destroyer(1)");
    addRule("CREATORS->vikings(1)|hobbits(1)|elfs(1)|gods(1)|hell(1)|chaos(1)|wisdom(1)|prophecy(1)");
    addRule("ENDING->(1)|of(1)SMTH(0)");
    addRule("RARITY->common(1)|rare(1)|epic(1)|legendary(1)|mythical(1)");
    addRule("SMTH->(1)|death(1)|destiny(1)|gods(1)|chaos(1)");
    addRule("ADJ->mighty(1)|powerfull(1)|muscular(1)|heavy(1)|vigorous(1)");
    addRule("NOUN->blade(1)|fire(1)|sword(1)|katana(1)|hammer(1)|gun(1)|bazooka(1)|rocket(1)|spear(1)|bow(1)");
}