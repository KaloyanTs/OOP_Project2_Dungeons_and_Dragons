#include "SpellNameGenerator.hpp"

SpellNameGenerator::SpellNameGenerator()
{
    addRule("S->SIMPLE(0)|SUPPORT(0)"); // todo more to be added -> SPECIAL
    addRule("SIMPLE->BASICADJ(0)BASIC(0)|BASICADJ(0)BASICADJ(0)BASIC(0)|BASIC(0)");
    addRule("BASICADJ->burning(1)|vaporizing(1)|paralizing(1)|toxic(1)|poisonous(1)");
    addRule("BASIC->fireball(1)|thunder(1)|ignition(1)|slash(1)|hypnose(1)|fire ring(1)|plague(1)");
    addRule("SUPPORT->NAME(0)DESCRIPTION(0)");
    addRule("NAME->CAP(0)L(0)L(0)|CAP(0)L(0)");
    addRule("CAP->Kin(2)|Fin(2)|Si(2)|Po(2)|Mir(2)|Wu(2)|Gro(2)");
    addRule("L->ton(2)|kesh(2)|li(2)|tu(2)|cunt(2)|ztix(2)|erch(2)");
    addRule("DESCRIPTION->, the(1)ADJTYPE(0)from the(1)SPAN(0)");
    addRule("ADJTYPE->ADJ(0)TYPE(0)|TYPE(0)");
    addRule("ADJ->mighty(1)|unbeatable(1)|wicked(1)|dark(1)|winged(1)|burning(1)|icy(1)|shocking(1)|black(1)|magical(1)");
    addRule("TYPE->dragon(1)|dinosaur(1)|phoenix(1)|behemoth(1)|angel(1)|hydra(1)");
    addRule("SPAN->lake(1)|skies(1)|heaven(1)|darkness(1)|graveyard(1)|woods(1)");
}