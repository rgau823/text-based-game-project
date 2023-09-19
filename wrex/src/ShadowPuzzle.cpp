/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 05, 2021
 */

#include <iostream>
#include <string>

#include "Display.h"
#include "Exorcist.h"
#include "ShadowPuzzle.h"
#include "Torch.h"
#include "UserInterface.h"

ShadowPuzzle::ShadowPuzzle() {
    path = "text/puzzle/shadow_puzzle/";

    const std::string description =
    "You see an empty void in front of you. It seems to sprawl "
    "endlessly. As you walk around you get the sinking suspicion "
    "that you are not moving anywhere.";

    setDescription(description);
}

void ShadowPuzzle::puzzle() {
    bool status = isCleared();

    if (status) {
        display.open(path + "status.txt");
        return;
    }

    theVoid();
}

void ShadowPuzzle::theVoid() {
    display.open(path + "welcome.txt");
    Exorcist* exorcist = Level::getExorcist();

    while (!isCleared()) {
        display.open(path + "choice.txt");

        std::cout << "> ";
        char input = getUserInput();

        switch (input) {
            case 'H':
            case 'h': {
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
    addItem(new Torch);
}
