#pragma once
#include <iostream>

// class position, responsible for a position (x,y) coordinate
class Position
{

private:
	// member variable
	float x, y;

public:
	// constructor
	Position(float xVal = 0, float yVal = 0);
	// destructor
	~Position();

	// output function
	void outputPosition() const;

	// operator overloads
	Position operator+(const Position& other) const; // overload +
	Position operator=(const Position& other); // overload =

};
