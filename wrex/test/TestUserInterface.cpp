/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#include "gtest/gtest.h"
#include "UserInterface.h"

TEST(TestUserInterface, testPrintable) {
    UserInterface* ui = new UserInterface();

    EXPECT_NO_THROW(ui->showNormalHelp());
    EXPECT_NO_THROW(ui->showBattleHelp());
    EXPECT_NO_THROW(ui->showNormalCommands());
    EXPECT_NO_THROW(ui->showBattleCommands());
    EXPECT_NO_THROW(ui->showStageCommands());

    delete ui;
}
