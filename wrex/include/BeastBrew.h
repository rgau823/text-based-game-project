/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 11, 2021
 */

#ifndef BEASTBREW_H
#define BEASTBREW_H

#include <string>

#include "Character.h"
#include "Item.h"

/**
* The Beast Power Brew item in the game.
* It increases a Character's modifier.
*/

class BeastBrew : public Item {
 public:
    /**
    * The default constructor for the BeastBrew.
    * It sets the name and the description.
    */
    BeastBrew();

    /**
    * It changes the modifiers of the Character.
    */
    virtual void use(Character *c);

    /**
    * View the name of the Beast Power Brew.
    */
    virtual std::string name();
};

#endif // BEASTBREW_H
