/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 21, 2021
 */

#ifndef DRAGONPUZZLE_H
#define DRAGONPUZZLE_H

#include <string>

#include "PuzzleLevel.h"

/**
* The Dog Puzzle is the second Puzzle of the Game.
*/

class DragonPuzzle : public PuzzleLevel {
 public:
    /**
    * The default constructor for DragonPuzzle.
    */
    DragonPuzzle();

    /**
    * The method to check if Puzzle's been completed or not.
    * If not, it goes to the Puzzle in the stage.
    */
    void puzzle();

    /**
    * A Puzzle for the player to solve to achieve the DragonSword.
    */
    void boneyard();

 private:
    int attempt = 2;
    std::string path;
};

#endif // DRAGONPUZZLE_H
