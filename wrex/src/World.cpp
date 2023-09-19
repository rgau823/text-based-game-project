#include <iomanip>
#include <iostream>
#include <vector>

#include "World.h"

World::World() {
    for (int i = 0; i < 4; i++) {
        Stage* stage = new Stage(i);
        stage->setIdentifier(i);
        stage->shuffleStage();
        stage->labelStage();

        addStage(stage);
    }
}

World::~World() {
    for (auto& stage : stages)
        delete stage;
}

std::vector<Stage*> World::getStages() {
    return stages;
}

void World::addStage(Stage* s) {
    if (s == nullptr)
        throw invalid_parameter_error("Stage is a nullptr");

    int size = stages.size();

    if (size >= limit) {
        std::cout << "World can't have more than " << limit << " stages!\n";
        return;
    }

    stages.push_back(s);
}

void World::displayWorld() {
    std::cout << "World" << std::endl;

    for (auto& stage : stages)
        stage->showStage();
}

void World::showStage(int i) {
    stages[i]->showStage();
}
