/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include "gtest/gtest.h"
#include "BossState.h"
#include "DragonBoss.h"
#include "DragonSword.h"
#include "Exorcist.h"

TEST(TestDragonBoss, testConstructor) {
    DragonBoss* boss = new DragonBoss();

    EXPECT_EQ(boss->getName(), "Ghost Dragon");
    EXPECT_EQ(boss->getState()->type, BossState::Type::Hostile);
    EXPECT_EQ(boss->getHealth(), 175);
    EXPECT_EQ(boss->getStrength(), 15);
    EXPECT_EQ(boss->getDefense(), 12);
    EXPECT_EQ(boss->getModifier(), 2);

    delete boss;
}

TEST(TestDragonBoss, testAttack) {
    Exorcist* exorcist = new Exorcist();
    DragonBoss* boss = new DragonBoss();

    boss->setState(BossState::Type::Vengeful);

    exorcist->setHealth(100);
    EXPECT_TRUE(boss->attack(exorcist));

    boss->setState(BossState::Type::Friendly);

    EXPECT_FALSE(boss->attack(exorcist));

    boss->setState(BossState::Type::Dead);

    EXPECT_FALSE(boss->attack(exorcist));

    delete exorcist;
    delete boss;
}

TEST(TestDragonBoss, testMaximumAttack) {
    DragonBoss* boss = new DragonBoss();
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setHealth(0);

    while (true) {
        bool success = boss->attack(exorcist);
        if (success) break;
    }

    EXPECT_EQ(exorcist->getHealth(), 0);

    delete exorcist;
    delete boss;
}

TEST(TestDragonBoss, testTransmogrify) {
    DragonBoss* boss = new DragonBoss();

    boss->setState(BossState::Type::Vengeful);

    EXPECT_EQ(boss->getModifier(), 3);

    boss->setState(BossState::Type::Hostile);

    EXPECT_EQ(boss->getModifier(), 2);

    boss->setState(BossState::Type::Friendly);

    EXPECT_EQ(boss->getModifier(), 1);

    boss->setState(BossState::Type::Dead);

    EXPECT_EQ(boss->getModifier(), 0);

    delete boss;
}

TEST(TestDragonBoss, testTakeItem) {
    DragonBoss* boss = new DragonBoss();

    boss->setState(BossState::Type::Vengeful);

    DragonSword* sword1 = new DragonSword();
    EXPECT_FALSE(boss->takeItem(sword1));

    boss->setState(BossState::Type::Hostile);

    DragonSword* sword2 = new DragonSword();
    EXPECT_TRUE(boss->takeItem(sword2));

    boss->setState(BossState::Type::Friendly);

    DragonSword* sword3 = new DragonSword();
    EXPECT_TRUE(boss->takeItem(sword3));

    boss->setState(BossState::Type::Dead);

    DragonSword* sword4 = new DragonSword();
    EXPECT_FALSE(boss->takeItem(sword4));

    delete sword1;
    delete sword4;
    delete boss;
}

TEST(TestDragonBoss, testUpdate) {
    DragonBoss* boss = new DragonBoss();

    boss->setHealth(1000);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Hostile);

    boss->setHealth(100);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Hostile);

    boss->setHealth(85);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Hostile);

    boss->setHealth(71);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Hostile);

    boss->setHealth(70);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Vengeful);

    boss->setHealth(30);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Vengeful);

    boss->setHealth(1);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Vengeful);

    boss->setHealth(0);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Dead);

    boss->setHealth(-100);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Dead);

    delete boss;
}

TEST(TestDragonBoss, testFriendlyUpdate) {
    DragonBoss* boss = new DragonBoss();
    boss->setState(BossState::Type::Friendly);

    boss->setHealth(50);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Friendly);

    delete boss;
}

TEST(TestDragonBoss, testBuff) {
    Exorcist* exorcist = new Exorcist();
    DragonBoss* boss = new DragonBoss();

    EXPECT_EQ(exorcist->getStrength(), 20);
    EXPECT_EQ(exorcist->getDefense(), 18);

    boss->buff(exorcist);

    EXPECT_EQ(exorcist->getStrength(), 23);
    EXPECT_EQ(exorcist->getDefense(), 24);

    delete exorcist;
    delete boss;
}

TEST(TestDragonBoss, testPrintable) {
    DragonBoss* boss = new DragonBoss();

    boss->setState(BossState::Type::Vengeful);

    EXPECT_NO_THROW(boss->getState()->response());
    EXPECT_NO_THROW(boss->getState()->getDescription());
    EXPECT_NO_THROW(boss->getState()->printState());
    EXPECT_NO_THROW(boss->response());
    EXPECT_NO_THROW(boss->viewState());
    EXPECT_FALSE(boss->isFriendly());

    boss->setState(BossState::Type::Hostile);

    EXPECT_NO_THROW(boss->getState()->response());
    EXPECT_NO_THROW(boss->getState()->getDescription());
    EXPECT_NO_THROW(boss->getState()->printState());
    EXPECT_NO_THROW(boss->response());
    EXPECT_NO_THROW(boss->viewState());
    EXPECT_FALSE(boss->isFriendly());

    boss->setState(BossState::Type::Friendly);

    EXPECT_NO_THROW(boss->getState()->response());
    EXPECT_NO_THROW(boss->getState()->getDescription());
    EXPECT_NO_THROW(boss->getState()->printState());
    EXPECT_NO_THROW(boss->response());
    EXPECT_NO_THROW(boss->viewState());
    EXPECT_TRUE(boss->isFriendly());

    boss->setState(BossState::Type::Dead);

    EXPECT_NO_THROW(boss->getState()->response());
    EXPECT_NO_THROW(boss->getState()->getDescription());
    EXPECT_NO_THROW(boss->getState()->printState());
    EXPECT_NO_THROW(boss->response());
    EXPECT_NO_THROW(boss->viewState());
    EXPECT_FALSE(boss->isFriendly());

    delete boss;
}

TEST(TestDragonBoss, testInvalidAttack) {
    DragonBoss* boss = new DragonBoss();

    EXPECT_THROW(boss->attack(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestDragonBoss, testInvalidTransmogrify) {
    DragonBoss* boss = new DragonBoss();

    EXPECT_THROW(boss->transmogrify(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestDragonBoss, testInvalidTakeItem) {
    DragonBoss* boss = new DragonBoss();

    EXPECT_THROW(boss->takeItem(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestDragonBoss, testInvalidBuff) {
    DragonBoss* boss = new DragonBoss();

    EXPECT_THROW(boss->buff(nullptr), invalid_parameter_error);

    delete boss;
}
