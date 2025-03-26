#include <iostream>
#include "linearSearch.h"

// function to preform linear search on array
void linearSearch::search(int arrayToSearch[], int sizeOfArray, int searchKey)
{
	outputArray(arrayToSearch, sizeOfArray);

	for (int i = 0; i < sizeOfArray; ++i)
	{
		std::cout << "Currently looking at index: " << i << ": " << arrayToSearch[i] << std::endl;

		if (arrayToSearch[i] == searchKey)
		{
			std::cout << "Search key was found at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Search key was not found." << std::endl;
}