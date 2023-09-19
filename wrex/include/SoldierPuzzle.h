/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 21, 2021
 */

#ifndef SOLDIERPUZZLE_H
#define SOLDIERPUZZLE_H

#include <string>

#include "PuzzleLevel.h"

/**
* The Soldier Puzzle is the third Puzzle of the Game.
*/

class SoldierPuzzle : public PuzzleLevel {
 public:
    /**
    * The default constructor for DragonPuzzle.
    */
    SoldierPuzzle();

    /**
    * The method to check if Puzzle's been completed or not.
    * If not, it goes to the Puzzle in the stage.
    */
    void puzzle();

    /**
    * A Puzzle for the player to solve to achieve the SoldierPendant.
    */
    void battlefield();

 private:
    int attempt = 2;
    std::string path;
};

#endif // SOLDIERPUZZLE_H
