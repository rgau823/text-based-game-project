#include <fstream>
#include <iostream>
#include <string>

#include "Display.h"

void Display::open(const std::string& filename) {
    std::ifstream file;
    file.open(filename);

    if (!file) {
        std::cout << "Unable to open file." << std::endl;
        return;
    }

    std::string input;

    while (getline(file, input))
        std::cout << input << std::endl;

    std::cout << std::endl;
    file.close();
}
