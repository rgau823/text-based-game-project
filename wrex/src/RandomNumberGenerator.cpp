#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator() {
    std::random_device device;
    mt.seed(device());
}

std::mt19937& RandomNumberGenerator::getEngine() {
    return mt;
}

bool getRandomBoolean(double p) {
    std::mt19937& mt = RandomNumberGenerator::getInstance().getEngine();
    std::bernoulli_distribution distribution(p);
    return distribution(mt);
}

int getRandomNumber(int x, int y) {
    std::mt19937& mt = RandomNumberGenerator::getInstance().getEngine();
    std::uniform_int_distribution<> distribution(x, y);
    return distribution(mt);
}
