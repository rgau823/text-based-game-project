#include <iostream>
#include <string>

#include "Character.h"

std::string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getStrength() {
    return strength;
}

int Character::getDefense() {
    return defense + modifier;
}

int Character::getModifier() {
    return modifier;
}

int Character::getDamage() {
    return strength * modifier;
}

unsigned int Character::getPosition() {
    return position;
}

void Character::setName(std::string n) {
    name = n;
}

void Character::setHealth(int h) {
    health = h;
}

void Character::setStrength(int s) {
    if (s < 0) s *= -1;
    strength = s;
}

void Character::setDefense(int d) {
    defense = d;
}

void Character::setModifier(int m) {
    modifier = m;
}

void Character::setPosition(unsigned int p) {
    position = p;
}

void Character::takeDamage(int d) {
    health = health - d;
}

bool Character::isDead() {
    if (health == 0) return true;
    return false;
}
