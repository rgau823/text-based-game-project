/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "DogCollar.h"
#include "Exorcist.h"
#include "ExorcistState.h"
#include "Enemy.h"
#include "Item.h"
#include "RedPotion.h"

TEST(TestExorcist, testDefaultConstructor) {
    Exorcist* exorcist = new Exorcist();
    EXPECT_EQ(exorcist->getName(), "Exorcist");

    delete exorcist;
}

TEST(TestExorcist, testConstructor) {
    Exorcist* exorcist = new Exorcist("Wrex");
    EXPECT_EQ(exorcist->getName(), "Wrex");

    delete exorcist;
}

TEST(TestExorcist, testDefaultConstructorGetState) {
    Exorcist* exorcist = new Exorcist();
    EXPECT_EQ(exorcist->getState()->type, ExorcistState::Type::Sane);

    delete exorcist;
}

TEST(TestExorcist, testSetGetName) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setName("Wrex");
    EXPECT_EQ(exorcist->getName(), "Wrex");

    delete exorcist;
}

TEST(TestExorcist, testSetGetHealth) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setHealth(500);
    EXPECT_EQ(exorcist->getHealth(), 500);

    delete exorcist;
}

TEST(TestExorcist, testSetGetStrength) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setStrength(100);
    EXPECT_EQ(exorcist->getStrength(), 100);

    delete exorcist;
}

TEST(TestExorcist, testSetGetModifiedDefense) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setDefense(100);
    EXPECT_EQ(exorcist->getDefense(), 103);

    delete exorcist;
}

TEST(TestExorcist, testSetGetModifier) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setModifier(100);
    EXPECT_EQ(exorcist->getModifier(), 100);

    delete exorcist;
}

TEST(TestExorcist, testSetGetPosition) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setPosition(5);
    EXPECT_EQ(exorcist->getPosition(), 5);

    delete exorcist;
}

TEST(TestExorcist, testTakeDamage) {
    Exorcist* exorcist = new Exorcist();

    EXPECT_EQ(exorcist->getHealth(), 100);

    exorcist->takeDamage(10);

    EXPECT_EQ(exorcist->getHealth(), 90);

    delete exorcist;
}

TEST(TestExorcist, testIsDead) {
    Exorcist* exorcist = new Exorcist();

    EXPECT_EQ(exorcist->getHealth(), 100);
    EXPECT_FALSE(exorcist->isDead());

    exorcist->setHealth(1);
    EXPECT_FALSE(exorcist->isDead());

    exorcist->setHealth(0);
    EXPECT_TRUE(exorcist->isDead());

    delete exorcist;
}

TEST(TestExorcist, testSetGetState) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setState(ExorcistState::Type::Injured);
    exorcist->setState(ExorcistState::Type::Possessed);

    EXPECT_EQ(exorcist->getState()->type, ExorcistState::Type::Possessed);

    delete exorcist;
}

TEST(TestExorcist, testAttack) {
    Exorcist* exorcist = new Exorcist("Exorcist");
    Enemy* enemy = new Enemy("Enemy");

    exorcist->attack(enemy);
    EXPECT_NEAR(enemy->getHealth(), 100, 50);

    delete exorcist;
    delete enemy;
}

TEST(TestExorcist, testDeadAttack) {
    Exorcist* exorcist = new Exorcist("Exorcist");
    Enemy* enemy = new Enemy("Enemy");

    enemy->setHealth(0);

    EXPECT_FALSE(exorcist->attack(enemy));
    EXPECT_EQ(enemy->getHealth(), 0);

    delete exorcist;
    delete enemy;
}

TEST(TestExorcist, testMaximumAttack) {
    Exorcist* exorcist = new Exorcist("Exorcist");
    Enemy* enemy = new Enemy("Enemy");

    exorcist->setStrength(500);
    enemy->setHealth(1);

    do {
        bool success = exorcist->attack(enemy);
        if (success) break;
    } while (true);

    EXPECT_EQ(enemy->getHealth(), 0);

    delete exorcist;
    delete enemy;
}

TEST(TestExorcist, testTransmogrify) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setState(ExorcistState::Type::Possessed);
    EXPECT_EQ(exorcist->getModifier(), 1);

    delete exorcist;
}

