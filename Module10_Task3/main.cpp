#include <iostream>
#include "BinarySearch.h"
#include "LinearSearch.h"
#include "TimeComplexity.h"

int main()
{
    // initial array to search
    int myArray[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int searchKey = 70;

    // create search object
    Search* searchAlgo;

    // running binary search on initial array
    searchAlgo = new binarySearch();
    std::cout << "Running Binary Search on array of size 10...\n";
    TimeComplexity::measureTime(searchAlgo, myArray, 10, searchKey);

    std::cout << std::endl;

    // running linear search on initial array
    searchAlgo = new linearSearch();
    std::cout << "Running Linear Search on array of size 10...\n";
    TimeComplexity::measureTime(searchAlgo, myArray, 10, searchKey);

    std::cout << std::endl;

    // doubling size of array
    int myArrayLong[20] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };

    // running binary search on array of size 20
    std::cout << "Running Binary Search on array of size 20...\n";
    TimeComplexity::measureTime(searchAlgo, myArrayLong, 20, searchKey);

    std::cout << std::endl;

    // running linear search on array of size 20
    searchAlgo = new linearSearch();
    std::cout << "Running Linear Search on array of size 20...\n";
    TimeComplexity::measureTime(searchAlgo, myArrayLong, 20, searchKey);

    std::cout << std::endl;

    // cleanup dynamically allocated memory
    delete searchAlgo;

    return 0;
}
