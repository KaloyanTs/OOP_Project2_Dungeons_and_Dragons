#include "PotionNameGenerator.hpp"

PotionNameGenerator::PotionNameGenerator()
{
    addRule("S->CREATE(0)KIND(0)of(1)END(0)");
    addRule("CREATE->the(1)CREATOR(0)'s(1)|(2)");
    addRule("CREATOR->sorcerer(2)|viking(2)|elf(2)|enchantor(2)|wizard(2)");
    addRule("KIND->potion(1)|elixir(1)|drink(1)|tonic(1)");
    addRule("END->ABILITY(0)SECOND(0)");
    addRule("SECOND->(2)|and(1)ABILITY(0)");
    addRule("ABILITY->ADJ(0)NOUN(0)|NOUN(0)");
    addRule("ADJ->ancient(1)|instant(1)|high(1)");
    addRule("NOUN->perfection(1)|knowledge(1)|will(1)|insanity(1)|vitality(1)|ancestry(1)|ecstasy(1)|power(1)|anger(1)|levitation(1)|foresight(1)|wisdom(1)");
}

PotionNameGenerator &PotionNameGenerator::getIntance()
{
    static PotionNameGenerator obj;
    return obj;
}