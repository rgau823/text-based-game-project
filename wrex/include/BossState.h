/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 08, 2021
 */

#ifndef BOSSSTATE_H
#define BOSSSTATE_H

#include <string>

#include "Character.h"
#include "Dialog.h"
#include "Item.h"

/**
 * BossState is used to control various states
 * of the Boss, depending on the context.
 */

class BossState {
 public:
    /**
    * The type of state for BossState
    */
    enum Type {
        Hostile,
        Vengeful,
        Friendly,
        Dead
    };

    /**
    * The default constructor for the BossState class.
    * @param[in] n the name of the state.
    */
    BossState(Type t) : type(t), dialog(new Dialog) {}

    /**
    * The destructor for BossState
    */
    virtual ~BossState() {
        if (dialoger) delete dialoger;
        if (dialog) delete dialog;
    }

    /**
    * The Boss attempts to attack a Character.
    * It depends on context and state of Boss.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character* c) = 0;

    /**
    * The Boss alters a Character's modifier.
    * It depends on context and state of the Boss.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c) = 0;

    /**
    * The Boss receives an Item from the Exorcist.
    * @return true if Item was received successfully.
    */
    virtual bool takeItem(Item* i) = 0;

    /**
    * A response from the Boss when talked to.
    * It depends on context and state of the Boss.
    */
    virtual void response() = 0;

    /**
    * The description of the Boss.
    * It depends on context and state of the Boss.
    */
    virtual void getDescription() = 0;

    /**
    * View the state of the Boss.
    * It depends on context and state of the Boss.
    */
    virtual void printState() = 0;

    /**
    * The type of state.
    */
    Type type;

 protected:
    Dialoger* dialoger = nullptr;
    Dialog* dialog = nullptr;
};

class VengefulState : public BossState {
 public:
    /**
    * The default constructor for the VengefulState class.
    */
    VengefulState();

    /**
    * The Boss attacks a Character in the Vengeful state.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character *c);

    /**
    * The Boss alters a Character's modifier in the Vengeful state.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * The Boss receives an Item from the Exorcist in the Vengeful state.
    * @return true if Item was received successfully.
    */
    virtual bool takeItem(Item* i);

    /**
    * A Vengeful response from the Boss when talked to.
    */
    virtual void response();

    /**
    * The description of the Boss in the Vengeful state.
    */
    virtual void getDescription();

    /**
    * View the current state of the Boss.
    */
    virtual void printState();
};

class HostileState : public BossState {
 public:
    /**
    * The default constructor for the HostileState class.
    */
    HostileState();

    /**
    * The Boss attacks a Character in the Hostile state.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character *c);

    /**
    * The Boss alters a Character's modifier in the Hostile state.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * The Boss receives an Item from the Exorcist in the Hostile state.
    * @return true if Item was received successfully.
    */
    virtual bool takeItem(Item* i);

    /**
    * A Hostile response from the Boss when talked to.
    */
    virtual void response();

    /**
    * The description of the Boss in the Hostile state.
    */
    virtual void getDescription();

    /**
    * View the current state of the Boss.
    */
    virtual void printState();
};

class FriendlyState : public BossState {
 public:
    /**
    * The default constructor for the FriendlyState class.
    */
    FriendlyState();

    /**
    * The Boss attacks a Character in the Friendly state.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character *c);

    /**
    * The Boss alters a Character's modifier in the Friendly state.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * The Boss receives an Item from the Exorcist in the Friendly state.
    * @return true if Item was received successfully.
    */
    virtual bool takeItem(Item* i);

    /**
    * A Friendly response from the Boss when talked to.
    */
    virtual void response();

    /**
    * The description of the Boss in the Friendly state.
    */
    virtual void getDescription();

    /**
    * View the current state of the Boss.
    */
    virtual void printState();
};

class DeadState : public BossState {
 public:
    /**
    * The default constructor for the DeadState class.
    */
    DeadState();

    /**
    * The Boss attacks a Character in the Dead state.
    * @param[in] c the pointer to a Character to attack.
    * @returns true if the attack was successful, false otherwise.
    */
    virtual bool attack(Character *c);

    /**
    * The Boss alters a Character's modifier in the Dead state.
    * @param[in] c the pointer to a Character to transmogrify.
    */
    virtual void transmogrify(Character* c);

    /**
    * The Boss receives an Item from the Exorcist in the Dead state.
    * @return true if Item was received successfully.
    */
    virtual bool takeItem(Item* i);

    /**
    * A Dead response from the Boss when talked to.
    */
    virtual void response();

    /**
    * The description of the Boss in the Dead state.
    */
    virtual void getDescription();

    /**
    * View the current state of the Boss.
    */
    virtual void printState();
};

#endif // BOSSSTATE_H
