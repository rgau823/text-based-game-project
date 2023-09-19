/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "CharacterAction.h"
#include "Item.h"

/**
* An abstract base class for Exorcist and NPC to inherit from.
*/

class Character : public CharacterAction {
 public:
    /**
    * The default constructor for Character.
    */
    Character() {}

    /**
    * A constructor for the Character class.
    * @param[in] n the name of the Character to be created.
    */
    Character(std::string n) : name(n) {}

    /**
    * The destructor for Character.
    */
    virtual ~Character() {}

    /**
    * Get the name of the Character.
    * @returns the name of the Character as a string.
    */
    std::string getName();

    /**
    * Get the current health of the Character.
    * @returns the current health of the Character as a int.
    */
    int getHealth();

    /**
    * Get the amount of strength the Character can do.
    * @returns the amount of strength the Character can do as a int.
    */
    int getStrength();

    /**
    * Get the defensive modifier for a Character.
    * @returns the defensive modifier of a Character as a int.
    */
    int getDefense();

    /**
    * Get the modifier percentage for a Character.
    * @returns the modifier percentage of a Character as a int.
    */
    int getModifier();

    /**
    * Get the damage a Character can inflict.
    * @returns the damage a Character can inflict as a int.
    */
    int getDamage();

    /**
    * Get the position of the Character in the map.
    * @returns the position of the Character as an unsigned int.
    */
    unsigned int getPosition();

    /**
    * Set the name of the Character.
    * @param[in] n the name to be set for the Character.
    */
    void setName(std::string n);

    /**
    * Set the health of the Character.
    * @param[in] h the health to be set for the Character.
    */
    void setHealth(int h);

    /**
    * Set the strength of the Character.
    * @param[in] d the strength to be set for the Character.
    */
    void setStrength(int s);

    /**
    * Set the defensive modifier of the Character.
    * @param[in] d the defensive modifier to be set for the Character.
    */
    void setDefense(int d);

    /**
    * Set the modifier percentage for a Character.
    * @param[in] m the modifier to be set for the Character.
    */
    void setModifier(int m);

    /**
    * Set the position of the Character within the map.
    * @param[in] p the position to be set for the Character.
    */
    void setPosition(unsigned int);

    /**
     * Take damage from a Character.
     * @param[in] d the damage to be taken from the Character.
     */
    void takeDamage(int d);

    /**
     * Is the Character dead?
     * @returns true if the Character is dead, false otherwise.
     */
    bool isDead();

 protected:
    std::string name;
    int health = 100;
    int strength = 5;
    int defense = 5;
    int modifier = 1;
    unsigned int position = 0;
};

#endif // CHARACTER_H
