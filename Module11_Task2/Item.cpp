#include <iostream>
#include "Item.h"

//-----------------------------------------
// class item declarations:
//-----------------------------------------


// constructor
Item::Item(const std::string& name, const std::string& description, ItemType type, int stat)
	: name(name), description(description), type(type), stat(stat) {}
// deconstructor
Item::~Item() {}
// function to output the item details
void Item::outputItemDetails()
{
	std::cout << "Name: " << name
		<< "\nDescription: " << description
		<< "\n";
}
// function to get the item type
ItemType Item::getItemType()
{
	return type;
}
//
int Item::getStatChange()
{
	return 0;
}


//-----------------------------------------
// class weapon :: item declarations:
//-----------------------------------------


// constructor
Weapon::Weapon(const std::string& name, const std::string& description, int damage)
	: Item(name, description, ItemType::Weapon, damage), damage(damage) {}
// function to override getStatChange and return damage of weapon
int Weapon::getStatChange()
{
	return damage;
}
void Weapon::outputItemDetails()
{
	std::cout << "Name: " << name
		<< "\nDescription: " << description
		<< "\nDamage: " << stat << "\n";
}

//-----------------------------------------
// class armour :: item declarations:
//-----------------------------------------


// constructor
Armour::Armour(const std::string& name, const std::string& description, int defense)
	: Item(name, description, ItemType::Armour, defense), defense(defense) {}
// function to override getStatChange and return defense of armour
int Armour::getStatChange()
{
	return defense;
}
void Armour::outputItemDetails()
{
	std::cout << "Name: " << name
		<< "\nDescription: " << description
		<< "\nDefense: " << stat << "\n";
}

//-----------------------------------------
// class potion :: item declarations:
//-----------------------------------------


// constructor
Potion::Potion(const std::string& name, const std::string& description, int health)
	: Item(name, description, ItemType::Potion, health), health(health) {}
// function to override getStatChange and return health of potion
int Potion::getStatChange()
{
	return health;
}
void Potion::outputItemDetails()
{
	std::cout << "Name: " << name
		<< "\nDescription: " << description
		<< "\nHealing: " << stat << "\n";
}

//-----------------------------------------
// class unknown :: item declarations:
//-----------------------------------------


// contructor
Unknown::Unknown(const std::string& name, const std::string& description, int stat)
	: Item(name, description, ItemType::Unknown, stat) {}
// function to override getStatChange
int Unknown::getStatChange()
{
	return 0;
}



//-----------------------------------------