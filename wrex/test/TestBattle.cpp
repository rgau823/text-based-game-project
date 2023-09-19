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
#include "Battle.h"
#include "Enemy.h"
#include "Exorcist.h"

TEST(TestBattle, testDefaultConstructor) {
    Exorcist* exorcist = new Exorcist();

    std::vector<Enemy*> enemies;

    Enemy* enemy1 = new Enemy();
    Enemy* enemy2 = new Enemy();
    enemies.push_back(enemy1);
    enemies.push_back(enemy2);

    Battle* battle = new Battle(exorcist, enemies);
    EXPECT_NO_THROW(battle);

    delete battle;
    delete exorcist;
    delete enemy1;
    delete enemy2;
}

TEST(TestBattle, testInvalidConstructor) {
    Exorcist* exorcist = new Exorcist();
    std::vector<Enemy*> enemies;

    EXPECT_THROW(new Battle(nullptr, enemies), invalid_parameter_error);

    delete exorcist;
}

TEST(TestBattle, testIsComplete) {
    Exorcist* exorcist = new Exorcist();

    std::vector<Enemy*> enemies;

    Enemy* enemy1 = new Enemy();
    Enemy* enemy2 = new Enemy();
    enemies.push_back(enemy1);
    enemies.push_back(enemy2);

    Battle* battle = new Battle(exorcist, enemies);

    EXPECT_FALSE(battle->isComplete());

    exorcist->setHealth(0);

    EXPECT_TRUE(battle->isComplete());

    exorcist->setHealth(100);

    for (auto& enemy : enemies)
        enemy->setHealth(0);

    EXPECT_TRUE(battle->isComplete());

    delete battle;
    delete exorcist;
    delete enemy1;
    delete enemy2;
}

TEST(TestBattle, testBuff) {
    Exorcist* exorcist = new Exorcist();

    EXPECT_EQ(exorcist->getStrength(), 20);
    EXPECT_EQ(exorcist->getDefense(), 18);

    std::vector<Enemy*> enemies;

    Enemy* enemy1 = new Enemy();
    Enemy* enemy2 = new Enemy();
    enemies.push_back(enemy1);
    enemies.push_back(enemy2);

    Battle* battle = new Battle(exorcist, enemies);

    for (auto& enemy : enemies)
        enemy->setHealth(0);

    EXPECT_TRUE(battle->isComplete());
    EXPECT_EQ(exorcist->getStrength(), 22);
    EXPECT_EQ(exorcist->getDefense(), 26);

    delete battle;
    delete exorcist;
    delete enemy1;
    delete enemy2;
}

TEST(TestBattle, testViewBattle) {
    Exorcist* exorcist = new Exorcist();

    std::vector<Enemy*> enemies;

    Enemy* enemy1 = new Enemy();
    Enemy* enemy2 = new Enemy();
    enemies.push_back(enemy1);
    enemies.push_back(enemy2);

    Battle* battle = new Battle(exorcist, enemies);

    EXPECT_NO_THROW(battle->viewBattle());

    delete battle;
    delete exorcist;
    delete enemy1;
    delete enemy2;
}
