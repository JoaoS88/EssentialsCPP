#include <iostream>

// function to increment the value of 'i' by 1 
inline int IncrementByOne(unsigned short int& i)
{
    return i++; // the value of 'i' is incremented
}

// function to multiply the value of 'i' by 2
inline int MultiplyByTwo(unsigned short int& i)
{
    return i * 2; // multiplies the value of 'i' by 2 and returns the result.
}

// function to increment the value of 'i' by 4
inline int IncrementByFour(unsigned short int& i)
{
    return i += 4; // adds 4 to 'i' and returns the new value of 'i'.
}

// function to divide the value of 'i' by 2
inline int DivideByTwo(unsigned short int& i)
{
    return i / 2; // divides the value of 'i' by 2 and returns the result.
}

// function to subtract the original value of 'i' (stored in 'placeholder') from the current value of 'i'
int SubtractOriginalNumber(unsigned short int& i, const int& placeholder)
{
    return i - placeholder; // subtracts the original number from the current value of 'i'.
}

int main()
{
    unsigned short int num; 
    // prompt for user input.
    std::cout << "Enter a integer between 1 and 20: "; 
    std::cin >> num; 
    // store the original value of 'num' in 'placeholder'.
    const unsigned short int placeholder = num; 

    // perform various operations on 'num' and modify it through reference.
    IncrementByOne(num); 
    MultiplyByTwo(num); 
    IncrementByFour(num); 
    DivideByTwo(num); 

    std::cout << "Result is: " << SubtractOriginalNumber(num, placeholder) << std::endl;

    return 0; 
}
