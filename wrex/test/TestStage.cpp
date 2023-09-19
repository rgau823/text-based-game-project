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
#include "NormalLevel.h"
#include "Stage.h"

TEST(TestStage, testConstructor) {
    Stage* stage = new Stage(0);

    std::vector<Level*> level = stage->getLevels();

    EXPECT_EQ(level.size(), 4);

    delete stage;
}

TEST(TestStage, testSetGetIdentifier) {
    Stage* stage = new Stage();
    stage->setIdentifier(10);

    EXPECT_EQ(stage->getIdentifier(), 10);

    delete stage;
}

TEST(TestStage, testAddGetLevels) {
    Stage* stage = new Stage(0);

    Level* level1 = new NormalLevel();
    Level* level2 = new NormalLevel();

    stage->addLevel(level1);
    stage->addLevel(level2);

    EXPECT_EQ(stage->getLevels().size(), 6);

    delete stage;
}

TEST(TestStage, testLabelStage) {
    Stage* stage = new Stage(0);

    stage->labelStage();

    std::vector<Level*> levels = stage->getLevels();

    for (int i = 0; i < levels.size(); i++)
        EXPECT_EQ(levels[i]->getIdentifier(), i);

    delete stage;
}

TEST(TestStage, testIsCleared) {
    Stage* stage = new Stage(0);

    EXPECT_FALSE(stage->isCleared());

    delete stage;
}

TEST(TestStage, testMaximumAddLevel) {
    Stage* stage = new Stage(0);

    for (int i = 0; i < 6; i++) {
        Level* level = new NormalLevel();
        stage->addLevel(level);

        if (i == 5) delete level;
    }

    delete stage;
}

TEST(TestStage, testShowStage) {
    Stage* stage = new Stage(0);

    EXPECT_NO_THROW(stage->showStage());

    delete stage;
}

TEST(TestStage, testInvalidAddLevel) {
    Stage* stage = new Stage(0);

    EXPECT_THROW(stage->addLevel(nullptr), invalid_parameter_error);

    EXPECT_EQ(stage->getLevels().size(), 4);

    delete stage;
}
