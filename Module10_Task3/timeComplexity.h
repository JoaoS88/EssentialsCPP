#include <iostream>
#include <chrono>

class Search;  // forward declaration to allow friendship with Search class

class TimeComplexity
{
public:
    static void measureTime(Search* searchAlgo, int array[], int size, int searchKey);
};
