#pragma once
#include "Search.h"

// binary search class that inherits from base class Search 
// implements the binary search algorithm
class binarySearch : public Search
{
public:
    // override search function from Search class
    void search(int array[], int size, int searchKey) override;
};
