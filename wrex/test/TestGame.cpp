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
#include "BeastBrew.h"
#include "Enemy.h"
#include "Exorcist.h"
#include "Game.h"
#include "Level.h"
#include "RedPotion.h"
#include "UserInterface.h"

TEST(TestGame, testPlayerNextLevel) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    Level* level = game->getCharacterLevel(exorcist);
    EXPECT_EQ(exorcist->getPosition(), 0);
    EXPECT_EQ(level->getIdentifier(), 0);

    int input = CommandType::NEXT_LEVEL;

    switch (input) {
        case CommandType::NEXT_LEVEL:
            game->moveCharacter(exorcist, exorcist->getPosition() + 1);
            break;

        default:
            break;
    }

    level = game->getCharacterLevel(exorcist);
    EXPECT_EQ(exorcist->getPosition(), 1);
    EXPECT_EQ(level->getIdentifier(), 1);

    delete game;
}

TEST(TestGame, testPlayerPreviousLevel) {
    Game* game = new Game();

    Exorcist* exorcist = game->getExorcist();
    Level* level = game->getCharacterLevel(exorcist);

    EXPECT_EQ(exorcist->getPosition(), 0);
    EXPECT_EQ(level->getIdentifier(), 0);

    // Next level
    int input = CommandType::NEXT_LEVEL;

    switch (input) {
        case CommandType::NEXT_LEVEL:
            game->moveCharacter(exorcist, exorcist->getPosition() + 1);
            break;

        default:
            break;
    }

    level = game->getCharacterLevel(exorcist);
    EXPECT_EQ(exorcist->getPosition(), 1);
    EXPECT_EQ(level->getIdentifier(), 1);

    // Previous level
    input = CommandType::PREVIOUS_LEVEL;

    switch (input) {
        case CommandType::PREVIOUS_LEVEL:
            game->moveCharacter(exorcist, exorcist->getPosition() - 1);
            break;

        default:
            break;
    }

    level = game->getCharacterLevel(exorcist);
    EXPECT_EQ(exorcist->getPosition(), 0);
    EXPECT_EQ(level->getIdentifier(), 0);

    delete game;
}

TEST(TestGame, testPlayerNextLevelOutOfBounds) {
    Game* game = new Game();

    Exorcist* exorcist = game->getExorcist();
    int i = 0;

    int input = CommandType::NEXT_LEVEL;

    // Four Levels per Stage
    for (i; i < 4; i++) {
        std::cout << "Moving to the next Level" << std::endl;

        Level* level = game->getCharacterLevel(exorcist);

        std::cout << "Moving from " << level->getIdentifier();
        std::cout << " to " << level->getIdentifier() + 1 << std::endl;

        EXPECT_EQ(level->getIdentifier(), i);

        switch (input) {
            case CommandType::NEXT_LEVEL:
                game->moveCharacter(exorcist, exorcist->getPosition() + 1);
                break;

            default:
                break;
        }
    }

    // We attempt to move the Exorcist out of bounds,
    // but remain in the last level of the Stage.
    EXPECT_EQ(exorcist->getPosition(), 3);
    delete game;
}

TEST(TestGame, testPlayerPreviousLevelOutOfBounds) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();
    int i = 0;

    int next = CommandType::NEXT_LEVEL;

    for (i; i < 3; i++) {
        Level* level = game->getCharacterLevel(exorcist);
        EXPECT_EQ(level->getIdentifier(), i);

        switch (next) {
            case CommandType::NEXT_LEVEL:
                game->moveCharacter(exorcist, exorcist->getPosition() + 1);
                break;

            default:
                break;
        }
    }

    int input = CommandType::PREVIOUS_LEVEL;

    for (i; i > -1; i--) {
        std::cout << "Moving to the previous Level" << std::endl;

        Level* level = game->getCharacterLevel(exorcist);

        std::cout << "Moving from " << level->getIdentifier();
        std::cout << " to " << level->getIdentifier() - 1 << std::endl;

        EXPECT_EQ(level->getIdentifier(), i);

        switch (input) {
            case CommandType::PREVIOUS_LEVEL:
                game->moveCharacter(exorcist, exorcist->getPosition() - 1);
                break;

            default:
                break;
        }
    }

    // We attempt to move the Exorcist out of bounds,
    // but remain in the first level of the Stage.
    EXPECT_EQ(exorcist->getPosition(), 0);
    delete game;
}

