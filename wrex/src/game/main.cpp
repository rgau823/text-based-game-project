#include "Enemy.h"
#include "Exorcist.h"

#include <string>


int main() {
    Exorcist* exorcist = new Exorcist();
    Enemy* enemy = new Enemy();

    exorcist->attack(enemy);
    enemy->attack(exorcist);

    delete exorcist;
    delete enemy;
}
