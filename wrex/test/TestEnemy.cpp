/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include "gtest/gtest.h"
#include "Enemy.h"
#include "Exorcist.h"
#include "RedPotion.h"

TEST(TestEnemy, testDefaultConstructor) {
    Enemy* enemy = new Enemy();
    EXPECT_EQ(enemy->getName(), "Enemy");

    delete enemy;
}

TEST(TestEnemy, testConstructor) {
    Enemy* enemy = new Enemy("Henchman");
    EXPECT_EQ(enemy->getName(), "Henchman");

    delete enemy;
}

TEST(TestEnemy, testSetGetName) {
    Enemy* enemy = new Enemy("Enemy");

    enemy->setName("Henchman");
    EXPECT_EQ(enemy->getName(), "Henchman");

    delete enemy;
}

TEST(TestEnemy, testSetGetHealth) {
    Enemy* enemy = new Enemy("Enemy");

    enemy->setHealth(500);
    EXPECT_EQ(enemy->getHealth(), 500);

    delete enemy;
}

TEST(TestEnemy, testSetGetStrength) {
    Enemy* enemy = new Enemy("Enemy");

    enemy->setStrength(100);
    EXPECT_EQ(enemy->getStrength(), 100);

    delete enemy;
}

TEST(TestEnemy, testSetGetModifiedDefense) {
    Enemy* enemy = new Enemy("Enemy");

    enemy->setDefense(100);
    EXPECT_EQ(enemy->getDefense(), 101);

    delete enemy;
}

TEST(TestEnemy, testSetGetModifier) {
    Enemy* enemy = new Enemy("Enemy");

    enemy->setModifier(100);
    EXPECT_EQ(enemy->getModifier(), 100);

    delete enemy;
}

TEST(TestEnemy, testSetGetPosition) {
    Enemy* enemy = new Enemy("Enemy");

    enemy->setPosition(5);
    EXPECT_EQ(enemy->getPosition(), 5);

    delete enemy;
}

TEST(TestEnemy, testGetDescription) {
    Enemy* enemy = new Enemy("Enemy");

    enemy->getDescription();
    EXPECT_NO_THROW(enemy->getDescription());

    delete enemy;
}

TEST(TestEnemy, testTakeDamage) {
    Enemy* enemy = new Enemy("Enemy");

    EXPECT_EQ(enemy->getHealth(), 100);

    enemy->takeDamage(10);

    EXPECT_EQ(enemy->getHealth(), 90);

    delete enemy;
}

TEST(TestEnemy, testIsDead) {
    Enemy* enemy = new Enemy("Enemy");

    EXPECT_EQ(enemy->getHealth(), 100);
    EXPECT_FALSE(enemy->isDead());

    enemy->setHealth(1);
    EXPECT_FALSE(enemy->isDead());

    enemy->setHealth(0);
    EXPECT_TRUE(enemy->isDead());

    delete enemy;
}

TEST(TestEnemy, testAttack) {
    Enemy* enemy = new Enemy("Enemy");
    Exorcist* exorcist = new Exorcist("Exorcist");

    enemy->attack(exorcist);
    EXPECT_NEAR(exorcist->getHealth(), 100, 10);

    delete enemy;
    delete exorcist;
}

TEST(TestEnemy, testSuccessfulAttack) {
    Enemy* enemy = new Enemy("Enemy");
    Exorcist* exorcist = new Exorcist("Exorcist");

    while (true) {
        bool success = enemy->attack(exorcist);
        if (success) break;
    }

    EXPECT_NEAR(exorcist->getHealth(), 100, 10);

    delete enemy;
    delete exorcist;
}

TEST(TestEnemy, testMaximumAttack) {
    Enemy* enemy = new Enemy("Enemy");
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setHealth(0);

    while (true) {
        bool success = enemy->attack(exorcist);
        if (success) break;
    }

    EXPECT_EQ(exorcist->getHealth(), 0);

    delete enemy;
    delete exorcist;
}

TEST(TestEnemy, testTransmogrify) {
    Enemy* enemy = new Enemy("Enemy");
    Exorcist* exorcist = new Exorcist("Exorcist");

    enemy->transmogrify(exorcist);

    EXPECT_EQ(exorcist->getStrength(), 6);
    EXPECT_EQ(exorcist->getDefense(), 12);

    delete enemy;
    delete exorcist;
}

TEST(TestEnemy, testTakeItem) {
    Enemy* enemy = new Enemy("Enemy");
    RedPotion* potion = new RedPotion();

    EXPECT_FALSE(enemy->takeItem(potion));

    delete potion;
    delete enemy;
}

TEST(TestEnemy, testUpdate) {
    Enemy* enemy = new Enemy();

    enemy->setHealth(1000);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 14);
    EXPECT_EQ(enemy->getDefense(), 7);

    enemy->setHealth(100);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 14);
    EXPECT_EQ(enemy->getDefense(), 7);

    enemy->setHealth(91);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 14);
    EXPECT_EQ(enemy->getDefense(), 7);

    enemy->setHealth(90);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 12);
    EXPECT_EQ(enemy->getDefense(), 5);

    enemy->setHealth(70);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 12);
    EXPECT_EQ(enemy->getDefense(), 5);

    enemy->setHealth(51);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 12);
    EXPECT_EQ(enemy->getDefense(), 5);

    enemy->setHealth(50);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 10);
    EXPECT_EQ(enemy->getDefense(), 3);

    enemy->setHealth(25);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 10);
    EXPECT_EQ(enemy->getDefense(), 3);

    enemy->setHealth(0);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 10);
    EXPECT_EQ(enemy->getDefense(), 3);

    enemy->setHealth(-100);
    enemy->update();
    EXPECT_EQ(enemy->getStrength(), 10);
    EXPECT_EQ(enemy->getDefense(), 3);

    delete enemy;
}

TEST(TestEnemy, testBuff) {
    Exorcist* exorcist = new Exorcist();
    Enemy* enemy = new Enemy("Enemy");

    EXPECT_EQ(exorcist->getStrength(), 20);
    EXPECT_EQ(exorcist->getDefense(), 18);

    enemy->buff(exorcist);

    EXPECT_EQ(exorcist->getStrength(), 21);
    EXPECT_EQ(exorcist->getDefense(), 22);

    delete exorcist;
    delete enemy;
}

TEST(TestEnemy, isFriendly) {
    Enemy* enemy = new Enemy("Enemy");

    EXPECT_FALSE(enemy->isFriendly());

    delete enemy;
}

TEST(TestEnemy, testInvalidAttack) {
    Enemy* enemy = new Enemy("Enemy");

    EXPECT_THROW(enemy->attack(nullptr), invalid_parameter_error);

    delete enemy;
}

TEST(TestEnemy, testInvalidTransmogrify) {
    Enemy* enemy = new Enemy("Enemy");

    EXPECT_THROW(enemy->transmogrify(nullptr), invalid_parameter_error);

    delete enemy;
}

TEST(TestEnemy, testInvalidTakeItem) {
    Enemy* enemy = new Enemy("Enemy");

    EXPECT_THROW(enemy->takeItem(nullptr), invalid_parameter_error);

    delete enemy;
}

TEST(TestEnemy, testInvalidBuff) {
    Enemy* enemy = new Enemy("Enemy");

    EXPECT_THROW(enemy->buff(nullptr), invalid_parameter_error);

    delete enemy;
}
