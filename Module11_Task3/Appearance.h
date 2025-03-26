#pragma once
#include <string>

class Appearance
{
private:
	// member variables
	std::string hairColour;		// character hair colour
	std::string hairLength;		// character hair length
	std::string eyeColour;		// character eye colour
	std::string eyeType;		// character eye type
	std::string faceType;		// character face type
	float height;				// character height

public:
	// parameterized constructor
	Appearance(std::string hc, std::string hl, std::string ec, std::string et, std::string ft, float h);
	// default constructor
	Appearance();
	// displays appearance of character
	void displayAppearance() const;
};