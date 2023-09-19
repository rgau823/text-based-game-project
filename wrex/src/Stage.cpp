#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "NormalLevel.h"
#include "PuzzleFactory.h"
#include "PuzzleLevel.h"
#include "RandomNumberGenerator.h"
#include "Stage.h"
#include "TeleportFactory.h"
#include "TeleportLevel.h"

Stage::Stage(unsigned int i) {
    setIdentifier(i);

    Level* n1 = new NormalLevel();
    Level* n2 = new NormalLevel();
    addLevel(n1);
    addLevel(n2);

    TeleportFactory tf;
    TeleportLevel* tl = tf.createTeleportLevel(i);
    addLevel(tl);

    PuzzleFactory pf;
    PuzzleLevel* pl = pf.createPuzzleLevel(i);
    addLevel(pl);
}

Stage::~Stage() {
    for (auto& level : levels)
        delete level;
}

unsigned int Stage::getIdentifier() {
    return id;
}

std::vector<Level*> Stage::getLevels() {
    return levels;
}

void Stage::addLevel(Level* l) {
    if (l == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    if (levels.size() >= limit) {
        std::cout << "World can't have more than " << limit << " stages!\n";
        return;
    }

    levels.push_back(l);
}

void Stage::setIdentifier(unsigned int i) {
    id = i;
}

bool Stage::isCleared() {
    for (auto level : levels) {
        bool cleared = level->isCleared();

        if (!cleared) return false;
    }

    return true;
}

void Stage::labelStage() {
    for (int i = 0; i < levels.size(); i++)
        levels[i]->setIdentifier(i);
}

void Stage::shuffleStage() {
    std::mt19937& mt = RandomNumberGenerator::getInstance().getEngine();
    shuffle(levels.begin(), levels.end(), mt);
}

void Stage::showStage() {
    std::cout << '\n';
    std::cout << '[' << id + 1 << ": " << "Stage" << ']' << std::endl;
    std::cout << '\n';

    for (auto& level : levels) {
        level->showLevel();
        std::cout << std::endl;
    }
}
