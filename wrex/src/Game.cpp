#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Art.h"
#include "Battle.h"
#include "EndingPath.h"
#include "Enemy.h"
#include "ExorcistState.h"
#include "Game.h"
#include "RandomNumberGenerator.h"
#include "RedPotion.h"

Game::Game() {
    world = new World();
    exorcist = new Exorcist();

    std::vector<Stage*> stages = world->getStages();
    std::vector<Level*> levels = stages[0]->getLevels();

    levels[0]->addExorcist(exorcist);
}

Game::~Game() {
    if (exorcist) delete exorcist;
    if (world) delete world;
}

void Game::introduction() {
    art.logo();
    art.dinosaur();
    art.introduction();
    art.stage(0);
}

void Game::play() {
    isRunning = true;

    while (isRunning) {
        Stage* stage = getCharacterStage(exorcist);
        Level* level = getCharacterLevel(exorcist);
        Level::Type type = level->getType();
        int id = stage->getIdentifier();
        world->showStage(id);

        if (stage->isCleared() && world->getStages().size() > id &&
            type == Level::Type::Teleport)
            ui.showStageCommands();

        int input = 0;
        input = ui.normalInput();

        switch (input) {
            case QUIT:
                isRunning = false;
                return;

            case FIGHT:
                getCharacterLevel(exorcist)->createBattle();
                break;

            case NEXT_LEVEL:
                moveCharacter(exorcist, exorcist->getPosition() + 1);
                break;

            case PREVIOUS_LEVEL:
                moveCharacter(exorcist, exorcist->getPosition() - 1);
                break;

            case INTERACT:
                getCharacterLevel(exorcist)->interact();
                break;

            case BACKPACK:
                exorcist->viewBackpack();
                break;

            case TALK: {
                std::vector<Enemy*> enemies = level->getEnemies();
                int size = enemies.size();
                if (size == 0) break;

                input = ui.numberCommand(size);

                if (input == CANCEL) break;
                if (input == QUIT) return;

                exorcist->talk(enemies[input]);

                break;
            }

            case EXAMINE: {
                std::vector<Item*> items = level->getItems();
                int size = items.size();
                if (size == 0) break;

                level->showItems();
                input = ui.numberCommand(size);

                if (input == CANCEL) break;

                Item* item = items[input];
                item->examine();

                break;
            }

            case TAKE: {
                std::vector<Item*> items = level->getItems();
                int size = items.size();
                if (size == 0) break;

                level->showItems();
                input = ui.numberCommand(size);

                if (input == CANCEL) break;

                Item* item = items[input];

                exorcist->takeItem(item);
                level->removeItem(item);

                break;
            }

            case DROP: {
                int size = exorcist->getBackpack().size();
                if (size == 0) break;

                exorcist->viewBackpack();
                input = ui.numberCommand(size);

                if (input == CANCEL) break;

                Item* item = exorcist->dropItem(input);
                level->addItem(item);

                break;
            }

            case USE: {
                int size = exorcist->getBackpack().size();
                if (size == 0) break;

                exorcist->viewBackpack();
                input = ui.numberCommand(size);

                if (input == CANCEL) break;

                exorcist->useItem(input);

                break;
            }

            case STAGE: {
                bool clear = stage->isCleared();
                if (clear && type == Level::Type::Teleport) {
                    if (stage->getIdentifier() == 3) {
                        isRunning = false;
                        ending();
                        break;
                    }
                    moveCharacter(exorcist, (id * 10) + 10);
                    art.stage(id + 1);
                }

                break;
            }
        }

        bool dead = exorcist->isDead();

        if (dead) {
            isRunning = false;
            break;
        }
    }
}

void Game::stop() {
    isRunning = false;
    art.gameover();
}

Exorcist* Game::getExorcist() {
    return exorcist;
}

Stage* Game::getCharacterStage(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    std::vector<Stage*> stages = world->getStages();
    int position = c->getPosition() / 10;

    return stages[position];
}

Level* Game::getCharacterLevel(Character* c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    Stage* stage = getCharacterStage(c);
    std::vector<Level*> levels = stage->getLevels();
    int position = c->getPosition() % 10;

    return levels[position];
}

void Game::moveCharacter(Character* c, unsigned int p) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    int si = p / 10;
    int li = p % 10;

    std::vector<Stage*> stages = world->getStages();
    std::vector<Level*> levels = stages[0]->getLevels();

    if (si > stages.size() || li > levels.size() - 1) {
        std::string name = c->getName();
        std::cout << '\n';
        std::cout << name << " can't move outside of the world." << std::endl;

        return;
    }

    Level* previous = getCharacterLevel(c);
    previous->removeExorcist();

    c->setPosition(p);

    Level* next = getCharacterLevel(c);
    next->addExorcist(exorcist);
}

void Game::ending() {
    if (EndingPath::getSaved() == 4)
        art.trueEnding();
    else if (EndingPath::getSaved() > 0)
        art.neutralEnding();
    else
        art.badEnding();
}
