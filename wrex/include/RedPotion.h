/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 11, 2021
 */

#ifndef REDPOTION_H
#define REDPOTION_H

#include <string>

#include "Character.h"
#include "Item.h"

/**
* The RedPotion Item in the game.
* It restores a Character's health.
*/

class RedPotion : public Item {
 public:
    /**
    * The default constructor for the RedPotion.
    * It sets the name and description.
    */
    RedPotion();

    /**
    * The use method for RedPotion. It restores the HP of the character.
    */
    virtual void use(Character *c);

    /**
    * View the name of the Beast Power Brew.
    */
    virtual std::string name();
};

#endif // REDPOTION_H
