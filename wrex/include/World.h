/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Exception.h"
#include "Level.h"
#include "Stage.h"
#include "Boss.h"

/**
* A container for each stage. The World will be
* used to indicate a Character's position in the
* World.
*/

class World {
 public:
    /**
    * The default constructor for World.
    */
    World();

    /**
    * The destructor for World.
    */
    virtual ~World();

    /**
    * Get the Stage(s) contained in the World.
    * @returns a vector of Stage(s) in the World.
    */
    std::vector<Stage*> getStages();

    /**
    * Add a Stage to the World.
    * @param[in] s the pointer of the Stage to add to the World.
    */
    void addStage(Stage* s);

    /**
    * View a text representation of the World.
    */
    void displayWorld();

    /**
    * View a specific Stage.
    * @param[in] i the index of Stage to view.
    */
    void showStage(int i);

 private:
    const int limit = 9;
    std::vector<Stage*> stages;
    std::vector<Boss*> bosses;
};

#endif // WORLD_H