TEST(TestGame, testAutomatedPlayerMovement) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();
    int i = 0;

    std::cout << "Simulating user input to move the Exorcist..." << std::endl;
    std::cout << std::endl;

    // Next level
    std::cout << "Cycling the next Level(s) of a Stage." << std::endl;

    int next = CommandType::NEXT_LEVEL;
    std::cout << "Starting position: " << exorcist->getPosition() << std::endl;

    for (i; i < 3; i++) {
        std::cout << "Moving to the next Level" << std::endl;

        Level* level = game->getCharacterLevel(exorcist);

        std::cout << "Moving from " << level->getIdentifier();
        std::cout << " to " << level->getIdentifier() + 1 << std::endl;

        EXPECT_EQ(level->getIdentifier(), i);

        switch (next) {
            case CommandType::NEXT_LEVEL:
                game->moveCharacter(exorcist, exorcist->getPosition() + 1);
                break;

            default:
                break;
        }
    }

    std::cout << "Ending position: " << exorcist->getPosition() << std::endl;

    std::cout << std::endl;

    // Previous level
    std::cout << "Cycling the previous Level(s) of a Stage." << std::endl;

    int previous = CommandType::PREVIOUS_LEVEL;
    std::cout << "Starting position: " << exorcist->getPosition() << std::endl;

    for (i; i > 0; i--) {
        std::cout << "Moving to the previous Level" << std::endl;

        Level* level = game->getCharacterLevel(exorcist);

        std::cout << "Moving from " << level->getIdentifier();
        std::cout << " to " << level->getIdentifier() - 1 << std::endl;

        EXPECT_EQ(level->getIdentifier(), i);

        switch (previous) {
            case CommandType::PREVIOUS_LEVEL:
                game->moveCharacter(exorcist, exorcist->getPosition() - 1);
                break;

            default:
                break;
        }
    }

    std::cout << "Ending position: " << exorcist->getPosition() << std::endl;

    delete game;
}

TEST(TestGame, testGetCharacterStage) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    Level* level = game->getCharacterLevel(exorcist);
    EXPECT_EQ(level->getIdentifier(), 0);

    delete game;
}

TEST(TestGame, testGetCharacterLevel) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    Stage* stage = game->getCharacterStage(exorcist);
    EXPECT_EQ(stage->getIdentifier(), 0);

    delete game;
}

TEST(testGame, moveCharacter) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    EXPECT_EQ(exorcist->getPosition(), 0);

    game->moveCharacter(exorcist, exorcist->getPosition() + 1);

    EXPECT_EQ(exorcist->getPosition(), 1);

    game->moveCharacter(exorcist, exorcist->getPosition() + 1);
    game->moveCharacter(exorcist, exorcist->getPosition() + 1);

    EXPECT_EQ(exorcist->getPosition(), 3);

    game->moveCharacter(exorcist, exorcist->getPosition() - 1);

    EXPECT_EQ(exorcist->getPosition(), 2);

    delete game;
}

TEST(testGame, talkCharacterLevel) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    int input = CommandType::TALK;

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(exorcist->getPosition(), i);

        switch (input) {
            case CommandType::TALK: {
                Level* level = game->getCharacterLevel(exorcist);

                // Temporary
                Enemy* enemy = new Enemy();
                level->addEnemy(enemy);

                std::vector<Enemy*> enemies = level->getEnemies();
                int size = enemies.size();

                if (size == 0) break;

                Enemy* character = enemies[0];
                EXPECT_NO_THROW(exorcist->talk(character));

                break;
            }

            default:
                break;
        }

        game->moveCharacter(exorcist, exorcist->getPosition() + 1);
    }

    delete game;
}

TEST(testGame, examineItemLevel) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    int input = CommandType::EXAMINE;

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(exorcist->getPosition(), i);

        switch (input) {
            case CommandType::EXAMINE: {
                Level* level = game->getCharacterLevel(exorcist);

                // Temporary
                BeastBrew* brew = new BeastBrew();
                level->addItem(brew);

                std::vector<Item*> items = level->getItems();
                int size = items.size();

                if (size == 0) break;

                Item* item = items[0];
                item->examine();

                EXPECT_EQ(item->getIdentifier(), Item::Identifier::BeastBrew);

                break;
            }

            default:
                break;
        }

        game->moveCharacter(exorcist, exorcist->getPosition() + 1);
    }

    delete game;
}

