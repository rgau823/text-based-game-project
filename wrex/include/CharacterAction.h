/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef CHARACTERACTION_H
#define CHARACTERACTION_H

#include <string>

/**
* Forward declaration of the Character class.
*/
class Character;
class Item;

/**
* An interface for the action(s) of a Character.
*
* The Character base class will not have a default
* implementation due to concrete classes using the
* State Pattern to alter the implementation.
*/

class CharacterAction {
 public:
    /**
    * Attack a Character, friend or foe.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character* c) = 0;

    /**
    * Alter the modifier(s) of the Character.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c) = 0;

    /**
    * The Character receives an Item from another Character.
    * @returns true if the item was received, false otherwise.
    */
    virtual bool takeItem(Item* i) = 0;

    /**
    * Set the state of the Character, depending on the context.
    */
    virtual void update() = 0;
};

#endif // CHARACTERACTION_H
