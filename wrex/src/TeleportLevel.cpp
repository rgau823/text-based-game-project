#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Boss.h"
#include "TeleportLevel.h"

TeleportLevel::TeleportLevel() {
    Level::setName("Teleport Level");
    Level::setType(Level::Teleport);
}

bool TeleportLevel::isCleared() {
    std::vector<Enemy*> bosses = Level::getEnemies();

    int health = 0;

    for (auto& boss : bosses) {
        bool friendly = boss->isFriendly();
        if (friendly) return true;

        health = health + boss->getHealth();
    }

    if (health > 0) return false;
    return true;
}

void TeleportLevel::interact() {
    std::cout << "There is a boss in shrouded in the darkness" << std::endl;
}
