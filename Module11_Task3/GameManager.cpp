#include <string>
#include "GameManager.h"
#include "CharacterFactory.h"
#include "Character.h"

// constructor
GameManager::GameManager()
{
    characterFactory = new CharacterFactory();
}
// destructor
GameManager::~GameManager()
{
    delete characterFactory;
}
// function to run the game
void GameManager::run()
{
    std::cout << "Welcome to the RPG Character Creation System!" << std::endl;
    // game loop
    while (true)
    {
        // display menu
        displayMenu();
        int choice;
        // validate choice
        if (!validateInput(choice, "Enter your choice: ", 1, 3))
        {
            continue;
        }
        switch (choice)
        {
            // create characters
        case 1:
            createCharacter();
            break;
            // display characters
        case 2:
            displayCharacters();
            break;
            // exit game
        case 3:
            std::cout << "Exiting the game. Goodbye!" << std::endl;
            return;
            // invalid choice
        default:
            std::cout << "Invalid option. Try again." << std::endl;
        }
    }
}
// function to display menu
void GameManager::displayMenu() const
{
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Create a new character\n";
    std::cout << "2. View all characters\n";
    std::cout << "3. Exit\n";
}
// function to create new character
void GameManager::createCharacter()
{
    std::string name;
    std::cout << "Enter your character's name: ";
    // clear input buffer
    std::cin.ignore();
    // get whole line
    std::getline(std::cin, name);
    // create new character using factory
    auto newCharacter = characterFactory->createCharacter(name);
    // check if created character successfully
    if (newCharacter)
    {
        // if so output 
        std::cout << "\nCharacter Created Successfully!\n";
        // display new character info
        newCharacter->displayCharacterInfo();
        // add character to list
        characters.push_back(std::move(newCharacter));
    }
    else
    {
        // else output failed
        std::cout << "Failed to create character. Try again.\n";
    }
}
// function to display characters created
void GameManager::displayCharacters() const
{
    if (characters.empty())
    {
        std::cout << "\nNo characters created yet.\n";
        return;
    }

    std::cout << "\nAll Created Characters:\n";
    for (const auto& character : characters)
    {
        character->displayCharacterInfo();
        std::cout << "-------------------------\n";
    }

}
// function to validate user input
bool GameManager::validateInput(int& input, const std::string& prompt, int min, int max) const
{
    std::cout << prompt;
    std::cin >> input;

    if (std::cin.fail() || input < min || input > max)
    {
        // clear error state
        std::cin.clear();
        // discard invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        // invalid so return false
        return false;
    }
    // valid so return true
    return true;
}
