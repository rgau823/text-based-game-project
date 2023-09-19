#include <iostream>

#include "BossState.h"
#include "DogBoss.h"
#include "Item.h"

DogBoss::DogBoss() {
    setName("Ghost Dog");
    setState(BossState::Type::Hostile);
    setHealth(150);
    setStrength(10);
    setDefense(5);
}

bool DogBoss::takeItem(Item* i) {
    if (i == nullptr)
        throw invalid_parameter_error("Item is a nullptr");

    bool accepted = state->takeItem(i);

    if (accepted) {
        Item::Identifier identifier = i->getIdentifier();

        if (identifier == Item::Identifier::DogCollar) {
            delete i;

            setState(BossState::Type::Friendly);
            return true;
        }
    }

    return false;
}

void DogBoss::update() {
    if (state->type == BossState::Type::Friendly)
        return;

    if (health > 70)
        setState(BossState::Type::Hostile);
    else if (health > 0)
        setState(BossState::Type::Vengeful);
    else
        setState(BossState::Type::Dead);
}

void DogBoss::buff(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    c->setStrength(c->getStrength() + 3);
    c->setDefense(c->getDefense() + 3);
}
