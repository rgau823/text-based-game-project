#include <iostream>
#include <string>
#include <vector>

#include "NPC.h"

NPC::NPC() {};

NPC::NPC(std::string n) : Character(n) {}

void NPC::setDescription(std::string d) {
    description = d;
}
