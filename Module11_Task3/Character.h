#pragma once
#include <string>

// forward declaration
class Appearance;
class Attributes;

// race of character
enum class Race
{
	Human,
	Elf,
	Dwarf,
	Orc,
	Fairy
};
// class of character
enum class Class
{
	Warrior,
	Mage,
	Archer
};
class Character
{
private:
	//member variables
	std::string name;					// character name
	Race race;							// character race
	Class characterClass;				// character class
	Appearance* characterAppearance;	// character appearance
	Attributes* characterAttributes;	// character attributes

public:
	// defualt constructor
	Character();
	// parameterized constructor
	Character(const std::string& n, Race r, Class c, Appearance* ap = nullptr, Attributes* atr = nullptr);
	// destructor
	~Character();
	// convert race to string
	std::string raceToString(Race r);
	// convert class to string
	std::string classToString(Class c);
	// displays all characteristics 
	void displayCharacterInfo();
};