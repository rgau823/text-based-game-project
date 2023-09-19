/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 10, 2021
 */

#ifndef SOLDIERBOSS_H
#define SOLDIERBOSS_H

#include "Boss.h"

/**
* The Soldier Boss is the second Boss of the Game.
*/

class SoldierBoss : public Boss {
 public:
    /**
    * The default constructor for the Ghost Soldier
    */
    SoldierBoss();

    /**
    * Set the state of the SoldierBoss, depending on current health.
    */
    virtual void update();

    /**
    * The SoldierBoss receives an item from a Character.
    * @returns true if the item was received, false otherwise.
    */
    virtual bool takeItem(Item* i);

    /**
    * The SoldierBoss will buff a Character after defeat.
    * @returns c a pointer to the Character to buff.
    */
    virtual void buff(Character* c);
};

#endif // SOLDIERBOSS_H
