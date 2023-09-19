/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef NORMALLEVEL_H
#define NORMALLEVEL_H

#include <string>

#include "Level.h"

class NormalLevel : public Level {
 public:
    NormalLevel();

    /**
    * The destructor for NormalLevel.
    */
    virtual ~NormalLevel() {}

    /**
    * Get the status of the NormalLevel.
    * @returns a boolean indicating if the Level was cleared.
    */
    virtual bool isCleared();

    /**
    * Interact with the Level to gather more information about it.
    */
    virtual void interact();

 private:
    int limit = 3;
};

#endif // NORMALLEVEL_H
