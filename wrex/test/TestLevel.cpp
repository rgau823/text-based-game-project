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
#include "DogCollar.h"
#include "Exorcist.h"
#include "NormalLevel.h"
#include "RedPotion.h"

TEST(TestLevel, testDefaultConstructor) {
    Level* level = new NormalLevel();

    EXPECT_EQ(level->getName(), "Normal Level");

    delete level;
}

TEST(TestLevel, testSetGetIdentifier) {
    Level* level = new NormalLevel();

    level->setIdentifier(20);

    EXPECT_EQ(level->getIdentifier(), 20);

    delete level;
}

TEST(TestLevel, testSetGetDescription) {
    Level* level = new NormalLevel();

    level->setDescription("Custom Level");

    EXPECT_EQ(level->getDescription(), "Custom Level");

    delete level;
}

TEST(TestLevel, testSetGetName) {
    Level* level = new NormalLevel();

    level->setName("Custom Level");

    EXPECT_EQ(level->getName(), "Custom Level");

    delete level;
}

TEST(TestLevel, testSetGetType) {
    Level* level = new NormalLevel();

    level->setType(Level::Type::Teleport);

    EXPECT_EQ(level->getType(), Level::Type::Teleport);

    delete level;
}

TEST(TestLevel, testGetExorcist) {
    Exorcist* exorcist = new Exorcist();
    Level* level = new NormalLevel();

    level->addExorcist(exorcist);

    EXPECT_EQ(level->getExorcist(), exorcist);

    delete exorcist;
    delete level;
}

TEST(TestLevel, testGetItems) {
    Level* level = new NormalLevel();

    std::vector<Item*> item = level->getItems();

    EXPECT_EQ(item.size(), 0);

    delete level;
}

TEST(TestLevel, testGetEnemies) {
    Level* level = new NormalLevel();

    std::vector<Enemy*> enemies = level->getEnemies();

    EXPECT_NEAR(enemies.size(), 0, 4);

    delete level;
}

TEST(TestLevel, testAddRemoveExorcist) {
    Exorcist* exorcist = new Exorcist();
    Level* level = new NormalLevel();

    EXPECT_NO_THROW(level->addExorcist(exorcist));
    EXPECT_NO_THROW(level->removeExorcist());

    delete exorcist;
    delete level;
}

TEST(TestLevel, testAddEnemy) {
    Level* level = new NormalLevel();

    Enemy* enemy = new Enemy();

    level->addEnemy(enemy);

    // Characters are dynamically added to the level
    EXPECT_NEAR(level->getEnemies().size(), 1, 3);

    delete level;
}

TEST(TestLevel, testRemoveEnemy) {
    Level* level = new NormalLevel();

    Enemy* enemy = new Enemy();
    level->addEnemy(enemy);

    // Characters are dynamically added to the level
    EXPECT_NEAR(level->getEnemies().size(), 1, 3);

    level->removeEnemy(enemy);

    // Characters are dynamically added to the level
    EXPECT_NEAR(level->getEnemies().size(), 0, 3);

    delete enemy;
    delete level;
}

TEST(TestLevel, testAddItem) {
    Level* level = new NormalLevel();
    DogCollar* collar = new DogCollar();

    level->addItem(collar);

    EXPECT_EQ(level->getItems().size(), 1);

    delete level;
}

TEST(TestLevel, testRemoveItem) {
    Level* level = new NormalLevel();
    DogCollar* collar = new DogCollar();

    level->addItem(collar);
    level->removeItem(collar);

    EXPECT_EQ(level->getItems().size(), 0);

    delete collar;
    delete level;
}

TEST(TestLevel, testInteract) {
    Level* level = new NormalLevel();

    EXPECT_NO_THROW(level->interact());

    delete level;
}

TEST(TestLevel, testShow) {
    Level* level = new NormalLevel();

    EXPECT_NO_THROW(level->showItems());
    EXPECT_NO_THROW(level->showCharacters());
    EXPECT_NO_THROW(level->showStatus());
    EXPECT_NO_THROW(level->showLevel());
    EXPECT_NO_THROW(level->examine());

    Exorcist* exorcist = new Exorcist();
    Enemy* enemy = new Enemy();
    RedPotion* potion = new RedPotion();

    level->addExorcist(exorcist);
    level->addEnemy(enemy);
    level->addItem(potion);

    EXPECT_NO_THROW(level->showItems());
    EXPECT_NO_THROW(level->showCharacters());

    delete exorcist;
    delete level;
}

TEST(TestLevel, testInvalidAddEnemy) {
    Level* level = new NormalLevel();

    EXPECT_THROW(level->addEnemy(nullptr), invalid_parameter_error);

    delete level;
}

TEST(TestLevel, testInvalidRemoveEnemy) {
    Level* level = new NormalLevel();

    EXPECT_THROW(level->removeEnemy(nullptr), invalid_parameter_error);

    delete level;
}

TEST(TestLevel, testInvalidAddItem) {
    Level* level = new NormalLevel();

    EXPECT_THROW(level->addItem(nullptr), invalid_parameter_error);

    delete level;
}

TEST(TestLevel, testInvalidRemoveItem) {
    Level* level = new NormalLevel();

    EXPECT_THROW(level->removeItem(nullptr), invalid_parameter_error);

    delete level;
}

