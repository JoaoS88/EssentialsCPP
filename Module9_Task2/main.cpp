#include <iostream>
#include "Position.h"
#include "PositionPrinter.h"

int main()
{
    // create Position object
    Position P1(5, 10);

    // create PositionPrinter object
    PositionPrinter printer;

    // use PositionPrinter to print Position's private members
    printer.printPosition(P1);

    return 0;
}
