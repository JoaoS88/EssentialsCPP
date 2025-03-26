#pragma once

// enum for Input Type
enum class InputType
{
    None,   // no input, idle
    Walk,   // walk input, walking
    Run,    // run input, running
    Crouch, // crouch input, crouching
    Jump    // jump input, jumping
};

// class player input controller, responsible for setting and retrieving player's input state
class PlayerInputController
{
private:
    // member variables
    InputType currentInput;

public:
    // function to set current input type
    void setInput(InputType input);
    // function to get current input type
    InputType getInput() const;
};
