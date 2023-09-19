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
#include "ShadowBoss.h"
#include "Torch.h"
#include "Exorcist.h"

TEST(TestShadowBoss, testConstructor) {
    ShadowBoss* boss = new ShadowBoss();

    EXPECT_EQ(boss->getName(), "Shadow Exorcist");
    EXPECT_EQ(boss->getState()->type, BossState::Type::Hostile);
    EXPECT_EQ(boss->getHealth(), 200);
    EXPECT_EQ(boss->getStrength(), 20);
    EXPECT_EQ(boss->getDefense(), 17);
    EXPECT_EQ(boss->getModifier(), 2);

    delete boss;
}

TEST(TestShadowBoss, testAttack) {
    Exorcist* exorcist = new Exorcist();
    ShadowBoss* boss = new ShadowBoss();

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

TEST(TestShadowBoss, testMaximumAttack) {
    ShadowBoss* boss = new ShadowBoss();
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

TEST(TestShadowBoss, testTransmogrify) {
    ShadowBoss* boss = new ShadowBoss();

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

TEST(TestShadowBoss, testTakeItem) {
    ShadowBoss* boss = new ShadowBoss();

    boss->setState(BossState::Type::Vengeful);

    Torch* torch1 = new Torch();
    EXPECT_FALSE(boss->takeItem(torch1));

    boss->setState(BossState::Type::Hostile);

    Torch* torch2 = new Torch();
    EXPECT_TRUE(boss->takeItem(torch2));

    boss->setState(BossState::Type::Friendly);

    Torch* torch3 = new Torch();
    EXPECT_TRUE(boss->takeItem(torch3));

    boss->setState(BossState::Type::Dead);

    Torch* torch4 = new Torch();
    EXPECT_FALSE(boss->takeItem(torch4));

    delete torch1;
    delete torch4;
    delete boss;
}

TEST(TestShadowBoss, testUpdate) {
    ShadowBoss* boss = new ShadowBoss();

    boss->setHealth(1000);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Hostile);

    boss->setHealth(121);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Hostile);

    boss->setHealth(100);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Vengeful);

    boss->setHealth(50);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Vengeful);

    boss->setHealth(25);
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

TEST(TestShadowBoss, testFriendlyUpdate) {
    ShadowBoss* boss = new ShadowBoss();
    boss->setState(BossState::Type::Friendly);

    boss->setHealth(50);
    boss->update();
    EXPECT_EQ(boss->getState()->type,
        BossState::Type::Friendly);

    delete boss;
}

TEST(TestShadowBoss, testBuff) {
    Exorcist* exorcist = new Exorcist();
    ShadowBoss* boss = new ShadowBoss();

    EXPECT_EQ(exorcist->getStrength(), 20);
    EXPECT_EQ(exorcist->getDefense(), 18);

    boss->buff(exorcist);

    EXPECT_EQ(exorcist->getStrength(), 25);
    EXPECT_EQ(exorcist->getDefense(), 26);

    delete exorcist;
    delete boss;
}

TEST(TestShadowBoss, testPrintable) {
    ShadowBoss* boss = new ShadowBoss();

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

TEST(TestShadowBoss, testInvalidAttack) {
    ShadowBoss* boss = new ShadowBoss();

    EXPECT_THROW(boss->attack(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestShadowBoss, testInvalidTransmogrify) {
    ShadowBoss* boss = new ShadowBoss();

    EXPECT_THROW(boss->transmogrify(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestShadowBoss, testInvalidTakeItem) {
    ShadowBoss* boss = new ShadowBoss();

    EXPECT_THROW(boss->takeItem(nullptr), invalid_parameter_error);

    delete boss;
}

TEST(TestShadowBoss, testInvalidBuff) {
    ShadowBoss* boss = new ShadowBoss();

    EXPECT_THROW(boss->buff(nullptr), invalid_parameter_error);

    delete boss;
}
