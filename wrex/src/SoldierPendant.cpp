#include <iostream>
#include <string>

#include "Item.h"
#include "SoldierPendant.h"

SoldierPendant::SoldierPendant() {
    setIdentifier(Item::Identifier::SoldierPendant);
    setType(Item::Type::Core);

    const std::string description =
    "A dirty silver pendant. "
    "There are signs of care.";

    setDescription(description);
}

void SoldierPendant::use(Character *c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    std::cout << c->getName() << " is unable to use this." << std::endl;

    const std::string message =
    "A family portrait. A man in military uniform is "
    "There are signs of care."
    "sitting with a child in his lap. A beautiful "
    "woman stands behind them.";

    std::cout << message << std::endl;
}

std::string SoldierPendant::name() {
    return "Soldier Pendant";
}
