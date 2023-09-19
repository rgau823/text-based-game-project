/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 08, 2021
 */

#ifndef DOGBOSS_H
#define DOGBOSS_H

#include "Boss.h"

/**
* The Dog Boss is the starting Boss of the Game.
*/

class DogBoss : public Boss {
 public:
    /**
    * The default constructor for the Ghost Dog
    */
    DogBoss();

    /**
    * Set the state of the DogBoss, depending on current health.
    */
    virtual void update();

    /**
    * The DogBoss receives an item from a Character.
    * @returns true if the item was received, false otherwise.
    */
    virtual bool takeItem(Item* i);

    /**
    * The DogBoss will buff a Character after defeat.
    * @returns c a pointer to the Character to buff.
    */
    virtual void buff(Character* c);
};

#endif // DOGBOSS_H
