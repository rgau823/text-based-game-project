/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 11, 2021
 */

#ifndef SOLDIERPENDANT_H
#define SOLDIERPENDANT_H

#include <string>

#include "Item.h"
#include "SoldierBoss.h"

/**
* The Soldier's Pendant is a core item.
* It should be used on the Ghost Soldier when it is in the Vengeful state.
*/

class SoldierPendant : public Item {
 public:
    /**
    * Default constructor for the SoldierPendant.
    * It sets the name and the description
    */
    SoldierPendant();

    /**
    * The use method for the SoldierPendant.
    * It provides a hint for its true purpose.
    */
    virtual void use(Character* c);

    /**
    * View the name of the Item.
    */
    virtual std::string name();
};

#endif // SOLDIERPENDANT_H
