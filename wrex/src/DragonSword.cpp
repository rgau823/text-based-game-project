#include <iostream>
#include <string>

#include "DragonSword.h"
#include "Item.h"

DragonSword::DragonSword() {
    setIdentifier(Item::Identifier::DragonSword);
    setType(Item::Type::Core);

    const std::string description =
    "You had heard tales about this sword. It was apparently made from the "
    "fang of a great dragon and was used to slay many dragons after.";

    setDescription(description);
}

void DragonSword::use(Character *c) {
    if (c == nullptr)
        throw invalid_parameter_error("Character is a nullptr");

    std::cout << c->getName() << " is unable to use this." << std::endl;

    const std::string message =
    "A sword of a legendary hero. It's rusted now "
    "and can't be used. It seems to emanate cursed energy. "
    "It certainly feels wrong in your hands.";

    std::cout << message << std::endl;
}

std::string DragonSword::name() {
    return "Dragon Sword";
}
