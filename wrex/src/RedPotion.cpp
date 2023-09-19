#include <iostream>
#include <string>

#include "EndingPath.h"
#include "Exception.h"
#include "Item.h"
#include "RedPotion.h"

RedPotion::RedPotion() {
    setIdentifier(Item::Identifier::RedPotion);
    setType(Item::Type::Consumable);

    const std::string description =
    "A vial of red liquid. "
    "It's warm to the touch. "
    "Perhaps try drinking it?";

    setDescription(description);
}

void RedPotion::use(Character *c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    if (EndingPath::canDrinkPotion()) {
        EndingPath::drinkPotion();
        c->setHealth(c->getHealth() + 50);

        std::cout << "The potion restores the vitality of ";
        std::cout << c->getName() << " by 50 HP." << std::endl;
    } else {
        c->setHealth(0);

        std::cout << c->getName() << " drank the potion too much," << std::endl;
        std::cout << "which made " << c->getName();
        std::cout << " fell an eternal sleep..."<< std::endl;
    }
}

std::string RedPotion::name() {
    return "Red Potion";
}
