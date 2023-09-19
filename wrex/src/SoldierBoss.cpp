#include <iostream>

#include "BossState.h"
#include "Item.h"
#include "SoldierBoss.h"

SoldierBoss::SoldierBoss() {
    setName("Ghost Soldier");
    setState(BossState::Type::Hostile);
    setHealth(200);
    setStrength(20);
    setDefense(15);
}

bool SoldierBoss::takeItem(Item* i) {
    if (i == nullptr)
        throw invalid_parameter_error("Item is a nullptr");

    bool accepted = state->takeItem(i);

    if (accepted) {
        Item::Identifier identifier = i->getIdentifier();

        if (identifier == Item::Identifier::SoldierPendant) {
            delete i;

            setState(BossState::Type::Friendly);
            return true;
        }
    }

    return false;
}

void SoldierBoss::update() {
    if (state->type == BossState::Type::Friendly)
        return;

    if (health > 70)
        setState(BossState::Type::Hostile);
    else if (health > 0)
        setState(BossState::Type::Vengeful);
    else
        setState(BossState::Type::Dead);
}

void SoldierBoss::buff(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    c->setStrength(c->getStrength() + 5);
    c->setDefense(c->getDefense() + 5);
}
