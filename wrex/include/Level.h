/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

#include "Battle.h"
#include "Character.h"
#include "Exception.h"
#include "Item.h"

/**
* An abstract base class for a Level.
*/

class Level {
 public:
    /**
    * The classification of Item.
    */
    enum Type {
        Normal,
        Puzzle,
        Teleport
    };

    /**
    * The destructor for Level.
    */
    virtual ~Level();

    /**
    * Get the identifier of the Level.
    * @returns the identifier of the Level as an unsigned int.
    */
    unsigned int getIdentifier();

    /**
    * Get the description of the Level.
    * @returns the description of the Level as a string.
    */
    std::string getDescription();

    /**
    * Get the name of Level.
    * @returns the name of the Level as a string.
    */
    std::string getName();

    /**
    * Get the type of the Level.
    * @returns the type of the Level as a Type enumeration.
    */
    Type getType();

    /**
    * Get the Exorcist
    * @returns the Exorcist as an Exorcist*.
    */
    Exorcist* getExorcist();

    /**
    * Get the Item(s) contained in the Level.
    * @returns a vector of Item(s) in the Level.
    */
    std::vector<Item*> getItems();

    /**
    * Get the enemies contained within the Level.
    * @returns a vector of Enemy* in the Level.
    */
    std::vector<Enemy*> getEnemies();

    /**
    * Set the identifier of the Level.
    * @param[in] i the identifier for the Level.
    */
    void setIdentifier(unsigned int i);

    /**
    * Set the description of the Level.
    * @param[in] d the description for the Level.
    */
    void setDescription(std::string d);

    /**
    * Set the name of Level.
    * @param[in] t the name of Level.
    */
    void setName(std::string t);

    /**
    * Set the type of the Level.
    * @param[in] t the type to be set for the Level.
    */
    void setType(Type t);

    /**
    * Add the Exorcist to the Level.
    * @param[in] e the Exorcist to set in the Level.
    */
    void addExorcist(Exorcist* e);

    /**
    * Remove the Exorcist from the Level.
    */
    void removeExorcist();

    /**
    * Add a Enemy to the Level.
    * @param[in] e the Enemy to add to the Level.
    */
    void addEnemy(Enemy* e);

    /**
    * Remove an Enemy from the Level.
    * @param[in] e the Enemy to remove from the Level.
    */
    void removeEnemy(Enemy* e);

    /**
    * Add an item to the Level.
    * @param[in] i the Item to add to the Level.
    */
    void addItem(Item* i);

    /**
    * Remove an item from the Level.
    * @param[in] i the Item to remove from the Level.
    */
    void removeItem(Item* i);

    /**
    * Print each Character within the Level.
    */
    void showCharacters();

    /**
    * Print each Item within the Level.
    */
    void showItems();

    /**
    * Print the stautus of the Level.
    */
    void showStatus();

    /**
    * Print everything within the Level.
    */
    void showLevel();

    /**
    * Examine and get detailed information about the Level.
    */
    void examine();

    /**
    * Create a Battle for the Exorcist to battle
    * enemies contained within a level.
    */
    void createBattle();

    /**
    * Check if a Level is cleared.
    */
    virtual bool isCleared() = 0;

    /**
    * Interact with the Level.
    */
    virtual void interact() = 0;

 private:
    unsigned int id = 0;
    std::string name;
    std::string description;
    Type type;
    Exorcist* exorcist = nullptr;
    std::vector<Enemy*> enemies;
    std::vector<Item*> items;
};

#endif // LEVEL_H
