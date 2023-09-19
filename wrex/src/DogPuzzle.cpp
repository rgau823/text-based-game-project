/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 10, 2021
 */

#include <iostream>
#include <string>

#include "Display.h"
#include "DogCollar.h"
#include "DogPuzzle.h"
#include "UserInterface.h"
#include "Exorcist.h"

DogPuzzle::DogPuzzle() : PuzzleLevel() {
    path = "text/puzzle/dog_puzzle/";

    const std::string description =
    "Before you is a field with many different coloured flowers. "
    "There seems to be a small mound in the distance with a grave marker. "
    "There are paw prints that lead into and out of the field, almost as if "
    "some animal was wondering in a loop.";

    setDescription(description);
}

void DogPuzzle::puzzle() {
    bool status = isCleared();

    if (status) {
        display.open(path + "status.txt");
        return;
    }

    flowerField();
}

void DogPuzzle::flowerField() {
    display.open(path + "welcome.txt");
    Exorcist* exorcist = Level::getExorcist();

    while (!isCleared()) {
        display.open(path + "choice.txt");

        std::cout << "> ";
        char input = getUserInput();

        switch (input) {
            case 'R':
            case 'r': {
                setSolved(true);
                break;
            }
            case 'E':
            case 'e':
            case 'S':
            case 's': {
                display.open(path + "incorrect.txt");
                attempt = attempt - 1;
                break;
            }
            default: {
                display.open(path + "badinput.txt");
                attempt = attempt - 1;
                break;
            }
        }

        if (attempt == 0) {
            exorcist->setHealth(0);
            display.open(path + "dead.txt");
            return;
        }

        if (!isCleared()) {
            int damaged = exorcist->getHealth() / 2;
            exorcist->setHealth(damaged);

            std::cout << "You got damaged..." << std::endl;
            std::cout << "Exorcist HP : " << exorcist->getHealth() << std::endl;
        }
    }

    display.open(path + "exit.txt");
    addItem(new DogCollar);
}
