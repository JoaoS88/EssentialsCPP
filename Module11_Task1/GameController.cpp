#include <iostream>
#include <crtdbg.h>

#include "PlayerController.h"
#include "GameController.h"
#include "PlayerInputController.h"


// constructor initialises playerController and inputController
GameController::GameController(PlayerController* player)
    : playerController(player), inputController()   // Initialize playerController with passed player
{}
// function displays menu for user, allows choosing different actions
void GameController::showMenu()
{
    std::cout << "Choose an action:\n";
    std::cout << "1. Walk\n";
    std::cout << "2. Run\n";
    std::cout << "3. Crouch\n";
    std::cout << "4. Jump\n";
    std::cout << "5. Exit\n";
}
// function to check player input and update inputController with state 
void GameController::processInput()
{
    int choice;
    // handling invalid input
    while (!(std::cin >> choice))
    {
        std::cout << "Invalid input! Please enter a number between 1 and 5: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // switch case for setting state based on input
    switch (choice)
    {
    case 1:
        // set to walking
        inputController.setInput(InputType::Walk);
        break;
    case 2:
        // set to running
        inputController.setInput(InputType::Run);
        break;
    case 3:
        // set to crouching
        inputController.setInput(InputType::Crouch);
        break;
    case 4:
        // set to jumping
        inputController.setInput(InputType::Jump);
        break;
    case 5:
        // exit game
        std::cout << "Exiting game.\n";
        exit(0);
    default:
        // handle invalid menu choices
        inputController.setInput(InputType::None);
        break;
    }
    // passing inputController to PlayerController to handle input
    playerController->handleInput(&inputController);
}
// starts game loop to show meny and process input and update state
void GameController::run()
{
    // game loop
    while (true)
    {
        // show action menu to player
        showMenu();
        // get and process player's input                  
        processInput();
        // update player's state after input             
        playerController->Update();
    }
}
