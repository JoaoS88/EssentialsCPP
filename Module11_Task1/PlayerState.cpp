#include <iostream>
#include <crtdbg.h>
#include "PlayerState.h"
#include "PlayerInputController.h"


// function to handle input
PlayerState* IdleState::handleInput(PlayerController* player, PlayerInputController* input)
{
    // switch statement to transition based on input
    switch (input->getInput())
    {
    case InputType::Walk:
        // transition to Walk state
        return new WalkState();
    case InputType::Run:
        // transition to Run state
        return new RunState();
    case InputType::Crouch:
        // transition to Crouch state
        return new CrouchState();
    case InputType::Jump:
        // transition to Jump state
        return new JumpState();
    default:
        // stay in Idle state if no transition happens
        return this;
    }
}
// idle state update function
void IdleState::Update(PlayerController& player)
{
    std::cout << "Player is Idle..." << std::endl;
    // idle logic...
}

// walk state
PlayerState* WalkState::handleInput(PlayerController* player, PlayerInputController* input)
{
    switch (input->getInput())
    {
    case InputType::Run:
        // transition to Run state
        return new RunState();
    case InputType::Crouch:
        // transition to Crouch state
        return new CrouchState();
    case InputType::Jump:
        // transition to Jump state
        return new JumpState();
    default:
        // stay in Walk state if no transition happens
        return this;
    }
}

void WalkState::Update(PlayerController& player)
{
    std::cout << "Player is Walking..." << std::endl;
    // walk logic...
}
// run state
PlayerState* RunState::handleInput(PlayerController* player, PlayerInputController* input)
{
    switch (input->getInput())
    {
    case InputType::Walk:
        // transition to Walk state
        return new WalkState();
        break;
    case InputType::Crouch:
        // transition to Crouch state
        return new CrouchState();
        break;
    case InputType::Jump:
        // transition to Jump state
        return new JumpState();
    default:
        // stay in Run state if no transition happens
        return this;
        break;
    }
}
// crouch state
PlayerState* CrouchState::handleInput(PlayerController* player, PlayerInputController* input)
{
    switch (input->getInput())
    {
    case InputType::Walk:
        return new WalkState();   // Transition to Walk state
    case InputType::Run:
        return new RunState();    // Transition to Run state
    case InputType::Jump:
        return new JumpState();   // Transition to Jump state
    default:
        return this;  // Stay in Crouch state if no transition happens
    }
}

void CrouchState::Update(PlayerController& player)
{
    std::cout << "Player is Crouching..." << std::endl;
    // crouching logic...
}

void RunState::Update(PlayerController& player)
{
    std::cout << "Player is Running..." << std::endl;
    // running logic...
}
// jump state
PlayerState* JumpState::handleInput(PlayerController* player, PlayerInputController* input)
{
    switch (input->getInput())
    {
    case InputType::Walk:
        // transition to Walk state
        return new WalkState();
        break;
    case InputType::Run:
        // transition to Run state
        return new RunState();
        break;
    case InputType::Crouch:
        // transition to Crouch state
        return new CrouchState();
        break;
    default:
        // stay in Jump state if no transition happens
        return this;
        break;
    }
}

void JumpState::Update(PlayerController& player)
{
    std::cout << "Player is Jumping..." << std::endl;
    // jumping logic...
}
