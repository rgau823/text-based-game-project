/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 05, 2021
 */


#ifndef TORCH_H
#define TORCH_H

#include <string>

#include "ShadowBoss.h"
#include "Item.h"

/**
 * The Torch is a core item.
 * It should be used on the Shadow Exorcist when it is in the Vengeful state.
 */

class Torch : public Item {
 public:
    /**
     * Default constructor for the Torch.
     * It sets the name and the description.
     */
    Torch();

    /**
     * The use method for the Torch.
     */
    virtual void use(Character* c);

    virtual std::string name();
};

#endif // Torch_H
