#include <crtdbg.h>
#include <iostream>

#include "PlayerController.h"
#include "PlayerState.h"

// constructor sets current state to idle state
PlayerController::PlayerController()
{
	currentState = new IdleState();
	std::cout << "Current state: " << currentState->getStateName() << std::endl;
}
// destructor
PlayerController::~PlayerController()
{
	// delete currentState object
	delete currentState;
}
// function that handles player input
void PlayerController::handleInput(PlayerInputController* input)
{
	// create state pointer
	PlayerState* newState = currentState->handleInput(this, input);
	//  checks if new state is the same as current state
	if (newState != currentState)
	{
		// deleting old state to prevent memory leak
		delete currentState;
		// setting current state to new state
		currentState = newState;
	}
}
// function to update state
void PlayerController::Update()
{
	// update current state
	currentState->Update(*this);
}