#pragma once
#include "Search.h"

// linear search class that inherits from base class Search 
// implements the binary search algorithm
class linearSearch : public Search
{
public:
    // override search function from Search class
    void search(int array[], int size, int searchKey) override;
};
