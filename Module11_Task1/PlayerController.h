class PlayerState;
class PlayerInputController;

// player controller class, responsible for handling player input and updating current state
class PlayerController
{
private:
    // member variables
    PlayerState* currentState;

public:
    // constructor
    PlayerController();
    // destructor
    ~PlayerController();
    // function to handle player input and transition between states
    void handleInput(PlayerInputController* input);
    // function to update current state
    void Update();
};
