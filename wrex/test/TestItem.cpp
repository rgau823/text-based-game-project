/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include <string>

#include "gtest/gtest.h"
#include "BeastBrew.h"
#include "DogCollar.h"
#include "DragonSword.h"
#include "EndingPath.h"
#include "Exorcist.h"
#include "RedPotion.h"
#include "SoldierPendant.h"
#include "Torch.h"

TEST(TestBeastBrew, testDefaultConstructor) {
    BeastBrew* brew = new BeastBrew();

    EXPECT_EQ(brew->getIdentifier(), Item::Identifier::BeastBrew);
    EXPECT_EQ(brew->getType(), Item::Type::Consumable);

    delete brew;
}

TEST(TestBeastBrew, testInteract) {
    Exorcist* exorcist = new Exorcist();
    BeastBrew* brew = new BeastBrew();

    brew->use(exorcist);

    EXPECT_EQ(exorcist->getModifier(), 6);

    delete brew;
    delete exorcist;
}

TEST(TestBeastBrew, testExamine) {
    BeastBrew* brew = new BeastBrew();

    EXPECT_NO_THROW(brew->examine());

    delete brew;
}

TEST(TestDogCollar, testDefaultConstructor) {
    DogCollar* collar = new DogCollar();

    EXPECT_EQ(collar->getIdentifier(), Item::Identifier::DogCollar);
    EXPECT_EQ(collar->getType(), Item::Type::Core);

    delete collar;
}

TEST(TestDogCollar, testInteract) {
    Exorcist* exorcist = new Exorcist();
    DogCollar* collar = new DogCollar();

    EXPECT_NO_THROW(collar->use(exorcist));

    delete exorcist;
    delete collar;
}

TEST(TestDogCollar, testExamine) {
    DogCollar* collar = new DogCollar();

    EXPECT_NO_THROW(collar->examine());

    delete collar;
}

TEST(TestDragonSword, testDefaultConstructor) {
    DragonSword* sword = new DragonSword();

    EXPECT_EQ(sword->getIdentifier(), Item::Identifier::DragonSword);
    EXPECT_EQ(sword->getType(), Item::Type::Core);

    delete sword;
}

TEST(TestDragonSword, testInteract) {
    Exorcist* exorcist = new Exorcist();
    DragonSword* sword = new DragonSword();

    EXPECT_NO_THROW(sword->use(exorcist));

    delete exorcist;
    delete sword;
}

TEST(TestRedPotion, testDefaultConstructor) {
    Exorcist* exorcist = new Exorcist();
    RedPotion* potion = new RedPotion();

    EXPECT_EQ(potion->getIdentifier(), Item::Identifier::RedPotion);
    EXPECT_EQ(potion->getType(), Item::Type::Consumable);

    delete potion;
    delete exorcist;
}

TEST(TestRedPotion, testInteract) {
    Exorcist* exorcist = new Exorcist();
    RedPotion* potion = new RedPotion();

    exorcist->setHealth(50);
    potion->use(exorcist);

    EXPECT_EQ(exorcist->getHealth(), 100);

    delete potion;
    delete exorcist;
}

TEST(TestRedPotion, testOveruse) {
    Exorcist* exorcist = new Exorcist();
    EndingPath::redpotionCounter = 0;

    for (int i = 0; i < 8; i++) {
        RedPotion* potion = new RedPotion();

        exorcist->setHealth(50);
        potion->use(exorcist);

        if (i > 7)
            EXPECT_EQ(exorcist->getHealth(), 0);

        delete potion;
    }

    delete exorcist;
}

TEST(TestSoldierPendant, testDefaultConstructor) {
    SoldierPendant* pendant = new SoldierPendant();

    EXPECT_EQ(pendant->getIdentifier(), Item::Identifier::SoldierPendant);
    EXPECT_EQ(pendant->getType(), Item::Type::Core);

    delete pendant;
}

TEST(TestSoldierPendant, testInteract) {
    Exorcist* exorcist = new Exorcist();
    SoldierPendant* pendant = new SoldierPendant();

    EXPECT_NO_THROW(pendant->use(exorcist));

    delete exorcist;
    delete pendant;
}

TEST(TestTorch, testDefaultConstructor) {
    Torch* torch = new Torch();

    EXPECT_EQ(torch->getIdentifier(), Item::Identifier::Torch);
    EXPECT_EQ(torch->getType(), Item::Type::Core);

    delete torch;
}

TEST(TestTorch, testInteract) {
    Exorcist* exorcist = new Exorcist();
    Torch* torch = new Torch();

    EXPECT_NO_THROW(torch->use(exorcist));

    delete torch;
    delete exorcist;
}

TEST(TestTorch, testExamine) {
    Torch* torch = new Torch();

    EXPECT_NO_THROW(torch->examine());

    delete torch;
}

TEST(TestItem, testName) {
    BeastBrew* brew = new BeastBrew();
    DogCollar* collar = new DogCollar();
    DragonSword* sword = new DragonSword();
    RedPotion* potion = new RedPotion();
    SoldierPendant* pendant = new SoldierPendant();
    Torch* torch = new Torch();

    EXPECT_NO_THROW(brew->name());
    EXPECT_NO_THROW(collar->name());
    EXPECT_NO_THROW(sword->name());
    EXPECT_NO_THROW(potion->name());
    EXPECT_NO_THROW(pendant->name());
    EXPECT_NO_THROW(torch->name());

    delete brew;
    delete collar;
    delete pendant;
    delete potion;
    delete sword;
    delete torch;
}

TEST(TestItem, testInvalidUse) {
    BeastBrew* brew = new BeastBrew();
    DogCollar* collar = new DogCollar();
    DragonSword* sword = new DragonSword();
    RedPotion* potion = new RedPotion();
    SoldierPendant* pendant = new SoldierPendant();
    Torch* torch = new Torch();

    EXPECT_THROW(brew->use(nullptr), invalid_parameter_error);
    EXPECT_THROW(collar->use(nullptr), invalid_parameter_error);
    EXPECT_THROW(sword->use(nullptr), invalid_parameter_error);
    EXPECT_THROW(potion->use(nullptr), invalid_parameter_error);
    EXPECT_THROW(pendant->use(nullptr), invalid_parameter_error);
    EXPECT_THROW(torch->use(nullptr), invalid_parameter_error);

    delete brew;
    delete collar;
    delete pendant;
    delete potion;
    delete sword;
    delete torch;
}
