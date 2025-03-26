#include <iostream>
#include "Appearance.h"

// parameterized constructor
Appearance::Appearance(std::string hc, std::string hl, std::string ec, std::string et, std::string ft, float h)
	: hairColour(hc), hairLength(hl), eyeColour(ec), eyeType(et), faceType(ft), height(h) {}
// default constructor
Appearance::Appearance()
{
	hairColour = "default";
	hairLength = "default";
	eyeColour = "default";
	eyeType = "default";
	faceType = "default";
	height = 150;
}
// function to display appearance
void Appearance::displayAppearance() const
{
	std::cout << "Hair Color: " << hairColour << "\nHair Length: " << hairLength
		<< "\nEye Color: " << eyeColour << "\nEye Type: " << eyeType
		<< "\nFace Type: " << faceType << "\nHeight: " << height << " meters\n";
}
