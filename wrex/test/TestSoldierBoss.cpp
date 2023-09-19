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
#include "Exorcist.h"
#include "SoldierBoss.h"
#include "SoldierPendant.h"

TEST(TestSoldierBoss, testConstructor) {
    SoldierBoss* boss = new SoldierBoss();

    EXPECT_EQ(boss->getName(), "Ghost Soldier");
    EXPECT_EQ(boss->getState()->type, BossState::Type::Hostile);
    EXPECT_EQ(boss->getHealth(), 200);
    EXPECT_EQ(boss->getStrength(), 20);
    EXPECT_EQ(boss->getDefense(), 17);
    EXPECT_EQ(boss->getModifier(), 2);

    delete boss;
}

TEST(TestSoldierBoss, testAttack) {
    Exorcist* exorcist = new Exorcist();
    SoldierBoss* boss = new SoldierBoss();

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

TEST(TestSoldierBoss, testMaximumAttack) {
    SoldierBoss* boss = new SoldierBoss();
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

TEST(TestSoldierBoss, testTransmogrify) {
    SoldierBoss* boss = new SoldierBoss();

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

TEST(TestSoldierBoss, testTakeItem) {
    SoldierBoss* boss = new SoldierBoss();

    boss->setState(BossState::Type::Vengeful);

    SoldierPendant* pendant1 = new SoldierPendant();
    EXPECT_FALSE(boss->takeItem(pendant1));

    boss->setState(BossState::Type::Hostile);

    SoldierPendant* pendant2 = new SoldierPendant();
    EXPECT_TRUE(boss->takeItem(pendant2));

    boss->setState(BossState::Type::Friendly);

    SoldierPendant* pendant3 = new SoldierPendant();
    EXPECT_TRUE(boss->takeItem(pendant3));

    boss->setState(BossState::Type::Dead);

    SoldierPendant* pendant4 = new SoldierPendant();
    EXPECT_FALSE(boss->takeItem(pendant4));

    delete pendant1;
    delete pendant4;
    delete boss;
}

TEST(TestSoldierBoss, testUpdate) {
    SoldierBoss* boss = new SoldierBoss();

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

TEST(TestSoldierBoss, testFriendlyUpdate) {
    SoldierBoss* boss = new SoldierBoss();
    boss->setState(BossState::Type::Friendly);

    boss->setHealth(50);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Friendly);

    delete boss;
}

TEST(TestSoldierBoss, testBuff) {
    Exorcist* exorcist = new Exorcist();
    SoldierBoss* boss = new SoldierBoss();

    EXPECT_EQ(exorcist->getStrength(), 20);
    EXPECT_EQ(exorcist->getDefense(), 18);

    boss->buff(exorcist);

    EXPECT_EQ(exorcist->getStrength(), 25);
    EXPECT_EQ(exorcist->getDefense(), 26);

    delete exorcist;
    delete boss;
}

TEST(TestSoldierBoss, testPrintable) {
    SoldierBoss* boss = new SoldierBoss();

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

TEST(TestSoldierBoss, testInvalidAttack) {
    SoldierBoss* boss = new SoldierBoss();

    EXPECT_THROW(boss->attack(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestSoldierBoss, testInvalidTransmogrify) {
    SoldierBoss* boss = new SoldierBoss();

    EXPECT_THROW(boss->transmogrify(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestSoldierBoss, testInvalidTakeItem) {
    SoldierBoss* boss = new SoldierBoss();

    EXPECT_THROW(boss->takeItem(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestSoldierBoss, testInvalidBuff) {
    SoldierBoss* boss = new SoldierBoss();

    EXPECT_THROW(boss->buff(nullptr), invalid_parameter_error);

    delete boss;
}
