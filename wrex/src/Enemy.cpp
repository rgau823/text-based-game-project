#include "Enemy.h"
#include "EnemyState.h"

#include <string>


Enemy::Enemy() {
    name = "The Mysterious Figure";
    state = new HostileState();
}

Enemy::~Enemy() {
    if (state) delete state;
}

bool Enemy::attack(Exorcist* e) {
    // These two lines could be called elsewhere, depending
    // on the context or we could create a setState() method.
    if (state) delete state;
    state = new PossessedState();

    state->attack(e);
    return true;
}

bool Enemy::talk(Exorcist* e) {
    state->talk(e);
    return true;
}

bool Enemy::gift(Exorcist* e) {
    state->gift(e);
    return true;
}