TEST(testGame, takeItemLevel) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    int input = CommandType::TAKE;

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(exorcist->getPosition(), i);

        switch (input) {
            case CommandType::TAKE: {
                Level* level = game->getCharacterLevel(exorcist);

                // Temporary
                BeastBrew* brew = new BeastBrew();
                level->addItem(brew);

                std::vector<Item*> items = level->getItems();
                int size = items.size();

                if (size == 0) break;

                Item* item = items[0];

                std::cout << "Picking up a " << item->name();
                std::cout << " in Level " << level->getIdentifier();
                std::cout << std::endl;

                exorcist->takeItem(item);

                // Upon Game creation, the Exorcist will receive a RedPotion,
                // therefore adding an item will increase the backpack size to 2
                EXPECT_EQ(exorcist->getBackpack().size(), 2);

                level->removeItem(item);
                exorcist->dropItem(1);

                EXPECT_EQ(exorcist->getBackpack().size(), 1);

                delete brew;

                break;
            }

            default:
                break;
        }

        game->moveCharacter(exorcist, exorcist->getPosition() + 1);
    }

    delete game;
}

TEST(testGame, dropItemLevel) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    int input = CommandType::DROP;

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(exorcist->getPosition(), i);

        switch (input) {
            case CommandType::DROP: {
                Level* level = game->getCharacterLevel(exorcist);

                // Temporary
                BeastBrew* brew = new BeastBrew();
                level->addItem(brew);

                std::vector<Item*> items = level->getItems();
                int size = items.size();

                if (size == 0) break;

                Item* item = items[0];

                exorcist->takeItem(item);

                EXPECT_EQ(exorcist->getBackpack().size(), 2);

                level->removeItem(item);

                Item* dropped = exorcist->dropItem(1);

                std::cout << "Dropping a " << dropped->name();
                std::cout << " in Level " << level->getIdentifier();
                std::cout << std::endl;

                EXPECT_EQ(exorcist->getBackpack().size(), 1);

                delete brew;

                break;
            }

            default:
                break;
        }

        game->moveCharacter(exorcist, exorcist->getPosition() + 1);
    }

    delete game;
}

TEST(testGame, useItemLevel) {
    Game* game = new Game();
    Exorcist* exorcist = game->getExorcist();

    int input = CommandType::USE;

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(exorcist->getPosition(), i);

        switch (input) {
            case CommandType::USE: {
                Level* level = game->getCharacterLevel(exorcist);

                // Temporary
                RedPotion* potion = new RedPotion();
                level->addItem(potion);

                std::vector<Item*> items = level->getItems();
                int size = items.size();

                if (size == 0) break;

                Item* item = items[0];

                exorcist->takeItem(item);

                EXPECT_EQ(exorcist->getBackpack().size(), 2);

                level->removeItem(item);

                EXPECT_EQ(exorcist->getHealth(), 100);
                exorcist->setHealth(50);

                exorcist->useItem(1);

                EXPECT_EQ(exorcist->getHealth(), 100);
                EXPECT_EQ(exorcist->getBackpack().size(), 1);

                break;
            }

            default:
                break;
        }

        game->moveCharacter(exorcist, exorcist->getPosition() + 1);
    }

    delete game;
}

TEST(TestGame, testStop) {
    Game* game = new Game();

    EXPECT_NO_THROW(game->stop());

    delete game;
}

TEST(TestGame, testEnding) {
    Game* game = new Game();

    for (int i = 0; i < 4; i++) {
        EndingPath::savedBoss();
        EXPECT_NO_THROW(game->ending());
    }

    delete game;
}

TEST(TestGame, testInvalidGetCharacterStage) {
    Game* game = new Game();

    EXPECT_THROW(game->getCharacterStage(nullptr), invalid_parameter_error);

    delete game;
}

TEST(TestGame, testInvalidGetCharacterLevel) {
    Game* game = new Game();

    EXPECT_THROW(game->getCharacterLevel(nullptr), invalid_parameter_error);

    delete game;
}

TEST(TestGame, testInvalidMoveCharacter) {
    Game* game = new Game();

    EXPECT_THROW(game->moveCharacter(nullptr, 0), invalid_parameter_error);

    delete game;
}
