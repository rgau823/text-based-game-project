/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 05, 2021
 */

#include <iostream>

#include "BossState.h"
#include "ShadowBoss.h"
#include "Item.h"

ShadowBoss::ShadowBoss() {
    setName("Shadow Exorcist");
    setState(BossState::Type::Hostile);

    setHealth(200);
    setStrength(20);
    setDefense(15);
}

bool ShadowBoss::takeItem(Item* i) {
    if (i == nullptr)
        throw invalid_parameter_error("Item is a nullptr");

    bool accepted = state->takeItem(i);

    if (accepted) {
        Item::Identifier identifier = i->getIdentifier();

        if (identifier == Item::Identifier::Torch) {
            delete i;

            setState(BossState::Type::Friendly);
            return true;
        }
    }

    return false;
}

void ShadowBoss::update() {
    if (state->type == BossState::Type::Friendly)
        return;

    if (health > 120)
        setState(BossState::Type::Hostile);
    else if (health > 0)
        setState(BossState::Type::Vengeful);
    else
        setState(BossState::Type::Dead);
}

void ShadowBoss::buff(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    c->setStrength(c->getStrength() + 5);
    c->setDefense(c->getDefense() + 5);
}
