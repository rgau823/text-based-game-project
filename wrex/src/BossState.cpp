#include <iostream>
#include <string>

#include "Boss.h"
#include "BossState.h"
#include "Character.h"
#include "Dialog.h"
#include "Item.h"

VengefulState::VengefulState() : BossState(Type::Vengeful) {
    if (dialoger) delete dialoger;
    dialoger = new VengefulDialoger();
}

bool VengefulState::attack(Character *c) {
    return true;
}

void VengefulState::transmogrify(Character* c) {
    c->setModifier(3);
}

bool VengefulState::takeItem(Item* i) {
    return false;
}

void VengefulState::response() {
    dialog->response(dialoger);
}

void VengefulState::getDescription() {
    std::cout << "The boss is vengeful." << std::endl;
}

void VengefulState::printState() {
    std::cout << "Vengeful" << std::endl;
}

HostileState::HostileState() : BossState(Type::Hostile) {
    if (dialoger) delete dialoger;
    dialoger = new HostileDialoger();
}

bool HostileState::attack(Character *c) {
    return getRandomBoolean(0.75);
}

void HostileState::transmogrify(Character* c) {
    c->setModifier(2);
}

bool HostileState::takeItem(Item* i) {
    return true;
}

void HostileState::response() {
    dialog->response(dialoger);
}

void HostileState::getDescription() {
    std::cout << "The boss is hostile." << std::endl;
}

void HostileState::printState() {
    std::cout << "Hostile" << std::endl;
}


FriendlyState::FriendlyState() : BossState(Type::Friendly) {
    if (dialoger) delete dialoger;
    dialoger = new FriendlyDialoger();
}

bool FriendlyState::attack(Character *c) {
    return false;
}

void FriendlyState::transmogrify(Character* c) {
    c->setModifier(1);
}

bool FriendlyState::takeItem(Item* i) {
    return true;
}

void FriendlyState::response() {
    dialog->response(dialoger);
}

void FriendlyState::getDescription() {
    std::cout << "The boss is friendly." << std::endl;
}

void FriendlyState::printState() {
    std::cout << "Friendly" << std::endl;
}


DeadState::DeadState() : BossState(Type::Dead) {
    if (dialoger) delete dialoger;
    dialoger = new DeadDialoger();
}

bool DeadState::attack(Character *c) {
    return false;
}

void DeadState::transmogrify(Character* c) {
    c->setModifier(0);
}

bool DeadState::takeItem(Item* i) {
    return false;
}

void DeadState::response() {
    dialog->response(dialoger);
}

void DeadState::getDescription() {
    std::cout << "The boss is dead." << std::endl;
}

void DeadState::printState() {
    std::cout << "Dead" << std::endl;
}
