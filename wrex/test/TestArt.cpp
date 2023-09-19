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
#include "Art.h"

TEST(TestArt, testPrintable) {
    Art art;

    EXPECT_NO_THROW(art.gameover());
    EXPECT_NO_THROW(art.trueEnding());
    EXPECT_NO_THROW(art.neutralEnding());
    EXPECT_NO_THROW(art.badEnding());
}
