/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include "gtest/gtest.h"
#include "SoldierPuzzle.h"

TEST(TestSoldierPuzzle, testSoldierPuzzle) {
    SoldierPuzzle* puzzle = new SoldierPuzzle();

    EXPECT_EQ(puzzle->getType(), Level::Type::Puzzle);

    delete puzzle;
}

TEST(TestSoldierPuzzle, testIsCleared) {
    SoldierPuzzle* puzzle = new SoldierPuzzle();
    puzzle->setSolved(true);

    EXPECT_NO_THROW(puzzle->puzzle());

    delete puzzle;
}

TEST(TestSoldierPuzzle, testShowNotCleared) {
    SoldierPuzzle* puzzle = new SoldierPuzzle();

    EXPECT_NO_THROW(puzzle->showStatus());

    delete puzzle;
}
