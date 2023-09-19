/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include <vector>

#include "Enemy.h"
#include "Exception.h"
#include "Exorcist.h"
#include "UserInterface.h"

/**
* A Battle is the combat sequence between the Exorcist
* and a group of enemies or a boss.
*/

class Battle {
 public:
    /**
    * A constructor for the Battle class.
    * @param[in] ex a pointer to the Exorcist
    * @param[in] en a vector of Enemy or Boss
    */
    Battle(Exorcist* ex, std::vector<Enemy*> en);

    /**
    * The destructor for Battle.
    */
    virtual ~Battle() {}

    /**
    * Start the Battle.
    */
    void start();

    /**
    * Reward the Exorcist after Battle.
    */
    void reward();

    /**
    * Check if the Battle is complete.
    * @returns the status of the Battle as a bool.
    */
    bool isComplete();

    /**
    * View the battlefield.
    */
    void viewBattle();

 private:
    Exorcist* exorcist = nullptr;
    std::vector<Enemy*> enemies;
    UserInterface ui;
};

#endif // BATTLE_H
