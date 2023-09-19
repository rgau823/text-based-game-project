/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 10, 2021
 */

#ifndef DOGPUZZLE_H
#define DOGPUZZLE_H

#include <string>

#include "PuzzleLevel.h"

/**
* The Dog Puzzle is the starting Puzzle of the Game.
*/

class DogPuzzle : public PuzzleLevel {
 public:
    /**
    * The default constructor for DogPuzzle.
    */
    DogPuzzle();

    /**
    * The method to check if puzzle's been completed or not.
    * If not, it goes to the puzzle in the stage.
    */
    void puzzle();

    /**
    * A Puzzle for the player to solve to achieve the DogCollar.
    */
    void flowerField();

 private:
    int attempt = 2;
    std::string path;
};

#endif // DOGPUZZLE_H
