/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 08, 2021
 */

#ifndef NPC_H
#define NPC_H

#include <string>

#include "Character.h"

class NPC : public Character {
 public:
    /**
     * The default constructor for NPC
     */
    NPC();

    /**
     * A constructor for NPC class. 
     * @param[in] n the name of the NPC to be created
     */
    NPC(std::string n);

    /**
     * The destructor for NPC.
     */
    virtual ~NPC() {}

    /**
     * Set the description of the NPC
     * @param[in] d the description of the NPC to be set
     */
    virtual void setDescription(std::string d);

    /**
     * A response to the Exorcist when the NPC is talked to
     */
    virtual void response() = 0;

    /**
    * Buff a Character.
    * @returns c a pointer to the Character to buff.
    */
    virtual void buff(Character* c) = 0;

 protected:
    std::string description;
};

#endif // NPC_H
