#include <iostream>
#include <string>

#include "Boss.h"
#include "BossState.h"
#include "Character.h"
#include "Enemy.h"
#include "NPC.h"

Boss::~Boss() {
    if (state) delete state;
}

BossState* Boss::getState() {
    return state;
}

bool Boss::attack(Character *c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    bool success = state->attack(c);
    if (!success) return false;

    int damage = getDamage();
    int health = c->getHealth();

    if (health > damage)
        c->takeDamage(damage);
    else
        c->takeDamage(health);

    std::cout << name << " dealt ";
    std::cout << damage << " damage ";
    std::cout << "to " << c->getName();
    std::cout << std::endl;

    return true;
}

void Boss::transmogrify(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    state->transmogrify(c);
}

void Boss::response() {
    std::cout << '\n' << name << ": ";
    state->response();
}

void Boss::setState(BossState::Type type) {
    if (state && type == state->type) return;
    if (state) delete state;

    switch (type) {
        case BossState::Type::Hostile:
        default:
            state = new HostileState;
            break;
        case BossState::Type::Vengeful:
            state = new VengefulState;
            break;
        case BossState::Type::Friendly:
            state = new FriendlyState;
            break;
        case BossState::Type::Dead:
            state = new DeadState;
            break;
    }

    transmogrify(this);
}

bool Boss::isFriendly() {
    if (state->type == BossState::Type::Friendly)
        return true;

    return false;
}

void Boss::viewState() {
    state->printState();
}
