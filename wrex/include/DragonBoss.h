/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 10, 2021
 */

#ifndef DRAGONBOSS_H
#define DRAGONBOSS_H

#include "Boss.h"

/**
* The Dragon Boss is the second Boss of the Game.
*/

class DragonBoss : public Boss {
 public:
    /**
    * The default constructor for the Ghost Dragon
    */
    DragonBoss();

    /**
    * Set the state of the DragonBoss, depending on current health.
    */
    virtual void update();

    /**
    * The DragonBoss receives an item from a Character.
    * @returns true if the item was received, false otherwise.
    */
    virtual bool takeItem(Item* i);

    /**
    * The DragonBoss will buff a Character after defeat.
    * @returns c a pointer to the Character to buff.
    */
    virtual void buff(Character* c);
};

#endif // DRAGONBOSS_H