TEST(TestExorcist, testTakeItem) {
    Exorcist* exorcist = new Exorcist("Exorcist");
    RedPotion* potion = new RedPotion();

    exorcist->takeItem(potion);
    std::vector<Item*> backpack = exorcist->getBackpack();

    EXPECT_EQ(backpack.size(), 1);

    Item* item = exorcist->getItem(0);
    Item::Identifier name = item->getIdentifier();
    Item::Type type = item->getType();

    EXPECT_EQ(name, Item::Identifier::RedPotion);
    EXPECT_EQ(type, Item::Type::Consumable);

    delete exorcist;
}

TEST(TestExorcist, testDropItem) {
    Exorcist* exorcist = new Exorcist("Exorcist");
    RedPotion* potion = new RedPotion();

    exorcist->takeItem(potion);

    Item* item = exorcist->dropItem(0);
    Item::Identifier name = item->getIdentifier();
    Item::Type type = item->getType();

    EXPECT_EQ(name, Item::Identifier::RedPotion);
    EXPECT_EQ(type, Item::Type::Consumable);

    std::vector<Item*> backpack = exorcist->getBackpack();

    EXPECT_EQ(backpack.size(), 0);

    delete item;
    delete exorcist;
}

TEST(TestExorcist, testUseItem) {
    Exorcist* exorcist = new Exorcist("Exorcist");
    RedPotion* potion = new RedPotion();

    exorcist->setHealth(50);
    exorcist->takeItem(potion);
    exorcist->useItem(0);

    EXPECT_EQ(exorcist->getHealth(), 100);

    std::vector<Item*> backpack = exorcist->getBackpack();
    EXPECT_EQ(backpack.size(), 0);

    delete exorcist;
}

TEST(TestExorcist, testGetBackpack) {
    Exorcist* exorcist = new Exorcist("Exorcist");
    RedPotion* potion = new RedPotion();

    exorcist->takeItem(potion);
    std::vector<Item*> backpack = exorcist->getBackpack();

    exorcist->viewBackpack();
    EXPECT_EQ(backpack.size(), 1);

    delete exorcist;
}

TEST(TestExorcist, testFlee) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->flee();
    EXPECT_NEAR(exorcist->flee(), 0, 1);

    delete exorcist;
}

TEST(TestExorcist, testUpdate) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    exorcist->setHealth(100);
    EXPECT_NO_THROW(exorcist->update());

    exorcist->setHealth(60);
    EXPECT_NO_THROW(exorcist->update());

    exorcist->setHealth(30);
    EXPECT_NO_THROW(exorcist->update());

    delete exorcist;
}

TEST(TestExorcist, testViewState) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    EXPECT_NO_THROW(exorcist->viewState());

    delete exorcist;
}

TEST(TestExorcist, testInvalidGetItem) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    EXPECT_THROW(exorcist->getItem(0), invalid_parameter_error);

    delete exorcist;
}

TEST(TestExorcist, testInvalidUseItem) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    DogCollar* collar = new DogCollar();
    exorcist->takeItem(collar);

    EXPECT_THROW(exorcist->useItem(5), invalid_parameter_error);

    delete exorcist;
}

TEST(TestExorcist, testInvalidDropItem) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    EXPECT_THROW(exorcist->dropItem(1), invalid_parameter_error);

    delete exorcist;
}

TEST(TestExorcist, testInvalidAttack) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    EXPECT_THROW(exorcist->attack(nullptr), invalid_parameter_error);

    delete exorcist;
}

TEST(TestExorcist, testInvalidTransmogrify) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    EXPECT_THROW(exorcist->transmogrify(nullptr), invalid_parameter_error);

    delete exorcist;
}

TEST(TestExorcist, testInvalidTalk) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    EXPECT_THROW(exorcist->talk(nullptr), invalid_parameter_error);

    delete exorcist;
}

TEST(TestExorcist, testInvalidTakeItem) {
    Exorcist* exorcist = new Exorcist("Exorcist");

    EXPECT_THROW(exorcist->takeItem(nullptr), invalid_parameter_error);

    delete exorcist;
}
