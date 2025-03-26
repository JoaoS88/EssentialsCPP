#pragma once
#include <vector>
#include <memory>
#include<iostream>

class Character;
class CharacterFactory;

class GameManager
{
private:
	// member variables
	std::vector<std::unique_ptr<Character>> characters; // store all created characters
	CharacterFactory* characterFactory;                 // handles character creation

public:
	// constructor
	GameManager();
	// destructor
	~GameManager();
	// game loop 
	void run();
	// displays menu
	void displayMenu() const;
	// allows player to create character
	void createCharacter();
	// displays created players
	void displayCharacters() const;
	// validates player input
	bool validateInput(int& input, const std::string& prompt, int min, int max) const;
};
