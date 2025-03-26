#include <crtdbg.h>
#include "PlayerInputController.h"

// function to set current input
void PlayerInputController::setInput(InputType input)
{
	currentInput = input;
}
// function to get current input
InputType PlayerInputController::getInput() const
{
	// return input
	return currentInput;
}
