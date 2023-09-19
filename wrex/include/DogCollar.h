/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 11, 2021
 */

#ifndef DOGCOLLAR_H
#define DOGCOLLAR_H

#include <string>

#include "DogBoss.h"
#include "Item.h"

/**
* The Dog Collar is a core item.
* It should be used on the Ghost Dog when it is in the Vengeful state.
*/

class DogCollar : public Item {
 public:
    /**
    * Default constructor for the DogCollar.
    * It sets the name and the description.
    */
    DogCollar();

    /**
    * The use method for the DogCollar.
    */
    virtual void use(Character* c);

    /**
    * View the name of the Item.
    */
    virtual std::string name();
};

#endif // DOGCOLLAR_H
