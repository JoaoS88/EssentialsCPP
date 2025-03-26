#include <iostream>
#include <string>
//Task1: 

// struct for Person, contains name, age and height
struct Person
{
    std::string name;
    int age;
    float height; // in metres
};
// function to populate person object
inline void populatePerson(Person& person)
{
    std::cout << "Enter the name: " << std::endl;
    std::cin >> person.name;
    std::cout << "Enter the age: " << std::endl;
    std::cin >> person.age;
    std::cout << "Enter the height: " << std::endl;
    std::cin >> person.height;

}
// function to output name, age, height of passed object person of type Person
inline void outputPerson(Person& person)
{
    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Age: " << person.age << std::endl;
    std::cout << "Height: " << person.height << std::endl;
    std::cout << std::endl;
}

int main()
{
    // create instance of struct People, object person1
    Person person1;
    // call functions to populate and output struct info
    populatePerson(person1);
    outputPerson(person1);
    // create instance of struct People, object person2
    Person person2;
    // call functions to populate and output struct info
    populatePerson(person2);
    outputPerson(person2);

    // for more instances of objects:
    // using vector i.e) std::vector<Person> people;
    // then can push back people into vector, prompt if want to add more people
    // then iterate through vector outputting people information

}