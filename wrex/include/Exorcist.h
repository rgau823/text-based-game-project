/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef EXORCIST_H
#define EXORCIST_H

#include <string>
#include <vector>

#include "Character.h"
#include "Enemy.h"
#include "Exception.h"
#include "ExorcistState.h"
#include "NPC.h"

/**
* A concrete class derived from the Character base class.
* The Exorcist is the main character, and consists of
* three states that will determine how likely an action
* will succeed and the amount of stat bonuses applied.
*/

class Exorcist : public Character {
 public:
    /**
    * The default constructor for Exorcist.
    */
    Exorcist();

    /**
    * A constructor for the Exorcist class.
    * @param[in] n the name of the Exorcist to be created.
    */
    Exorcist(std::string n);

    /**
    * The destructor for Exorcist.
    */
    virtual ~Exorcist();

    /**
    * The Exorcist attempts to attack a Character, friend or foe.
    * This method is affected by ExorcistState.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character* c);

    /**
    * Alter the Exorcist's modifier(s).
    * This method is affected by ExorcistState.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * The Exorcist attempts to talk to a NPC, friend or foe.
    * @param[in] c the pointer to a NPC to talk to.
    */
    virtual void talk(NPC* n);

    /**
    * The Exorcist attempts to gift a Enemy an Item, friend or foe.
    * @param[in] c the pointer to a Enemy to gift
    * @param[in] i the pointer to an Item to gift
    * @returns true if gifting was successful, false otherwise.
    */
    virtual bool takeItem(Item* i);

    /**
    * The Exorcist attempts to flee from combat with an Enemy.
    * This method is affected by ExorcistState.
    * @returns true if able to flee, false otherwise.
    */
    virtual bool flee();

    /**
    * Set the state of the Exorcist, depending on the current health.
    */
    virtual void update();

    /**
    * Get the backpack of the Exorcist.
    * @returns the backpack of the Exorcist as a vector of Item.
    */
    std::vector<Item*> getBackpack();

    /**
    * Get an Item from the Exorcist's backpack.
    * @param[in] i the index of the Item.
    * @returns a pointer to the Item.
    */
    Item* getItem(unsigned int i);

    /**
    * Use an Item from the Exorcist's backpack.
    * @param[in] i the index of the Item.
    */
    void useItem(unsigned int i);

    /**
    * Drop an Item from the Exorcist's backpack.
    * @param[in] i the index of the Item.
    * @returns a pointer to the Item.
    */
    Item* dropItem(unsigned int i);

    /**
    * Get the state of the Exorcist.
    * @returns the state of the Exorcist as an ExorcistState*.
    */
    ExorcistState* getState();

    /**
    * Set the state of the Exorcist.
    * @param[in] s the state to be set for the Exorcist.
    */
    void setState(ExorcistState::Type s);

    /**
    * The Exorcist attempts to interact with the environment.
    * @returns true if there is an interaction to be had, false otherwise.
    */
    bool interact();

    /**
    * View the content of the Exorcist's backpack.
    */
    void viewBackpack();

    /**
    * View the state of the Exorcist.
    */
    void viewState();

 private:
    ExorcistState* state = nullptr;
    std::vector<Item*> backpack;
};

#endif // EXORCIST_H
