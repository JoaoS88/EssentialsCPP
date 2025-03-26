#include <iostream>
#include "Attributes.h"

// parameterized constructor
Attributes::Attributes(int h, int a, int d, std::string sa)
	: health(h), attack(a), defense(d), specialAbility(sa) {}
// default constructor
Attributes::Attributes()
{
	health = 100;
	attack = 10;
	defense = 10;
	specialAbility = "Nothing";
}
// function to display attributes
void Attributes::displayAttributes() const
{
	std::cout << "Health: " << health << "\nAttack: " << attack << "\nDefense: " << defense
		<< "\nSpecial Ability: " << specialAbility << std::endl;
}
