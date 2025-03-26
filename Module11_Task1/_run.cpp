#include <iostream>
#include "PlayerController.h"
#include "GameController.h"

int main()
{
    // memory leak detection
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // create a PlayerController object
    PlayerController* player = new PlayerController();
    // create GameController object, passing PlayerController to it
    GameController game(player);
    // run game loop
    game.run();
    // clean up PlayerController when game ends
    delete player;

    return 0;
}
