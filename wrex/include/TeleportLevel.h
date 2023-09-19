/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef TELEPORTLEVEL_H
#define TELEPORTLEVEL_H

#include <string>

#include "Level.h"

/**
* A TeleportLevel is a unique level where the
* Exorcist will be allowed to teleport to a
* new Stage/Level if a condition is met.
*/

class TeleportLevel : public Level {
 public:
    /**
    * The default constructor for TeleportLevel.
    */
    TeleportLevel();

    /**
    * The destructor for TeleportLevel.
    */
    virtual ~TeleportLevel() {}

    /**
    * Get the status of the TeleportLevel.
    * @returns a boolean indicating if the Level was cleared.
    */
    virtual bool isCleared();

    /**
    * Interact with the Level to gather more information about it.
    */
    virtual void interact();
};

#endif // TELEPORTLEVEL_H
