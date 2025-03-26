#include <iostream>
#include <cmath>
#include <sstream>

struct coords { float x = 0, y = 0; };
double pointDistanceCalculator(coords point1, coords point2)
{
    return std::sqrt((std::pow((point2.x - point1.x), 2)) + std::pow((point2.y - point1.y), 2));

}
void pointDistance()
{
    coords point1, point2;
    std::string input;

    std::cout << "Input 2 coordinate points: (x1,y1);(x2,y2)" << std::endl;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    char ignore;
    ss >> ignore >> point1.x >> ignore >> point1.y >> ignore >> ignore
        >> ignore >> point2.x >> ignore >> point2.y >> ignore;

    double distance = pointDistanceCalculator(point1, point2);
    std::cout << "The distance between: (" << point1.x << ", " << point1.y
        << ") and (" << point2.x << ", " << point2.y
        << ") = " << distance << std::endl;

}

int main()
{
    pointDistance();
    return 0;
}
