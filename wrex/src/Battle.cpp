#include <iostream>
#include <string>
#include <vector>

#include "Battle.h"
#include "RandomNumberGenerator.h"
#include "RedPotion.h"
#include "EndingPath.h"

Battle::Battle(Exorcist* ex, std::vector<Enemy*> en) {
    if (ex == nullptr)
        throw invalid_parameter_error("Invalid parameter");

    exorcist = ex;
    enemies = en;
}

bool Battle::isComplete() {
    bool dead = exorcist->isDead();
    if (dead) return dead;

    for (auto& enemy : enemies) {
        bool friendly = enemy->isFriendly();
        if (friendly) return true;

        bool dead = enemy->isDead();
        if (!dead) return false;
    }

    reward();
    return true;
}

void Battle::reward() {
    for (auto& enemy : enemies) {
        enemy->buff(exorcist);

        bool rng = getRandomBoolean(0.50);
        if (!rng) continue;

        exorcist->takeItem(new RedPotion);
    }
}

void Battle::start() {
    if (enemies.size() == 0) {
        std::cout << '\n' << "No enemies here." << std::endl;
        return;
    }

    std::cout << '\n' << "=== [Battle] ===" << std::endl;

    do {
        exorcist->update();

        bool complete = isComplete();
        if (complete) return;

        viewBattle();
        int input = 0;

        // Player's turn
        input = ui.battleInput();

        switch (input) {
            case ATTACK: {
                int size = enemies.size();
                input = ui.numberCommand(size);

                if (input == CANCEL) continue;

                bool success = exorcist->attack(enemies[input]);

                if (!success) {
                    std::cout << exorcist->getName() << "\'s ";
                    std::cout << "attack missed." << std::endl;
                }

                break;
            }

            case FLEE: {
                bool attempt = exorcist->flee();

                if (attempt) return;
                std::cout << "Flee failed!" << std::endl;

                break;
            }

            case GIFT: {
                int input2 = 0;
                int size = exorcist->getBackpack().size();

                if (size == 0) break;

                exorcist->viewBackpack();

                std::cout << "Select an item to give : ";
                input = ui.numberCommand(size);

                if (input == CANCEL) continue;

                viewBattle();

                std::cout << "Select an enemy to gift : ";

                size = enemies.size();
                input2 = ui.numberCommand(size);

                if (input2 == CANCEL) continue;

                Enemy* enemy = enemies[input2];
                Item* item = exorcist->dropItem(input);

                bool success = enemy->takeItem(item);
                if (success) {
                    EndingPath::savedBoss();
                    continue;
                }

                break;
            }

            case INFO: {
                std::cout << "=== Enemies Information ===" << std::endl;

                for (int i = 0; i < enemies.size(); i++) {
                    std::string name = enemies[i]->getName();
                    double health = enemies[i]->getHealth();

                    std::cout << i + 1 << ": " << name;
                    std::cout << " - HP: " << health;

                    std::cout << std::endl;
                }

                continue;
            }

            case BACKPACK: {
                exorcist->viewBackpack();
                continue;
            }

            case QUIT: {
                return;
            }
        }

        // Enemies' turn
        for (auto& enemy : enemies) {
            enemy->update();

            bool dead = enemy->isDead();
            if (dead) continue;

            bool success = enemy->attack(exorcist);

            if (!success) {
                std::cout << enemy->getName() << "\'s ";
                std::cout << "attack missed." << std::endl;
            }
        }
    } while (true);
}

void Battle::viewBattle() {
    std::cout << '\n' << "=== Enemies ===" << std::endl;

    for (int i = 0; i < enemies.size(); i++) {
        std::string name = enemies[i]->getName();
        double health = enemies[i]->getHealth();

        std::cout << i + 1 << ": " << name;
        std::cout << " - HP: " << health << std::endl;
    }

    std::cout << "=== Exorcist ===" << std::endl;

    std::string name = exorcist->getName();
    double health = exorcist->getHealth();

    std::cout << "*: " << name;
    std::cout << " - HP: " << health << std::endl;

    std::cout << std::endl;
}
