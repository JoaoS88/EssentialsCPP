#include <iostream>

// function to output array
void outputArray(const int myArray[], const int sizeOfArray)
{
    // for easier readability
    std::cout << ">> ";
    // iterate through array
    for (int i = 0; i < sizeOfArray; i++)
    {
        // output with spaces between numbers
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
}
// function to bubble sort an array 
void bubbleSort(int arrayToSort[], const int sizeOfArray, const int AscendingOrDescending) // 1 = ascending ; -1 = descending
{
    std::cout << ">> Unsorted Array: " << std::endl;
    outputArray(arrayToSort, sizeOfArray);

    // pass number when doing bubble sort
    for (int passNumber = 0; passNumber < sizeOfArray - 1; passNumber++)
    {
        // output current pass number 
        std::cout << std::endl;
        std::cout << ">> Pass Number: " << passNumber + 1 << std::endl;
        // inner loop iterating through numbers
        for (int i = 0; i < sizeOfArray - 1 - passNumber; ++i)
        {
            // output current comparison
            std::cout << "--> Comparing: " << arrayToSort[i] << " and " << arrayToSort[i + 1] << std::endl;

            // swap condition depending on AscendingOrDescending value
            if ((AscendingOrDescending == 1 && arrayToSort[i] > arrayToSort[i + 1]   /*ascending*/) ||
                (AscendingOrDescending == -1 && arrayToSort[i] < arrayToSort[i + 1]) /*descending*/)
            {
                std::cout << arrayToSort[i] << " and " << arrayToSort[i + 1] << " need to be swapped." << std::endl;
                // creating temp variable to store value at position i
                int tempVar = arrayToSort[i];
                // setting value at position i to value at position i + 1
                arrayToSort[i] = arrayToSort[i + 1];
                // setting value at position i + 1 to the temp variable which had what was previously at position i
                arrayToSort[i + 1] = tempVar;
                // output array after swap
                std::cout << "--> After swap array looks like: " << std::endl;
                outputArray(arrayToSort, sizeOfArray);
            }
            else
            {
                // outputting what happens if no swap necessary
                std::cout << arrayToSort[i] << " and " << arrayToSort[i + 1] << " do not need swapping." << std::endl;
            }
        }
        // outputting result of after the pass
        std::cout << "After pass " << passNumber + 1 << ", array looks like: " << std::endl;
        outputArray(arrayToSort, sizeOfArray);
        std::cout << std::endl;
    }
    // outputting fully sorted array
    std::cout << "Array has been fully sorted..." << std::endl;
    std::cout << ">> Sorted Array: ";
    outputArray(arrayToSort, sizeOfArray);
}
int main()
{
    // declaring size of array as constant
    const int sizeOfArray = 5;
    // setting values of array
    int myArray[sizeOfArray] = { 10,2,91,7,52 };
    // calling bubble sort on our array
    bubbleSort(myArray, sizeOfArray, -1);

    return 0;
}