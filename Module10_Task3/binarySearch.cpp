#include <iostream>
#include "binarySearch.h"

void binarySearch::search(int arrayToSearch[], int sizeOfArray, int searchKey)
{
	outputArray(arrayToSearch, sizeOfArray);

	int low = 0;
	int high = sizeOfArray;

	// loop until low is greater than high
	while (low <= high)
	{
		// finding the middle of the array
		int middle = (low + high) / 2;
		std::cout << "Current Index is at " << middle << ", which is number:  " << arrayToSearch[middle] << std::endl;

		// if middle element matches search key, returns index
		if (searchKey == arrayToSearch[middle])
		{
			// output search key was found and at what index it was at and what it is
			std::cout << "Search Key was found at index: " << middle << " ==> " << arrayToSearch[middle] << std::endl;
			return;
		}
		// if search key < element at middle index
		else if (searchKey < arrayToSearch[middle])
		{
			std::cout << "Search Key: " << searchKey << " < " << arrayToSearch[middle] << std::endl;
			// search LOWER half of remaining array
			high = middle - 1;
		}
		// if search key > element at middle index
		else
		{
			std::cout << "Search Key: " << searchKey << " > " << arrayToSearch[middle] << std::endl;
			// search HIGHER half of remaining array
			low = middle + 1;
		}

	}
	// output key wasn't found
	std::cout << "Search Key was not found..." << std::endl;
}
