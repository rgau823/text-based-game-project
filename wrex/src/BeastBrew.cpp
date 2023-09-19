#include <iostream>
#include <string>

#include "BeastBrew.h"
#include "Exception.h"

BeastBrew::BeastBrew() {
    setIdentifier(Item::Identifier::BeastBrew);
    setType(Item::Type::Consumable);

    const std::string description =
    "A tankard of mysterious green liquid. "
    "It has a mysterious logo on it. It seems "
    "to course with energy.";

    setDescription(description);
}

void BeastBrew::use(Character *c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    c->setModifier(c->getModifier() * 2);
}

std::string BeastBrew::name() {
    return "Beast Brew";
}
