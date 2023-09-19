#include <iostream>

#include "BossState.h"
#include "DragonBoss.h"
#include "Item.h"

DragonBoss::DragonBoss() {
    setName("Ghost Dragon");
    setState(BossState::Type::Hostile);
    setHealth(175);
    setStrength(15);
    setDefense(10);
}

bool DragonBoss::takeItem(Item* i) {
    if (i == nullptr)
        throw invalid_parameter_error("Item is a nullptr");

    bool accepted = state->takeItem(i);

    if (accepted) {
        Item::Identifier identifier = i->getIdentifier();

        if (identifier == Item::Identifier::DragonSword) {
            delete i;

            setState(BossState::Type::Friendly);
            return true;
        }
    }

    return false;
}

void DragonBoss::update() {
    if (state->type == BossState::Type::Friendly)
        return;

    if (health > 70)
        setState(BossState::Type::Hostile);
    else if (health > 0)
        setState(BossState::Type::Vengeful);
    else
        setState(BossState::Type::Dead);
}

void DragonBoss::buff(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    c->setStrength(c->getStrength() + 3);
    c->setDefense(c->getDefense() + 3);
}
