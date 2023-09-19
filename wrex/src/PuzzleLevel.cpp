#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "PuzzleLevel.h"

PuzzleLevel::PuzzleLevel() {
    Level::setName("Puzzle Level");
    Level::setType(Level::Puzzle);
    setSolved(false);
}

void PuzzleLevel::interact() {
    puzzle();
}

bool PuzzleLevel::isCleared() {
    return solved;
}

void PuzzleLevel::setSolved(bool s) {
    solved = s;
}
