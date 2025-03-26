#include <random>
#include <iostream>

// function to generate a random number in the range [1, 100]
inline int GenerateRandomNum()
{
    static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist100(1, 100); // distribution in range [1, 100]

    return dist100(rng);
}

// function to check if a number is even (returns true for even, false for odd)
inline static bool IsOddOrEven(unsigned short int randomnum)
{
    return randomnum % 2 == 0; // Returns true if even, false if odd
}

int main()
{
    // generate a random number once
    int randomNum = GenerateRandomNum();

    // check if the number is even or odd
    if (IsOddOrEven(randomNum))
    {
        std::cout << "The number " << randomNum << " is Even" << std::endl;
    }
    else
    {
        std::cout << "The number " << randomNum << " is Odd" << std::endl;
    }

    return 0;
}
