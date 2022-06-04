#include "DragonQuoteGenerator.hpp"

DragonQuoteGenerator::DragonQuoteGenerator()
{
    addRule("S->Were you born this(1)INSULT(0)or did you work at it?(1)");
    addRule("S->Why even overstraining, there is emerging life more complex than you...(1)");
    addRule("S->All dragons are but pale immitations of my kind...(1)");
    addRule("S->Your survival is not impossible, only very... very... unlikely...(1)");
    addRule("S->Bravery is absurd - but admirable...(1)");
    addRule("S->Few can impress me. That's a compliment(1)");
    addRule("S->I kill where I wish and none dare exists...(1)");
    addRule("S->Tremble before the power of a dragon...(1)");
    addRule("S->Darkness is my only true enemy...(1)");
    addRule("INSULT->weak(1)|bad(1)|deficient(1)|faulty(1)");
}