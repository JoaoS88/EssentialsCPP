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

// function to sum two random numbers
inline int SumOfRange(unsigned short int randomnum1, unsigned short int randomnum2)
{
    return randomnum1 + randomnum2;
}

// function to check if a number is even (true) or odd (false)
inline bool IsOddOrEven(unsigned short int randomnumsum)
{
    return randomnumsum % 2 == 0; // Returns true if even, false if odd
}

int main()
{
    // generate two random numbers
    unsigned short int randomnum1 = GenerateRandomNum();
    unsigned short int randomnum2 = GenerateRandomNum();

    // calculate the sum of the two random numbers
    unsigned short int randomnumsum = SumOfRange(randomnum1, randomnum2);

    // outputs sum of two random numbers
    std::cout << "The sum of " << randomnum1 << " and " << randomnum2 << " is " << randomnumsum << std::endl;

    // check if the sum is even or odd
    if (IsOddOrEven(randomnumsum))
    {
        std::cout << "The number " << randomnumsum << " is Even" << std::endl;
    }
    else
    {
        std::cout << "The number " << randomnumsum << " is Odd" << std::endl;
    }

    return 0;
}
