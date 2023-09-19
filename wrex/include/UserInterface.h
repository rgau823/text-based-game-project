/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>

#include "Character.h"
#include "Display.h"

/**
* The classification of commands.
*/

enum CommandType {
    NEXT_LEVEL,
    PREVIOUS_LEVEL,
    TAKE,
    TALK,
    INTERACT,
    FIGHT,
    ATTACK,
    GIFT,
    EXAMINE,
    USE,
    DROP,
    FLEE,
    INFO,
    BACKPACK,
    CANCEL,
    QUIT,
    STAGE,
    WRONG_COMMAND = 99
};

/**
* The user interface will manager user input to assist the
* player in playing the game.
*/

class UserInterface {
 public:
    /**
    * View all available Help actions.
    */
    void showNormalHelp();

    /**
    * View all available Battle actions.
    */
    void showBattleHelp();

    /**
    * View the normal commands.
    */
    void showNormalCommands();

    /**
    * View the Battle commands.
    */
    void showBattleCommands();

    /**
    * View the Stage commands.
    */
    void showStageCommands();

    /**
    * Get user input for the normal menu.
    */
    CommandType normalInput();

    /**
    * Get user input for the Battle menu.
    */
    CommandType battleInput();

    /**
    * Parse user input when a selection is required.
    * @param[in] m the maximum amount of options.
    */
    int numberCommand(int m);

    /**
    * Press a key to continue through the menu.
    * @returns the character that was pressed.
    */
    char pressAnykey();

 private:
    Display display;
};

char getUserInput();

#endif // USERINTERFACE_H
