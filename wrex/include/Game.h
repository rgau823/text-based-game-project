/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef GAME_H
#define GAME_H

#include "Art.h"
#include "EndingPath.h"
#include "Exorcist.h"
#include "Display.h"
#include "UserInterface.h"
#include "World.h"

/**
* A game session can be created, played and stopped,
* depending on the user's input.
*/

class Game {
 public:
    /**
    * The default constructor for Game.
    */
    Game();

    /**
    * The destructor for Game.
    */
    virtual ~Game();

    /**
    * Displays the introduction for the Game.
    */
    void introduction();

    /**
    * Play the game.
    */
    void play();

    /**
    * Stop the game.
    */
    void stop();

    /**
    * Get the Exorcist. This is used in unit testing.
    * @returns a pointer to the Exorcist.
    */
    Exorcist* getExorcist();

    /**
    * Get the Character's current Stage.
    * @param[in] c a pointer to the Character.
    * @returns a the pointer to the Stage.
    */
    Stage* getCharacterStage(Character* c);

    /**
    * Get the Character's current Level.
    * @param[in] c a pointer to the Character.
    * @returns a the pointer to the Level.
    */
    Level* getCharacterLevel(Character* c);

    /**
    * Move the position of the Character within the map.
    * @param[in] c the pointer of the Character to move.
    * @param[in] p the position to be set for the Character.
    */
    void moveCharacter(Character* c, unsigned int p);

    /**
    * View the endgame art, depending on the ending.
    */
    void ending();

 private:
    bool isRunning = false;
    World* world = nullptr;
    Exorcist* exorcist = nullptr;
    Art art;
    UserInterface ui;
};

#endif // GAME_H
