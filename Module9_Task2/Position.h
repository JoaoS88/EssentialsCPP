#pragma once
#include <iostream>

// forward declaration of PositionPrinter class
class PositionPrinter;

// class position, responsible for a position (x,y) coordinate
class Position
{
    // granting PositionPrinter class access to private members
    // using keyword "friend"
    friend class PositionPrinter;

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
