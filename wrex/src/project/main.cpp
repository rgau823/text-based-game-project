#include "Game.h"

#include <iostream>
#include <string>


int main() {
    Game* game = new Game();

    game->introduction();
    game->play();
    game->stop();

    delete game;
}
