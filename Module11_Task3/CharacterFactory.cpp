#include <iostream>
#include "CharacterFactory.h"
#include "Character.h"
#include "Attributes.h"
#include "Appearance.h"


std::unique_ptr<Character> CharacterFactory::createCharacter(std::string name)
{
    int raceInput, classInput;

    // prompt user for race and class
    std::cout << " Select Race: 1. Human 2. Elf 3. Dwarf 4. Orc 5. Fairy: ";
    std::cin >> raceInput;
    // convert 
    Race race = static_cast<Race>(raceInput - 1);

    std::cout << "Select Class: 1. Warrior 2. Mage 3. Archer: ";
    std::cin >> classInput;
    // convert 
    Class characterClass = static_cast<Class>(classInput - 1);

    // prompt for customized stats
    int health, attack, defense;
    std::cout << "Enter health: ";
    std::cin >> health;
    std::cout << "Enter attack: ";
    std::cin >> attack;
    std::cout << "Enter defense: ";
    std::cin >> defense;

    std::string specialAbility;
    std::cout << "Enter special ability: ";
    // clear buffer
    std::cin.ignore();
    // get whole line
    std::getline(std::cin, specialAbility);

    // prompt for physical appearance customization
    std::string hairColor, hairLength, eyeColor, eyeType, faceType;
    float height;
    std::cout << "Enter hair color: ";
    std::getline(std::cin, hairColor);
    std::cout << "Enter hair length: ";
    std::getline(std::cin, hairLength);
    std::cout << "Enter eye color: ";
    std::getline(std::cin, eyeColor);
    std::cout << "Enter eye type: ";
    std::getline(std::cin, eyeType);
    std::cout << "Enter face type: ";
    std::getline(std::cin, faceType);
    std::cout << "Enter height (in meters): ";
    std::cin >> height;

    // create appearance and attributes pointers
    Appearance* appearance = new Appearance(hairColor, hairLength, eyeColor, eyeType, faceType, height);
    Attributes* attributes = new Attributes(health, attack, defense, specialAbility);

    // create character based on custom customization
    return std::make_unique<Character>(name, race, characterClass, appearance, attributes);
}
