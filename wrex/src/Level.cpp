#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Level.h"
#include "PuzzleLevel.h"
#include "TeleportLevel.h"

Level::~Level() {
    for (auto& enemy : enemies)
        delete enemy;

    for (auto& item : items)
        delete item;
}

unsigned int Level::getIdentifier() {
    return id;
}

std::string Level::getName() {
    return name;
}

std::string Level::getDescription() {
    return description;
}

Level::Type Level::getType() {
    return type;
}

Exorcist* Level::getExorcist() {
    return exorcist;
}

std::vector<Enemy*> Level::getEnemies() {
    return enemies;
}

std::vector<Item*> Level::getItems() {
    return items;
}

void Level::setIdentifier(unsigned int i) {
    id = i;
}

void Level::setName(std::string n) {
    name = n;
}

void Level::setDescription(std::string d) {
    description = d;
}

void Level::setType(Level::Type t) {
    type = t;
}

void Level::addExorcist(Exorcist* e) {
    exorcist = e;
}

void Level::removeExorcist() {
    if (exorcist) exorcist = nullptr;
}

void Level::addEnemy(Enemy* e) {
    if (e == nullptr)
        throw invalid_parameter_error("Enemy is a nullptr");

    enemies.push_back(e);
}

void Level::removeEnemy(Enemy* e) {
    if (e == nullptr)
        throw invalid_parameter_error("Enemy is a nullptr");

    enemies.erase(
        std::remove(enemies.begin(), enemies.end(), e),
        enemies.end());
}

void Level::addItem(Item* i) {
    if (i == nullptr)
        throw invalid_parameter_error("Item is a nullptr");

    items.push_back(i);
}

void Level::removeItem(Item* i) {
    if (i == nullptr)
        throw invalid_parameter_error("Item is a nullptr");

    items.erase(
        std::remove(items.begin(), items.end(), i),
        items.end());
}

void Level::showItems() {
    if (items.size() > 0) {
        std::cout << "=== Item ===" << std::endl;

        for (int i = 0; i < items.size(); i++) {
            std::cout << i + 1 << ": ";
            std::cout << items[i]->name() << std::endl;
        }
    }
}

void Level::showCharacters() {
    if (enemies.size() > 0) {
        std::cout << "=== Enemies ===" << std::endl;

        for (int i = 0; i < enemies.size(); i++) {
            std::cout << i + 1 << ": " << enemies[i]->getName();
            std::cout << " - HP: " << enemies[i]->getHealth() << std::endl;
        }
    }

    if (exorcist) {
        std::cout << "=== Exorcist ===" << std::endl;
        std::cout << "*: " << exorcist->getName();
        std::cout << " - HP: " << exorcist->getHealth() << std::endl;
    }
}

void Level::showStatus() {
    bool cleared = isCleared();
    std::string status = "Status: ";

    if (cleared)
        status = status + "Cleared";
    else
        status = status + "In progress...";

    std::cout << status << std::endl;
}

void Level::showLevel() {
    std::string name = getName();
    unsigned int identifier = getIdentifier();

    std::cout << '[' << identifier + 1 << ": " << name << ']' << std::endl;
    showStatus();
    showItems();
    showCharacters();
}

void Level::examine() {
    std::cout << getDescription() << std::endl;
}

void Level::createBattle() {
    Battle* battle = new Battle(exorcist, enemies);
    battle->start();
    delete battle;
}
