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
#include "Display.h"

TEST(TestDisplay, testPrintable) {
    Display display;

    EXPECT_NO_THROW(display.open("ascii/intro.txt"));
    EXPECT_NO_THROW(display.open("ascii/logo.txt"));
    EXPECT_NO_THROW(display.open("ascii/skeleton.txt"));
    EXPECT_NO_THROW(display.open("ascii/gameover.txt"));
    EXPECT_NO_THROW(display.open("ascii/first.txt"));
    EXPECT_NO_THROW(display.open("ascii/second.txt"));
    EXPECT_NO_THROW(display.open("ascii/third.txt"));
    EXPECT_NO_THROW(display.open("ascii/final.txt"));
    EXPECT_NO_THROW(display.open("ascii/stage.txt"));

    EXPECT_NO_THROW(display.open("text/introduction/part_1.txt"));
    EXPECT_NO_THROW(display.open("text/introduction/part_2.txt"));
    EXPECT_NO_THROW(display.open("text/introduction/part_3.txt"));
    EXPECT_NO_THROW(display.open("text/introduction/part_4.txt"));

    EXPECT_NO_THROW(display.open("text/puzzle/dog_puzzle/badinput.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dog_puzzle/choice.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dog_puzzle/dead.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dog_puzzle/exit.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dog_puzzle/incorrect.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dog_puzzle/status.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dog_puzzle/welcome.txt"));

    EXPECT_NO_THROW(display.open("text/puzzle/dragon_puzzle/badinput.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dragon_puzzle/choice.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dragon_puzzle/dead.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dragon_puzzle/exit.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dragon_puzzle/incorrect.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dragon_puzzle/status.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/dragon_puzzle/welcome.txt"));

    EXPECT_NO_THROW(display.open("text/puzzle/shadow_puzzle/badinput.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/shadow_puzzle/choice.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/shadow_puzzle/dead.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/shadow_puzzle/exit.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/shadow_puzzle/incorrect.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/shadow_puzzle/status.txt"));

    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/badinput.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/choice.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/damaged.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/dead.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/exit.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/gruff.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/incorrect.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/status.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/twisted.txt"));
    EXPECT_NO_THROW(display.open("text/puzzle/soldier_puzzle/welcome.txt"));

    EXPECT_NO_THROW(display.open("text/ending/trueEnding.txt"));
    EXPECT_NO_THROW(display.open("text/ending/neutralEnding.txt"));
    EXPECT_NO_THROW(display.open("text/ending/badEnding.txt"));

    EXPECT_NO_THROW(display.open("text/help/normal/help.txt"));
    EXPECT_NO_THROW(display.open("text/help/battle/help.txt"));
}
