#pragma once
#include <string>
// forward declarations
class PlayerInputController;
class PlayerController;

// class player state, base class, responsible for creating different player states
class PlayerState
{
public:
	// destructor
	virtual ~PlayerState() = default;
	// pure virtual handle input function
	virtual PlayerState* handleInput(PlayerController* player, PlayerInputController* input) = 0;
	// pure virtual update function
	virtual void Update(PlayerController& player) = 0;
	virtual std::string getStateName() = 0;

};
// class for idle state inherits from player state, responsible for the idle state logic
class IdleState : public PlayerState
{
	// overriden function for handle input and update for idle state
	virtual PlayerState* handleInput(PlayerController* player, PlayerInputController* input) override;
	virtual void Update(PlayerController& player) override;
	std::string getStateName() override { return "Idle"; }

};
// class for walk state inherits from player state, responsible for the walk state logic
class WalkState : public PlayerState
{
	// overriden function for handle input and update for walk state
	virtual PlayerState* handleInput(PlayerController* player, PlayerInputController* input) override;
	virtual void Update(PlayerController& player) override;
	std::string getStateName() override { return "Walking"; }
};
// class for run state inherits from player state, responsible for the run state logic
class RunState : public PlayerState
{
	// overriden function for handle input and update for run state
	virtual PlayerState* handleInput(PlayerController* player, PlayerInputController* input) override;
	virtual void Update(PlayerController& player) override;
	std::string getStateName() override { return "Running"; }
};
// class for crouch state inherits from player state, responsible for the crouch state logic
class CrouchState : public PlayerState
{
	// overriden function for handle input and update for crouch state
	virtual PlayerState* handleInput(PlayerController* player, PlayerInputController* input) override;
	virtual void Update(PlayerController& player) override;
	std::string getStateName() override { return "Crouching"; }
};
// class for jump state inherits from player state, responsible for the jump state logic
class JumpState : public PlayerState
{
	// overriden function for handle input and update for jump state
	virtual PlayerState* handleInput(PlayerController* player, PlayerInputController* input) override;
	virtual void Update(PlayerController& player) override;
	std::string getStateName() override { return "Jumping"; }
};