#include "ExorcistState.h"

#include <iostream>


SaneState::SaneState() : ExorcistState("Sane") {}

bool SaneState::attack(Enemy *e) {
    std::cout << "attack() in the SaneState()" << std::endl;
    return true;
}

bool SaneState::flee(Enemy *in) {
    std::cout << "flee() in the SaneState()" << std::endl;
    return true;
}



InjuredState::InjuredState() : ExorcistState("Injured") {}

bool InjuredState::attack(Enemy *e) {
    std::cout << "attack() in the InjuredState()" << std::endl;
    return true;
}

bool InjuredState::flee(Enemy *e) {
    std::cout << "flee() in the InjuredState()" << std::endl;
    return true;
}


PossessedState::PossessedState() : ExorcistState("Possessed") {}

bool PossessedState::attack(Enemy *e) {
    std::cout << "attack() in the PossessedState()" << std::endl;
    return true;
}

bool PossessedState::flee(Enemy *e) {
    std::cout << "flee() in the PossessedState()" << std::endl;
    return false;
}
