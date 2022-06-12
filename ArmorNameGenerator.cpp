#include "ArmorNameGenerator.hpp"

ArmorNameGenerator::ArmorNameGenerator()
{
    addRule("S->ARTICLE(0)ADJ(0)TYPE(0)ENDING(0)");
    addRule("TYPE->helmet(1)|armor(1)|mantle(1)|shield(1)|chainmail(1)");
    addRule("ARTICLE->(1)|the(1)");
    addRule("ADJ->(1)|holy(1)|dragon scale(1)|lion's(1)|death(1)|thunder(1)|fire(1)");
    addRule("ENDING->of the(1)PURPOSE(0)|from(1)CREATOR(0)");
    addRule("CREATOR->gods(1)|heaven(1)|elfs(1)|witches(1)");
    addRule("PURPOSE->traveller(1)|wizard(1)|elfs(1)|witches(1)|chaos(1)|knight(1)|gladiator(1)|nature(1)|order(1)|elf king(1)");
}

ArmorNameGenerator &ArmorNameGenerator::getInstance()
{
    static ArmorNameGenerator obj;
    return obj;
}