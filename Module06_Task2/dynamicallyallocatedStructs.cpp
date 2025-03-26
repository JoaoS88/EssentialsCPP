#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Task2:

// struct for Car, contains make, model and year
struct Car
{
    std::string make;
    std::string model;
    int year;
};
// function to populate car object
void populateCar(Car* car)
{
    if (!car) { return; } // safety check - for null pointer

    std::cout << "Car model: ";
    std::cin >> car->model;
    std::cout << "Car make: ";
    std::cin >> car->make;
    std::cout << "Car year: ";
    std::cin >> car->year;
}
// function to output model, make, year of passed object person of type Car
void outputCar(Car* car)
{
    if (!car) { return; } // safety check - for null pointer

    std::cout << "Car model: " << car->model << std::endl;
    std::cout << "Car make: " << car->make << std::endl;
    std::cout << "Car year: " << car->year << std::endl;
    std::cout << std::endl;
}
// function that compares car a and car b years
bool compareCarsByYear(Car* a, Car* b)
{
    return (a->year < b->year);
}
// function that sorts cars by year in ascending order
inline void sortCars(std::vector<Car*>& cars)
{
    // sort using compareCarsByYear function and std::sort
    std::sort(cars.begin(), cars.end(), compareCarsByYear);
}
// function that deallocates memory
void clearMemory(std::vector<Car*>& cars)
{
    // iterate through vector cars for each object of type Car
    for (Car* car : cars)
    {
        // deallocate each car object present in vector cars
        delete car;
    }
    // clear the vector cars
    cars.clear();
}
int main()
{
    std::vector<Car*> cars;
    char choice;
    do
    {
        // dynamically allocate memory for car struct
        Car* car = new Car;
        // attempts to execute code
        try
        {
            // successfully created car object on heap
            std::cout << "Successfully created car object" << std::endl;
            populateCar(car);
            // add car to vector cars
            cars.push_back(car);

            // prompt user to add more cars
            std::cout << "Do you want to add another car? (y/n): ";
            std::cin >> choice;
        }
        // carch any exceptions thrown during execution
        catch (const std::exception& e)
        {
            // print out error message
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } while (choice == 'y' || choice == 'Y');

    std::cout << std::endl;
    std::cout << "The cars in ascending year order:" << std::endl;
    // sort cars by ascending year order 
    sortCars(cars);
    // output cars in order
    for (Car* car : cars)
    {
        outputCar(car);
    }
    std::cout << std::endl;

    // clear memory 
    clearMemory(cars);
    std::cout << "Successfully deleted all objects and cleared the vector." << std::endl;
    return 0;
}