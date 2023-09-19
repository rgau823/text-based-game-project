/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef PUZZLEFACTORY_H
#define PUZZLEFACTORY_H

#include "DogPuzzle.h"
#include "DragonPuzzle.h"
#include "PuzzleLevel.h"
#include "SoldierPuzzle.h"
#include "ShadowPuzzle.h"

class PuzzleFactory {
 public:
    /**
    * The default constructor for PuzzleFactory.
    */
    PuzzleFactory() {}

    /**
    * The destructor for PuzzleFactory.
    */
    virtual ~PuzzleFactory() {}

    /**
    * Create a specific Puzzle, depending on the Stage.
    * @returns a specific PuzzleLevel.
    */
    PuzzleLevel* createPuzzleLevel(unsigned int t) {
        switch (t) {
            case 0:
                return new DogPuzzle();
            case 1:
                return new SoldierPuzzle();
            case 2:
                return new DragonPuzzle();
            case 3:
                return new ShadowPuzzle();
            default:
                break;
        }

        return nullptr;
    }
};

#endif // PUZZLEFACTORY_H
