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
#include "DogBoss.h"
#include "DogCollar.h"
#include "Exorcist.h"

TEST(TestDogBoss, testConstructor) {
    DogBoss* boss = new DogBoss();

    EXPECT_EQ(boss->getName(), "Ghost Dog");
    EXPECT_EQ(boss->getState()->type, BossState::Type::Hostile);
    EXPECT_EQ(boss->getHealth(), 150);
    EXPECT_EQ(boss->getStrength(), 10);
    EXPECT_EQ(boss->getDefense(), 7);
    EXPECT_EQ(boss->getModifier(), 2);

    delete boss;
}

TEST(TestDogBoss, testAttack) {
    Exorcist* exorcist = new Exorcist();
    DogBoss* boss = new DogBoss();

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

TEST(TestDogBoss, testMaximumAttack) {
    DogBoss* boss = new DogBoss();
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

TEST(TestDogBoss, testTransmogrify) {
    DogBoss* boss = new DogBoss();

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

TEST(TestDogBoss, testTakeItem) {
    DogBoss* boss = new DogBoss();

    boss->setState(BossState::Type::Vengeful);

    DogCollar* collar1 = new DogCollar();
    EXPECT_FALSE(boss->takeItem(collar1));

    boss->setState(BossState::Type::Hostile);

    DogCollar* collar2 = new DogCollar();
    EXPECT_TRUE(boss->takeItem(collar2));

    boss->setState(BossState::Type::Friendly);

    DogCollar* collar3 = new DogCollar();
    EXPECT_TRUE(boss->takeItem(collar3));

    boss->setState(BossState::Type::Dead);

    DogCollar* collar4 = new DogCollar();
    EXPECT_FALSE(boss->takeItem(collar4));

    delete collar1;
    delete collar4;
    delete boss;
}

TEST(TestDogBoss, testUpdate) {
    DogBoss* boss = new DogBoss();

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

TEST(TestDogBoss, testFriendlyUpdate) {
    DogBoss* boss = new DogBoss();
    boss->setState(BossState::Type::Friendly);

    boss->setHealth(50);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Friendly);

    delete boss;
}

TEST(TestDogBoss, testBuff) {
    Exorcist* exorcist = new Exorcist();
    DogBoss* boss = new DogBoss();

    EXPECT_EQ(exorcist->getStrength(), 20);
    EXPECT_EQ(exorcist->getDefense(), 18);

    boss->buff(exorcist);

    EXPECT_EQ(exorcist->getStrength(), 23);
    EXPECT_EQ(exorcist->getDefense(), 24);

    delete exorcist;
    delete boss;
}

TEST(TestDogBoss, testPrintable) {
    DogBoss* boss = new DogBoss();

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

TEST(TestDogBoss, testInvalidAttack) {
    DogBoss* boss = new DogBoss();

    EXPECT_THROW(boss->attack(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestDogBoss, testInvalidTransmogrify) {
    DogBoss* boss = new DogBoss();

    EXPECT_THROW(boss->transmogrify(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestDogBoss, testInvalidTakeItem) {
    DogBoss* boss = new DogBoss();

    EXPECT_THROW(boss->takeItem(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestDogBoss, testInvalidBuff) {
    DogBoss* boss = new DogBoss();

    EXPECT_THROW(boss->buff(nullptr), invalid_parameter_error);

    delete boss;
}
