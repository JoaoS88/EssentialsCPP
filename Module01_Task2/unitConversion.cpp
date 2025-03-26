#include <iostream>

void conversionOfInches()
{
    double length;
    std::cout << "Enter a length in inches: " << std::endl;
    std::cin >> length;
    std::cout << length << "inch => " << length / 12 << "ft" << std::endl;
    std::cout << length << "inch => " << length * 0.0254 << "m" << std::endl;
}

int main()
{
    conversionOfInches();
    return 0;
}
