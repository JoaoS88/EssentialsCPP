#include "PositionPrinter.h"

void PositionPrinter::printPosition(const Position& pos) const
{
    std::cout << "Position: (" << pos.x << ", " << pos.y << ")" << std::endl;
}
