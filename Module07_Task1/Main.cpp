#include "Person.h"
#include <iostream>
#include <string>

// using Pointers and Dynamically Allocated Memory
int main()
{
    Person* p_MyPerson = new Person; // heap-allocated
    int age = 0;
    std::string name = "";

    // prompt user to enter name of a person
    std::cout << "Enter the name of a person: ";
    // store user input in temp vatiable name

    // instead of std::cin << name  and if (name.empty()) 
    // cin >> reads until it finds whitespace, so if enter is pressed only
    // it wont store "" it will keep waiting for input so need to use std::getline()
    std::getline(std::cin, name); // read full line for name
    // validate input
    if (name.empty() || name.find_first_not_of(' ') == std::string::npos)
    {
        std::cout << "Enter a correct name!" << std::endl;
        delete p_MyPerson;
        return 1; // exit if input invalid
    }

    // prompt user to enter age of a person
    std::cout << "Enter the age of the person: ";
    // store user input in temp vatiable age
    std::cin >> age;
    // validate input 
    if (age <= 0)
    {
        std::cout << "Enter a correct age!" << std::endl;
        delete p_MyPerson;
        return 1; // exit if input invalid
    }

    // set object name and age using user input 
    // using dereferencing operator "->"
    p_MyPerson->setName(name);
    p_MyPerson->setAge(age);

    // output age and name using getter functions in class
    std::cout << "Person 1: " << std::endl
        << "Name: " << p_MyPerson->getName() << std::endl
        << "Age: " << p_MyPerson->getAge() << std::endl;

    // delete object
    delete p_MyPerson;
    // null the pointer
    p_MyPerson = nullptr;
    return 0;
}

//int main()
//{
//    Person myPerson; // stack-allocated 
//    int age = 0;
//    std::string name = "";
//
//    std::cout << "Enter the name of a person: ";
//    std::getline(std::cin, name); // read full line for name
//    if (name.empty() || name.find_first_not_of(' ') == std::string::npos)
//    {
//        std::cout << "Enter a correct name!" << std::endl;
//        return 1;
//    }
//
//    std::cout << "Enter the age of the person: ";
//    std::cin >> age;
//    if (age <= 0)
//    {
//        std::cout << "Enter a correct age!" << std::endl;
//        return 1;
//    }
//
//    myPerson.setName(name);
//    myPerson.setAge(age);
//
//    std::cout << "Person 1: " << std::endl
//        << "Name: " << myPerson.getName() << std::endl
//        << "Age: " << myPerson.getAge() << std::endl;
//
//    return 0; 
//}