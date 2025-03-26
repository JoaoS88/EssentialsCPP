#include "Character.h"
#include "Appearance.h"
#include "Attributes.h"
#include <iostream>

// default constructor
Character::Character()
    : name("Unnamed"), race(Race::Human), characterClass(Class::Warrior),
    characterAppearance(new Appearance()), characterAttributes(new Attributes()) {}
// parameterized constructor
Character::Character(const std::string& n, Race r, Class c, Appearance* ap, Attributes* atr)
    : name(n), race(r), characterClass(c), characterAppearance(ap), characterAttributes(atr)
{
    // ensure appearance and attributes are not null
    if (!characterAppearance)
    {
        // allocate default if null
        characterAppearance = new Appearance();
    }
    if (!characterAttributes)
    {
        // allocate default if null
        characterAttributes = new Attributes();
    }
}
// destructor
Character::~Character()
{
    delete characterAppearance;
    delete characterAttributes;
}
// utility to convert Race to string
std::string Character::raceToString(Race r)
{
    switch (r)
    {
    case Race::Human: return "Human";
    case Race::Elf: return "Elf";
    case Race::Dwarf: return "Dwarf";
    case Race::Orc: return "Orc";
    case Race::Fairy: return "Fairy";
    default: return "Unknown";
    }
}
// utility to convert Class to string
std::string Character::classToString(Class c)
{
    switch (c)
    {
    case Class::Warrior: return "Warrior";
    case Class::Mage: return "Mage";
    case Class::Archer: return "Archer";
    default: return "Unknown";
    }
}
// display character details
void Character::displayCharacterInfo()
{
    std::cout << "Character Name: " << name << "\n";
    std::cout << "Race: " << raceToString(race) << "\n";
    std::cout << "Class: " << classToString(characterClass) << "\n";
    if (characterAppearance)
    {
        std::cout << "Appearance:\n";
        characterAppearance->displayAppearance();
    }
    if (characterAttributes)
    {
        std::cout << "Attributes:\n";
        characterAttributes->displayAttributes();
    }
}
