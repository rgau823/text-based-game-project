/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <string>

#include "Exception.h"
#include "NPC.h"

/**
* A concrete class derived from the Character base class.
* NPCs in the game share common characteristics of having
* a description and also being able to be talked to.
*/

class Enemy : public NPC {
 public:
    /**
    * The default constructor for Enemy.
    */
    Enemy();

    /**
    * A constructor for the Enemy class.
    * @param[in] n the name of the Enemy to be created.
    */
    Enemy(std::string n);

    /**
    * The destructor for Enemy.
    */
    virtual ~Enemy() {}

    /**
    * The Enemy attempts to attack a Character.
    * This method is affected by EnemyState.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character* c);

    /**
    * Provide permanent stat boost to the character passed in upon defeat.
    */
    virtual void transmogrify(Character* c);

    /**
    * The description of the Enemy.
    */
    virtual void getDescription();

    /**
    * A generic response.
    */
    virtual void response();

    /**
    * The Enemy receives an item from a Character.
    * @returns false.
    */
    virtual bool takeItem(Item* i);

    /**
    * Buff a Character after defeat
    * @returns c a pointer to the Character to buff.
    */
    virtual void buff(Character* c);

    /**
    * Set the damage and defense of the Enemy,
    * depending on current health.
    */
    virtual void update();

    /**
    * Get the status of the Enemy - friendly or not.
    * @returns false.
    */
    virtual bool isFriendly();
};

#endif // ENEMY_H
