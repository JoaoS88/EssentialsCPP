#pragma once

// search class - base class containing pure virtual search function
class Search
{
public:
    virtual void search(int array[], int size, int searchKey) = 0;  // pure virtual 
    void outputArray(const int array[], const int size);
};