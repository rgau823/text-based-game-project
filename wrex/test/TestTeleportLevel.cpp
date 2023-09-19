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
#include "BossState.h"
#include "DogBoss.h"
#include "TeleportLevel.h"

TEST(TestTeleportLevel, testDefaultConstructor) {
    TeleportLevel* level = new TeleportLevel();

    EXPECT_EQ(level->getIdentifier(), 0);
    EXPECT_EQ(level->getName(), "Teleport Level");

    delete level;
}

TEST(TestTeleportLevel, testInteract) {
    TeleportLevel* level = new TeleportLevel();

    EXPECT_NO_THROW(level->interact());

    delete level;
}

TEST(TestTeleportLevel, testIsClearedKilled) {
    TeleportLevel* level = new TeleportLevel();
    DogBoss* boss = new DogBoss();

    level->addEnemy(boss);

    EXPECT_FALSE(level->isCleared());

    std::vector<Enemy*> enemies = level->getEnemies();

    for (auto& enemy : enemies)
        enemy->setHealth(0);

    EXPECT_TRUE(level->isCleared());

    delete level;
}

TEST(TestTeleportLevel, testIsClearedFriendly) {
    TeleportLevel* level = new TeleportLevel();
    DogBoss* boss = new DogBoss();

    level->addEnemy(boss);

    EXPECT_FALSE(level->isCleared());

    boss->setState(BossState::Type::Friendly);

    EXPECT_TRUE(level->isCleared());

    delete level;
}
