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
#include "DragonSword.h"
#include "DragonPuzzle.h"
#include "UserInterface.h"
#include "Exorcist.h"

DragonPuzzle::DragonPuzzle() : PuzzleLevel() {
    path = "text/puzzle/dragon_puzzle/";

    const std::string description =
    "A desolate valley of many felled dragons as far as you can see. Giant "
    "bones litter the wasteland. One giant skeleton sits in the middle of the "
    "valley. It seems to be missing something but you're not quite sure what."
    "The air is heavy with miasma, it is so thick you cannot breathe.";

    setDescription(description);
}

void DragonPuzzle::puzzle() {
    bool status = isCleared();

    if (status) {
        display.open(path + "status.txt");
        return;
    }

    boneyard();
}

void DragonPuzzle::boneyard() {
    display.open(path + "welcome.txt");
    Exorcist* exorcist = Level::getExorcist();

    while (!isCleared()) {
        display.open(path + "choice.txt");

        std::cout << "> ";
        char input = getUserInput();

        switch (input) {
            case 'F':
            case 'f':
                setSolved(true);
                break;
            case 'C':
            case 'c':
            case 'T':
            case 't': {
                display.open(path + "incorrect.txt");
                attempt = attempt -1;
                break;
            }
            default: {
                display.open(path + "badinput.txt");
                attempt = attempt -1;
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
    addItem(new DragonSword);
}
