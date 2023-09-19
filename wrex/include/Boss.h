/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 08, 2021
 */

#ifndef BOSS_H
#define BOSS_H

#include <string>

#include "BossState.h"
#include "Enemy.h"
#include "Exception.h"

/**
* A base class for each Boss to inherit from.
*/

class Boss: public Enemy {
 public:
    /**
    * The default constructor for Boss.
    */
    Boss() {}

    /**
    * A constructor for the Boss class
    * @param[in] n the name of the Boss to be created.
    */
    Boss(std::string n);

    /**
    * The destructor for Boss.
    */
    virtual ~Boss();

    /**
    * Attack a Character.
    * @param[in] c a pointer to the Character to attack.
    */
    virtual bool attack(Character *c);

    /**
    * Set the modifier of Character.
    * @param[in] c a pointer to the Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * Get the response of a Boss, depending on the state.
    */
    virtual void response();

    /**
    * Get the status of the Boss - friendly or not.
    * @returns the friendly status of the Boss as a bool
    */
    virtual bool isFriendly();

    /**
    * Buff a Character after defeat
    * @returns c a pointer to the Character to buff.
    */
    virtual void buff(Character* c) = 0;

    /**
    * Set the state of the Boss, depending on current health.
    */
    virtual void update() = 0;

    /**
     * Get the state of the Boss.
     * @returns the state of the Boss as a BossState*.
     */
    BossState* getState();

    /**
    * Set the state of the Boss.
    * @param[in] s the state to be set for the Boss.
    */
    void setState(BossState::Type s);

    /**
    * View the state of the Boss.
    */
    void viewState();

 protected:
    BossState* state = nullptr;
};

#endif // BOSS_H
