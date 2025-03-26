#pragma once

class TimeComplexity; // forward declaration to make the TimeComplexity class a friend

// search class - base class containing pure virtual search function
class Search
{
    // making TimeComplexity a friend class
    friend class TimeComplexity;

public:
    virtual void search(int array[], int size, int searchKey) = 0;  // pure virtual 
    void outputArray(const int array[], const int size);
};