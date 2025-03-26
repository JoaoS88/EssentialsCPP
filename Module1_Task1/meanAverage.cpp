#include <iostream>

void meanAverage()
{
    int count;
    int sum = 0;
    int num;

    std::cout << "How many numbers do you want?" << std::endl;
    std::cin >> count;

    for (int i = 0; i < count; ++i)
    {
        std::cout << "Input number " << i + 1 << ":" << std::endl;
        std::cin >> num;
        sum += num;
    }

    // Make sure to cast either sum or count to float to ensure floating-point division
    std::cout << "The average of your numbers is: " << static_cast<float>(sum) / count << std::endl;
}

int main()
{
    meanAverage();
    return 0;
}