/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include "gtest/gtest.h"
#include "ShadowPuzzle.h"

TEST(TestShadowPuzzle, testShadowPuzzle) {
    ShadowPuzzle* puzzle = new ShadowPuzzle();

    EXPECT_EQ(puzzle->getType(), Level::Type::Puzzle);

    delete puzzle;
}

TEST(TestShadowPuzzle, testIsCleared) {
    ShadowPuzzle* puzzle = new ShadowPuzzle();
    puzzle->setSolved(true);

    EXPECT_NO_THROW(puzzle->puzzle());

    delete puzzle;
}

TEST(TestShadowPuzzle, testShowNotCleared) {
    ShadowPuzzle* puzzle = new ShadowPuzzle();

    EXPECT_NO_THROW(puzzle->showStatus());

    delete puzzle;
}
