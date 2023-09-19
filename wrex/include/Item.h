/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef ITEM_H
#define ITEM_H

#include <map>
#include <string>

#include "Character.h"

/**
* Item is an abstract data class for concrete
* items to inherit from.
*/

class Item {
 public:
    /**
    * The classification of Item.
    */
    enum Type {
        Consumable,
        Core
    };

    /**
    * The name of each item.
    */
    enum Identifier {
        /* Core */
        DogCollar,
        DragonSword,
        SoldierPendant,
        Torch,

        /* Consumable */
        BeastBrew,
        RedPotion,
    };

    /**
    * The destructor for Item.
    */
    virtual ~Item() {}

    /**
    * Get the identifier of the Item.
    * @returns the identifier of the Item as a Identifier enumeration.
    */
    Identifier getIdentifier();

    /**
    * Get the type of the Item.
    * @returns the type of the Item as a Type enumeration.
    */
    Type getType();

    /**
    * Set the identifier of the Item.
    * @param[in] i the identifier to be set for the Item.
    */
    void setIdentifier(Identifier i);

    /**
    * Set the type of the Item.
    * @param[in] t the type to be set for the Item.
    */
    void setType(Type t);

    /**
    * Set the type of the Item.
    * @param[in] d the description to be set for the Item.
    */
    void setDescription(std::string d);

    /**
    * Examine and get detailed information about the Item.
    */
    void examine();

    /**
    * View the name of the Item.
    */
    virtual std::string name() = 0;

    /**
    * Use the Item.
    */
    virtual void use(Character* c) = 0;

 private:
    Item::Identifier identifier;
    Item::Type type;
    std::string description;
};

#endif // ITEM_H
