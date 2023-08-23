#include "EnemyState.h"

#include <iostream>


FriendlyState::FriendlyState() : EnemyState("Friendly") {}

bool FriendlyState::talk(Exorcist *e) {
    std::cout << "talk() in the FriendlyState()" << std::endl;
    return true;
}

bool FriendlyState::gift(Exorcist *in) {
    std::cout << "gift() in the FriendlyState()" << std::endl;
    return true;
}

bool FriendlyState::attack(Exorcist *e) {
    std::cout << "attack() in the FriendlyState()" << std::endl;
    return true;
}


HostileState::HostileState() : EnemyState("Hostile") {}

bool HostileState::talk(Exorcist *e) {
    std::cout << "talk() in the HostileState()" << std::endl;
    return true;
}

bool HostileState::gift(Exorcist *e) {
    std::cout << "gift() in the HostileState()" << std::endl;
    return true;
}

bool HostileState::attack(Exorcist *e) {
    std::cout << "attack() in the HostileState()" << std::endl;
    return true;
}


DeadState::DeadState() : EnemyState("Dead") {}

bool DeadState::talk(Exorcist *e) {
    std::cout << "talk() in the DeadState()" << std::endl;
    return true;
}

bool DeadState::gift(Exorcist *e) {
    std::cout << "talk() in the DeadState()" << std::endl;
    return true;
}

bool DeadState::attack(Exorcist *e) {
    std::cout << "talk() in the DeadState()" << std::endl;
    return true;
}
