#include <iostream>
#include <string>

#include "Item.h"

Item::Identifier Item::getIdentifier() {
    return identifier;
}

Item::Type Item::getType() {
    return type;
}

void Item::setIdentifier(Item::Identifier i) {
    identifier = i;
}

void Item::setType(Item::Type t) {
    type = t;
}

void Item::setDescription(std::string d) {
    description = d;
}

void Item::examine() {
    std::cout << description << std::endl;
}

