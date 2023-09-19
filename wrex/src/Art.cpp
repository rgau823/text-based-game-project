#include <fstream>
#include <iostream>
#include <string>

#include "Art.h"

void Art::dinosaur() {
    display.open("ascii/intro.txt");
    ui.pressAnykey();
}

void Art::logo() {
    display.open("ascii/logo.txt");
    ui.pressAnykey();
}

void Art::gameover() {
    display.open("ascii/gameover.txt");
}

void Art::stage(int i) {
    i = i + 1;

    std::cout << std::endl;

    switch (i) {
        case 1: {
            display.open("ascii/first.txt");
            break;
        }

        case 2: {
            display.open("ascii/second.txt");
            break;
        }

        case 3: {
            display.open("ascii/third.txt");
            break;
        }

        case 4: {
            display.open("ascii/final.txt");
            break;
        }
    }

    display.open("ascii/stage.txt");
    std::cout << std::endl;

    ui.pressAnykey();
}

void Art::introduction() {
    const std::string directories = "text/introduction/";
    const std::string filename = "part_";
    const std::string extension = ".txt";

    const std::string skip =
    "== Enter [S] to skip the introduction... ==";

    for (int i = 1; i < 4; i++) {
        std::string number = std::to_string(i);

        std::string path(directories + filename + number + extension);
        display.open(path);

        std::cout << skip << std::endl;
        char input = ui.pressAnykey();

        if (input == 's' || input == 'S') return;
    }
}

void Art::trueEnding() {
    display.open("text/ending/trueEnding.txt");
    display.open("ascii/true.txt");
}

void Art::neutralEnding() {
    display.open("text/ending/neutralEnding.txt");
    display.open("ascii/neutral.txt");
}

void Art::badEnding() {
    display.open("text/ending/badEnding.txt");
    display.open("ascii/bad.txt");
}
