/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date November 21, 2021
 */

#include <iostream>
#include <string>

#include "Display.h"
#include "SoldierPendant.h"
#include "SoldierPuzzle.h"
#include "UserInterface.h"
#include "Exorcist.h"

SoldierPuzzle::SoldierPuzzle() : PuzzleLevel() {
    path = "text/puzzle/soldier_puzzle/";

    const std::string description =
    "A battle is taking place on a field up ahead. As you're watching you "
    "realize that when someone is struck down, they stand back up to keep "
    "fighting. They are not even soldiers, just shadowy figures fighting for "
    "eternity. The sounds of battle is deafening.";

    setDescription(description);
}

void SoldierPuzzle::puzzle() {
    bool status = isCleared();

    if (status) {
        display.open(path + "status.txt");
        return;
    }

    battlefield();
}

void SoldierPuzzle::battlefield() {
    display.open(path + "welcome.txt");
    Exorcist* exorcist = Level::getExorcist();

    while (!isCleared()) {
        display.open(path + "choice.txt");

        std::cout << "> ";
        char input = getUserInput();

        switch (input) {
            case 'Q':
            case 'q':
                setSolved(true);
                break;
            case 'G':
            case 'g':
                display.open(path + "gruff.txt");
                attempt = attempt -1;
                break;
            case 'T':
            case 't':
                display.open(path + "twisted.txt");
                attempt = attempt - 1;
                break;
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
            display.open(path + "damaged.txt");
            int damaged = exorcist->getHealth() / 2;
            exorcist->setHealth(damaged);
        }
    }

    display.open(path + "exit.txt");
    addItem(new SoldierPendant);
}
