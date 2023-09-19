/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include "gtest/gtest.h"
#include "Level.h"
#include "DogPuzzle.h"

TEST(TestDogPuzzle, testDogPuzzle) {
    DogPuzzle* puzzle = new DogPuzzle();

    EXPECT_EQ(puzzle->getType(), Level::Type::Puzzle);

    delete puzzle;
}

TEST(TestDogPuzzle, testIsCleared) {
    DogPuzzle* puzzle = new DogPuzzle();
    puzzle->setSolved(true);

    EXPECT_NO_THROW(puzzle->puzzle());

    delete puzzle;
}

TEST(TestDogPuzzle, testShowNotCleared) {
    DogPuzzle* puzzle = new DogPuzzle();

    EXPECT_NO_THROW(puzzle->showStatus());

    delete puzzle;
}
