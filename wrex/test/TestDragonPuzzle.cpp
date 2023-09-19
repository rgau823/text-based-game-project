/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include "gtest/gtest.h"
#include "DragonPuzzle.h"

TEST(TestDragonPuzzle, testDragonPuzzle) {
    DragonPuzzle* puzzle = new DragonPuzzle();

    EXPECT_EQ(puzzle->getType(), Level::Type::Puzzle);

    delete puzzle;
}

TEST(TestDragonPuzzle, testIsCleared) {
    DragonPuzzle* puzzle = new DragonPuzzle();
    puzzle->setSolved(true);

    EXPECT_NO_THROW(puzzle->puzzle());

    delete puzzle;
}

TEST(TestDragonPuzzle, testShowNotCleared) {
    DragonPuzzle* puzzle = new DragonPuzzle();

    EXPECT_NO_THROW(puzzle->showStatus());

    delete puzzle;
}
