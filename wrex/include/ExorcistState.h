/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef EXORCISTSTATE_H
#define EXORCISTSTATE_H

#include <string>
#include <random>

#include "Character.h"

/**
* ExorcistState is used to control various states
* of the Exorcist, depending on the context.
*/

class ExorcistState {
 public:
    /**
     * The type of state for ExorcistState
     */
    enum Type {
        Sane,
        Injured,
        Possessed
    };

    /**
    * The default constructor for the ExorcistState class.
    * @param[in] n the name of the state.
    */
    ExorcistState(Type t) : type(t) {}

    /**
    * The destructor for ExorcistState.
    */
    virtual ~ExorcistState() {}

    /**
    * The Exorcist attempts to attack a Character.
    * It depends on the context and state of the Exorcist.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character* c) = 0;

    /**
    * The Exorcist's modifier(s) are altered.
    * It depends on the context and state of the Exorcist.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c) = 0;

    /**
    * The Exorcist attempts to flee from combat with an Enemy.
    * It depends on the context and state of the Exorcist.
    * @returns true if able to flee, false otherwise.
    */
    virtual bool flee() = 0;

    /**
    * View the state of the Exorcist.
    * It depends on context and state of the Exorcist.
    */
    virtual void printState() = 0;

    /**
    * The type of state.
    */
    const Type type;
};

/**
* SaneState is a state that indicates that the
* Exorcist is in a normal state, which is the
* default. As the game progresses, the Exorcist
* may lose their sanity.
*/

class SaneState : public ExorcistState {
 public:
    /**
    * The default constructor for the SaneState class.
    */
    SaneState();

    /**
    * The Exorcist attempts to attack a Character.
    * The attempt will often be successful in this state.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character* c);

    /**
    * The Exorcist's modifier(s) are altered.
    * The modifier is reset to the default in this state.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * The Exorcist attempts to flee from an Enemy.
    * The attempt will often be successful in this state.
    * @returns true if able to flee, false otherwise.
    */
    virtual bool flee();

    /**
    * View the current state of the Boss.
    */
    virtual void printState();
};

/**
* InjuredState is a state that indicates that the
* Exorcist is injured from running into a trap,
* answering a puzzle incorrectly or engaging in
* combat with enemies.
*/

class InjuredState : public ExorcistState {
 public:
    /**
    * The default constructor for the InjuredState class.
    */
    InjuredState();

    /**
    * The Exorcist attempts to attack a Character.
    * The attempt will sometimes be successful in this state.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character* c);

    /**
    * The Exorcist's modifier(s) are altered.
    * The modifier will be lower than the default value.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * The Exorcist attempts to flee from an Enemy.
    * The attempt will sometimes be successful in this state.
    * @returns true if able to flee, false otherwise.
    */
    virtual bool flee();

    /**
    * View the current state of the Boss.
    */
    virtual void printState();
};

/**
* PossessedState is a state that indicates that the
* Exorcist is possessed and will require an item or
* blessing from an ally to go back to a Sane state.
* The game will be harder, and lower the Exorcist's
* stats.
*/

class PossessedState : public ExorcistState {
 public:
    /**
    * The default constructor for the PossessedState class.
    */
    PossessedState();

    /**
    * The Exorcist attempts to attack a Character.
    * The attempt will often fail in this state.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character* c);

    /**
    * The Exorcist's modifier(s) are altered.
    * The modifier will be lower than the default value
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * The Exorcist attempts to flee from an Enemy.
    * The attempt will often be fail in this state.
    * @returns true if able to flee, false otherwise.
    */
    virtual bool flee();

    /**
    * View the current state of the Boss.
    */
    virtual void printState();
};

#endif // EXORCISTSTATE_H
