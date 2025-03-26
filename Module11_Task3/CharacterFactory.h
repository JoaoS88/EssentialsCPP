#pragma once
#include <memory>
#include <string>

// forward declaration
class Character;

// character factory to assemble characters using user customization
class CharacterFactory
{
public:
	// factory method to create characters based on input
	std::unique_ptr<Character> createCharacter(std::string name);
};