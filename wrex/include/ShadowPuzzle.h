/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 05, 2021
 */

#ifndef SHADOWPUZZLE_H
#define SHADOWPUZZLE_H

#include <string>

#include "PuzzleLevel.h"

class ShadowPuzzle : public PuzzleLevel {
 public:
    /**
     * Default constructor for ShadowPuzzle level
     */
    ShadowPuzzle();

    /**
     * The method to check if puzzle's completed or not. If not, it goes 
     * to the puzzle in the stage.
     */
    void puzzle();

    /**
     * The puzzle that the player needs to figure out to get to the torch.
     */
    void theVoid();

 private:
    int attempt = 2;
    std::string path;
};

#endif // SHADOWPUZZLE_H
