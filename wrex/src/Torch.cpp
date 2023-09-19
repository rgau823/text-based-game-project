/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 05, 2021
 */

#include <iostream>
#include <string>

#include "Torch.h"
#include "Item.h"

Torch::Torch() {
    setIdentifier(Item::Identifier::Torch);
    setType(Item::Type::Core);

    const std::string description =
    "A torch with the flame of your conviction";

    setDescription(description);
}

void Torch::use(Character *c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    std::cout << c->getName() << " is unable to use this." << std::endl;

    const std::string message =
    "You feel it is not the right time to use this.";

    std::cout << message << std::endl;
}

std::string Torch::name() {
    return "The Torch";
}
