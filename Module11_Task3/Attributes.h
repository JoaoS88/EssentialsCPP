#pragma once
#include <string>

class Attributes
{
private:
	// member variables
	int health;						// character health
	int attack;						// character attack
	int defense;					// character defense
	std::string specialAbility;		// character special ability

public:
	// parameterized constructor
	Attributes(int h, int a, int d, std::string sa);
	// default constructor
	Attributes();
	// displays character attributes
	void displayAttributes() const;

};