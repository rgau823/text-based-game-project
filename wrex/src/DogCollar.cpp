#include <iostream>
#include <string>

#include "DogCollar.h"
#include "Item.h"

DogCollar::DogCollar() {
    setIdentifier(Item::Identifier::DogCollar);
    setType(Item::Type::Core);

    const std::string description =
    "A ragged collar with a faded tag on it. "
    "You can barely make out an inscription \"Braggs\" on it";

    setDescription(description);
}

void DogCollar::use(Character *c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    std::cout << c->getName() << " is unable to use this." << std::endl;

    const std::string message =
    "The dog collar doesn't do anything. "
    "But perhaps it belongs somewhere else?";

    std::cout << message << std::endl;
}

std::string DogCollar::name() {
    return "Dog Collar";
}
