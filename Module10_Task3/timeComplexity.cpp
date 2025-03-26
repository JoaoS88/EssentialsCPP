#include <chrono>
#include "timeComplexity.h"
#include "Search.h"

//
void TimeComplexity::measureTime(Search* searchAlgo, int array[], int size, int searchKey)
{
    // record the start time
    auto start = std::chrono::high_resolution_clock::now();

    // Perform the search
    searchAlgo->search(array, size, searchKey);

    // Record the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Time taken: " << duration << " microseconds.\n";
}

