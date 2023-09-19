/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef TELEPORTFACTORY_H
#define TELEPORTFACTORY_H

#include "DogBoss.h"
#include "DragonBoss.h"
#include "SoldierBoss.h"
#include "ShadowBoss.h"
#include "TeleportLevel.h"

class TeleportFactory {
 public:
    /**
    * The default constructor for TeleportFactory.
    */
    TeleportFactory() {}

    /**
    * The destructor for TeleportFactory.
    */
    virtual ~TeleportFactory() {}

    TeleportLevel* createTeleportLevel(unsigned int t) {
        TeleportLevel* level = new TeleportLevel();

        switch (t) {
            case 0:
                level->addEnemy(new DogBoss);
                break;
            case 1:
                level->addEnemy(new SoldierBoss);
                break;
            case 2:
                level->addEnemy(new DragonBoss);
                break;
            case 3:
                level->addEnemy(new ShadowBoss);
                break;
            default:
                break;
        }

        return level;
    }
};

#endif // TELEPORTFACTORY_H
