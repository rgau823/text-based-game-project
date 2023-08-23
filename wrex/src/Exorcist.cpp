#include "Character.h"
#include "Exorcist.h"
#include "ExorcistState.h"

#include <string>
#include <vector>


Exorcist::Exorcist() {
    name = "Exorcist";
    state = new SaneState();
}

Exorcist::~Exorcist() {
    if (state) delete state;
}

bool Exorcist::attack(Enemy* e) {
    // These two lines could be called elsewhere, depending
    // on the context or we could create a setState() method.
    if (state) delete state;
    state = new PossessedState();

    state->attack(e);
    return true;
}

bool Exorcist::flee(Enemy* e) {
    state->flee(e);
    return true;
}
