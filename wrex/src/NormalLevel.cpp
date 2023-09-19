#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "EnemyFactory.h"
#include "NormalLevel.h"
#include "RandomNumberGenerator.h"

NormalLevel::NormalLevel() {
    Level::setName("Normal Level");
    Level::setType(Level::Normal);

    for (int i = 0; i < limit; i++) {
        bool chance = getRandomBoolean(0.50);

        if (chance) {
            EnemyFactory factory;
            Enemy* enemy = factory.createEnemy();
            addEnemy(enemy);
        }
    }
}

bool NormalLevel::isCleared() {
    std::vector<Enemy*> enemies = Level::getEnemies();

    int health = 0;

    for (Enemy* enemy : enemies)
        health = health + enemy->getHealth();

    if (health > 0) return false;
    return true;
}


void NormalLevel::interact() {
    const std::string message =
    "You feel around the room, "
    "but find nothing of interest.";

    std::cout << message << std::endl;
}
