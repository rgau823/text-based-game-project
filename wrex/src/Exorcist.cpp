#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Character.h"
#include "Enemy.h"
#include "Exorcist.h"
#include "ExorcistState.h"
#include "RedPotion.h"

Exorcist::Exorcist() {
    setName("Exorcist");
    setState(ExorcistState::Type::Sane);
    setStrength(20);
    setDefense(15);
    takeItem(new RedPotion);
}

Exorcist::Exorcist(std::string n) : Character(n) {
    setState(ExorcistState::Type::Sane);
}

Exorcist::~Exorcist() {
    if (state) delete state;

    for (auto item : backpack)
        delete item;
}

bool Exorcist::attack(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    int health = c->getHealth();
    if (health == 0) return false;

    bool success = state->attack(c);
    if (!success) return false;

    int damage = getDamage();

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

void Exorcist::transmogrify(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    state->transmogrify(this);
}

void Exorcist::talk(NPC* n) {
    if (n == nullptr)
        throw invalid_parameter_error("NPC is a nullptr");

    n->response();
}

bool Exorcist::takeItem(Item* i) {
    if (i == nullptr)
        throw invalid_parameter_error("Item is a nullptr");

    backpack.push_back(i);
    return true;
}

bool Exorcist::flee() {
    return state->flee();
}

void Exorcist::update() {
    if (health > 80)
        setState(ExorcistState::Type::Sane);
    else if (health > 40)
        setState(ExorcistState::Type::Injured);
    else
        setState(ExorcistState::Type::Possessed);
}

std::vector<Item*> Exorcist::getBackpack() {
    return backpack;
}

Item* Exorcist::getItem(unsigned int i) {
    int size = backpack.size();

    if (i >= size || size == 0)
        throw invalid_parameter_error("No item at that position.");

    return backpack[i];
}

ExorcistState* Exorcist::getState() {
    return state;
}

void Exorcist::setState(ExorcistState::Type type) {
    if (state && type == state->type) return;
    if (state) delete state;

    switch (type) {
        case ExorcistState::Type::Sane:
        default:
            state = new SaneState;
            break;
        case ExorcistState::Type::Injured:
            state = new InjuredState;
            break;
        case ExorcistState::Type::Possessed:
            state = new PossessedState;
            break;
    }

    transmogrify(this);
}

Item* Exorcist::dropItem(unsigned int i) {
    if (i >= backpack.size())
        throw invalid_parameter_error("Index is larger than the size of items");

    Item* item = backpack[i];

    backpack.erase(
        std::remove(backpack.begin(), backpack.end(), item),
        backpack.end());

    return item;
}

void Exorcist::useItem(unsigned int i) {
    if (i >= backpack.size())
        throw invalid_parameter_error("Index is larger than the size of items");

    Item* item = backpack[i];

    if (item->getType() == Item::Type::Core) return;

    item->use(this);

    backpack.erase(
        std::remove(backpack.begin(), backpack.end(), item),
        backpack.end());

    delete item;
}

void Exorcist::viewBackpack() {
    std::cout << "\n=== Exorcist's Backpack ===\n";

    if (backpack.size() == 0) return;

    for (int i = 0; i < backpack.size(); i++) {
        std::cout << i + 1 << ": ";
        std::cout << backpack[i]->name() << std::endl;
    }
}

void Exorcist::viewState() {
    state->printState();
}
