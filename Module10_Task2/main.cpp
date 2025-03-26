#include <iostream>
#include "BinarySearch.h"
#include "LinearSearch.h"

int main()
{
    int myArray[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int searchKey = 70;

    // choosing the search algorithm
    Search* searchAlgo;

    // choosing binary search
    searchAlgo = new binarySearch();
    std::cout << "Running Binary Search...\n";
    searchAlgo->search(myArray, 10, searchKey);

    std::cout << std::endl;

    // choosing linear search
    searchAlgo = new linearSearch();
    std::cout << "Running Linear Search...\n";
    searchAlgo->search(myArray, 10, searchKey);

    std::cout << std::endl;

    delete searchAlgo;  // clean up dynamically allocated memory
    return 0;
}
