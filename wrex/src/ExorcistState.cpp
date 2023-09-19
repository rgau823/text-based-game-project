#include <iostream>

#include "ExorcistState.h"
#include "RandomNumberGenerator.h"

SaneState::SaneState() : ExorcistState(Type::Sane) {}

bool SaneState::attack(Character *c) {
    return true;
}

void SaneState::transmogrify(Character *c) {
    c->setModifier(3);
}

bool SaneState::flee() {
    return getRandomBoolean(0.75);
}

void SaneState::printState() {
    std::cout << "Sane" << std::endl;
}


InjuredState::InjuredState() : ExorcistState(Type::Injured) {}

bool InjuredState::attack(Character *c) {
    return getRandomBoolean(0.75);
}

void InjuredState::transmogrify(Character *c) {
    c->setModifier(2);
}

bool InjuredState::flee() {
    return getRandomBoolean(0.75);
}

void InjuredState::printState() {
    std::cout << "Injured" << std::endl;
}


PossessedState::PossessedState() : ExorcistState(Type::Possessed) {}

bool PossessedState::attack(Character *c) {
    return getRandomBoolean(0.50);
}

void PossessedState::transmogrify(Character *c) {
    c->setModifier(1);
}

bool PossessedState::flee() {
    return getRandomBoolean(0.50);
}

void PossessedState::printState() {
    std::cout << "Possessed" << std::endl;
}
