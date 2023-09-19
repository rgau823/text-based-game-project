#include <iostream>
#include <string>

#include "Character.h"
#include "Enemy.h"
#include "NPC.h"
#include "RandomNumberGenerator.h"

Enemy::Enemy() : NPC() {
    setName("Enemy");
    setDescription("A generic enemy");
}

Enemy::Enemy(std::string n) : NPC(n) {
    setDescription("A generic enemy");
}

bool Enemy::attack(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    bool success = getRandomBoolean(0.30);
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

void Enemy::transmogrify(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    c->setStrength(c->getStrength() + 1);
    c->setDefense(c->getDefense() + 1);
}

void Enemy::getDescription() {
    std::cout << description << std::endl;
}

void Enemy::response() {
    std::cout << "Grrr, I'm a " << name << std::endl;
}

bool Enemy::takeItem(Item* i) {
    if (i == nullptr)
        throw invalid_parameter_error("Item is a nullptr");

    std::cout << "The enemy does not seem interested in an item" << std::endl;
    return false;
}

void Enemy::update() {
    if (health > 90) {
        setStrength(14);
        setDefense(6);
    } else if (health > 50) {
        setStrength(12);
        setDefense(4);
    } else {
        setStrength(10);
        setDefense(2);
    }
}

void Enemy::buff(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    c->setStrength(c->getStrength() + 1);
    c->setDefense(c->getDefense() + 1);
}

bool Enemy::isFriendly() {
    return false;
}
