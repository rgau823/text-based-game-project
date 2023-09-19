/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 11, 2021
 */

#ifndef DRAGONSWORD_H
#define DRAGONSWORD_H

#include <string>

#include "DragonBoss.h"
#include "Item.h"

/**
 * The Dragon Sword is a core item.
 * It should be used on the Ghost Dragon when it is in the Vengeful state.
 */

class DragonSword : public Item {
 public:
    /**
    * Default constructor for the DragonSword.
    * It sets the name and the description.
    */
    DragonSword();

    /**
    * The use method for the DragonSword.
    * It provides a hint for its true purpose.
    */
    virtual void use(Character* c);

    /**
    * View the name of the Item.
    */
    virtual std::string name();
};

#endif // DRAGONSWORD_H
