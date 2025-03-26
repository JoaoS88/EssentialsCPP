#include <iostream>
#include "Search.h"

void Search::outputArray(const int myArray[], const int sizeOfArray)
{
	// for easier readability
	std::cout << ">> ";
	// iterate through array
	for (int i = 0; i < sizeOfArray; i++)
	{
		// output with spaces between numbers
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
}