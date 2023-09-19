#include <string>

#include "EndingPath.h"
#include "UserInterface.h"

void UserInterface::showNormalHelp() {
    std::cout << std::endl;
    display.open("text/help/normal/help.txt");
}

void UserInterface::showBattleHelp() {
    std::cout << std::endl;
    display.open("text/help/battle/help.txt");
}

void UserInterface::showNormalCommands() {
    display.open("text/menu/normal/menu.txt");

    std::cout << "Bosses saved: " << EndingPath::getSaved() << std::endl;
    std::cout << std::endl;

    std::cout << "Enter a command : ";
}

void UserInterface::showBattleCommands() {
    display.open("text/menu/battle/menu.txt");
    std::cout << "Enter a command : ";
}

void UserInterface::showStageCommands() {
    display.open("text/menu/stage/menu.txt");
}

char getUserInput() {
    std::string input;
    getline(std::cin, input);

    if (input.length() > 1) return -1;
    input = input.substr(0, 1);

    return input[0];
}

CommandType UserInterface::normalInput() {
    do {
        showNormalCommands();
        char input = getUserInput();
        std::cout << std::endl;

        switch (input) {
            case 'q':
            case 'Q':
                return QUIT;

            case 'n':
            case 'N':
                return NEXT_LEVEL;

            case 'p':
            case 'P':
                return PREVIOUS_LEVEL;

            case 't':
            case 'T':
                return TAKE;

            case 'a':
            case 'A':
                return TALK;

            case 'e':
            case 'E':
                return EXAMINE;

            case 'i':
            case 'I':
                return INTERACT;

            case 'f':
            case 'F':
                return FIGHT;

            case 'b':
            case 'B':
                return BACKPACK;

            case 'd':
            case 'D':
                return DROP;

            case 'u':
            case 'U':
                return USE;

            case 'h':
            case 'H':
                showNormalHelp();
                break;

            case 's':
            case 'S':
                return STAGE;

            default:
                std::cout << std::endl;
                std::cout << "Please input a valid option" << std::endl;
                break;
        }
    } while (true);

    return WRONG_COMMAND;
}

CommandType UserInterface::battleInput() {
    do {
        showBattleCommands();
        char input = getUserInput();
        std::cout << std::endl;

        switch (input) {
            case 'a':
            case 'A':
                return ATTACK;

            case 'u':
            case 'U':
                return USE;

            case 'g':
            case 'G':
                return GIFT;

            case 'f':
            case 'F':
                return FLEE;

            case 'i':
            case 'I':
                return INFO;

            case 'b':
            case 'B':
                return BACKPACK;

            case 'h':
            case 'H':
                showBattleHelp();
                break;

            default:
                std::cout << std::endl;
                std::cout << "Please input a valid option" << std::endl;
                break;
        }
    } while (true);

    return WRONG_COMMAND;
}

int UserInterface::numberCommand(int max) {
    do {
        std::cout << "(C)ancel, ";
        std::cout << "Choose a number! (from 1 to " << max << "): ";

        char input = getUserInput();
        std::cout << std::endl;

        switch (input) {
            case '1' ... '9': {
                int choice = input - '0';
                if (choice <= max) return choice - 1;

                std::cout << "Please input a valid option" << std::endl;
                break;
            }

            case 'c':
            case 'C':
                return CANCEL;
        }
    } while (true);

    return WRONG_COMMAND;
}

char UserInterface::pressAnykey() {
    std::cout << "== Press [Enter] to continue ==" << std::endl;
    return getUserInput();
}
