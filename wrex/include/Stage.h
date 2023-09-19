/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef STAGE_H
#define STAGE_H

#include <vector>

#include "Exception.h"
#include "Level.h"

/**
* A collection of Level(s). A Stage is locked, until a
* condition is met, such as: defeating a boss, solving
* puzzle or using a core item.
*/

class Stage {
 public:
    /**
    * The default constructor for Stage.
    */
    Stage() {}

    /**
    * A constructor for Stage.
    */
    Stage(unsigned int i);

    /**
    * The destructor for Stage.
    */
    virtual ~Stage();

    /**
    * Get the identifier of the Stage.
    * @returns the identifier of the Stage as an integer.
    */
    unsigned int getIdentifier();

    /**
    * Get the Level(s) contained in the Stage.
    * @returns a vector of Level(s) in the Stage.
    */
    std::vector<Level*> getLevels();

    /**
    * Add a Level to the Stage.
    * @param[in] l the pointer of the Level to add to the Stage.
    */
    void addLevel(Level* l);

    /**
    * Set the identifier of the Stage.
    * @param[in] i the identifier to set for the Stage.
    */
    void setIdentifier(unsigned int i);

    /**
    * Check if the Stage was cleared.
    * @returns true if the Stage was cleared, false otherwise.
    */
    bool isCleared();

    /**
    * View the Stage.
    */
    void showStage();

    /**
    * Label the Level's in a Stage after shuffling.
    */
    void labelStage();

    /**
    * Shuffle the Level's in a Stage.
    */
    void shuffleStage();

 private:
    unsigned int id = 0;
    bool lock = true;
    const int limit = 9;
    std::vector<Level*> levels;
};

#endif // STAGE_H
