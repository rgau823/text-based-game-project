/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include <vector>

#include "gtest/gtest.h"
#include "Stage.h"
#include "World.h"

TEST(TestWorld, testConstructor) {
    World* world = new World();

    std::vector<Stage*> stages = world->getStages();

    EXPECT_EQ(stages.size(), 4);

    delete world;
}

TEST(TestWorld, testGetStages) {
    World* world = new World();
    Stage* stage = new Stage();

    world->addStage(stage);

    int size = world->getStages().size();

    EXPECT_EQ(size, 5);

    delete world;
}

TEST(TestWorld, testAddStage) {
    World* world = new World();

    Stage* stage = new Stage();
    Stage* stage2 = new Stage();

    world->addStage(stage);
    world->addStage(stage2);

    int size = world->getStages().size();

    EXPECT_EQ(size, 6);

    delete world;
}

TEST(TestWorld, testDisplayWorld) {
    World* world = new World();

    EXPECT_NO_THROW(world->displayWorld());

    delete world;
}

TEST(TestWorld, testShowStage) {
    World* world = new World();

    EXPECT_NO_THROW(world->showStage(0));

    delete world;
}

TEST(TestWorld, testInvalidAddStage) {
    World* world = new World();
    EXPECT_THROW(world->addStage(nullptr), invalid_parameter_error);

    int size = world->getStages().size();
    EXPECT_EQ(size, 4);

    delete world;
}

TEST(TestStage, testMaximumAddStage) {
    World* world = new World();

    Stage* stage5 = new Stage();
    Stage* stage6 = new Stage();
    Stage* stage7 = new Stage();
    Stage* stage8 = new Stage();
    Stage* stage9 = new Stage();
    Stage* stage10 = new Stage();

    world->addStage(stage5);
    world->addStage(stage6);
    world->addStage(stage7);
    world->addStage(stage8);
    world->addStage(stage9);

    EXPECT_NO_THROW(world->addStage(stage10));

    delete stage10;
    delete world;
}
