#include <iostream>
#include "Position.h"

// constructor for Position object
Position::Position(float xVal, float yVal)
{
	// set x and y values to corresponding xVal and yVal
	x = xVal;
	y = yVal;
}
// destructor for Position object
Position::~Position() {}
// output coordinate "(x,y)"
void Position::outputPosition() const
{
	std::cout << "(" << x << "," << y << ")";
}
// overloaded + operator (adding two coordinates (x1,y1) + (x2,y2) = (x3,y3)
Position Position::operator+(const Position& other) const
{
	// return new Position object of the form ((x1 + x2), (y1 + y2))
	return Position(x + other.x, y + other.y);
}
// overloaded = operator 
Position Position::operator=(const Position& other)
{
	// copy values from other object
	x = other.x;
	y = other.y;
	// return current object
	return *this;
}

