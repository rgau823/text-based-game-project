/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <string>

#include "Enemy.h"
#include "RandomNumberGenerator.h"

class EnemyFactory {
 public:
    /**
    * The default constructor for EnemyFactory.
    */
    EnemyFactory() {}

    /**
    * The destructor for EnemyFactory.
    */
    virtual ~EnemyFactory() {}

    /**
    * Create an enemy, depending on RNG.
    * @returns a generic Enemy
    */
    Enemy* createEnemy() {
        int rng = getRandomNumber(1, limit);

        switch (rng) {
            case 1:
                return new Enemy("Ghoul");
            case 2:
                return new Enemy("Spectre");
            case 3:
                return new Enemy("Wraith");
            default:
                return new Enemy("Henchman");
        }
    }

 private:
    int limit = 3;
};

#endif // ENEMYFACTORY_H
