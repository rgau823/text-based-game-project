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
#include "ExorcistState.h"

TEST(TestExorcistState, testSaneConstructor) {
    ExorcistState* state = new SaneState();

    EXPECT_EQ(state->type, ExorcistState::Type::Sane);

    delete state;
}

TEST(TestExorcistState, testInjuredConstructor) {
    ExorcistState* state = new InjuredState();

    EXPECT_EQ(state->type, ExorcistState::Type::Injured);

    delete state;
}

TEST(TestExorcistState, testPossessedConstructor) {
    ExorcistState* state = new PossessedState();

    EXPECT_EQ(state->type, ExorcistState::Type::Possessed);

    delete state;
}

TEST(TestExorcistState, testSaneAttack) {
    Exorcist* exorcist = new Exorcist();
    Enemy* enemy = new Enemy("Enemy");

    exorcist->attack(enemy);
    EXPECT_NEAR(enemy->getHealth(), 100, 100);

    delete exorcist;
    delete enemy;
}

TEST(TestExorcistState, testInjuredAttack) {
    Exorcist* exorcist = new Exorcist();

    exorcist->setState(ExorcistState::Type::Injured);

    Enemy* enemy = new Enemy("Enemy");

    exorcist->attack(enemy);
    EXPECT_NEAR(enemy->getHealth(), 100, 100);

    delete exorcist;
    delete enemy;
}

TEST(TestExorcistState, testPossessedAttack) {
    Exorcist* exorcist = new Exorcist();

    exorcist->setState(ExorcistState::Type::Possessed);

    Enemy* enemy = new Enemy("Enemy");

    exorcist->attack(enemy);
    EXPECT_NEAR(enemy->getHealth(), 100, 50);

    delete exorcist;
    delete enemy;
}

TEST(TestExorcistState, testSaneTransmogrify) {
    Exorcist* exorcist = new Exorcist();

    EXPECT_EQ(exorcist->getModifier(), 3);

    delete exorcist;
}

TEST(TestExorcistState, testInjuredTransmogrify) {
    Exorcist* exorcist = new Exorcist();

    exorcist->setState(ExorcistState::Type::Injured);

    EXPECT_EQ(exorcist->getModifier(), 2);

    delete exorcist;
}

TEST(TestExorcistState, testPossessedTransmogrify) {
    Exorcist* exorcist = new Exorcist();

    exorcist->setState(ExorcistState::Type::Possessed);

    EXPECT_EQ(exorcist->getModifier(), 1);

    delete exorcist;
}

TEST(TestExorcistState, testSaneFlee) {
    Exorcist* exorcist = new Exorcist();

    EXPECT_NEAR(exorcist->flee(), 0, 1);

    delete exorcist;
}

TEST(TestExorcistState, testInjuredFlee) {
    Exorcist* exorcist = new Exorcist();

    exorcist->setState(ExorcistState::Type::Injured);

    EXPECT_NEAR(exorcist->flee(), 0, 1);

    delete exorcist;
}

TEST(TestExorcistState, testPossessedFlee) {
    Exorcist* exorcist = new Exorcist();

    exorcist->setState(ExorcistState::Type::Possessed);

    EXPECT_NEAR(exorcist->flee(), 0, 1);

    delete exorcist;
}

TEST(TestExorcistState, testPrint) {
    Exorcist* exorcist = new Exorcist();

    exorcist->setState(ExorcistState::Type::Sane);
    EXPECT_NO_THROW(exorcist->viewState());

    exorcist->setState(ExorcistState::Type::Injured);
    EXPECT_NO_THROW(exorcist->viewState());

    exorcist->setState(ExorcistState::Type::Possessed);
    EXPECT_NO_THROW(exorcist->viewState());

    delete exorcist;
}
