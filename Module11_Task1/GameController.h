#pragma once
#include <iostream>
#include "PlayerInputController.h"

// forward declaration
class PlayerController;

// game controller class, responsible for processing input and running the game
class GameController
{
private:
    // member variables
    PlayerController* playerController;
    PlayerInputController inputController;

public:
    // constructor
    GameController(PlayerController* player);
    // function to display menu of options to player
    void showMenu();
    // function to process player input and transition states
    void processInput();
    // function for main loop
    void run();
};
