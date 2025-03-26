#include "Item.h"
#include <iostream>

// item constructor
Item::Item(std::string name, int healAmount)
	: m_name(name), m_healAmount(healAmount) {}

// item destructor
//Item::~Item()
//{
//	std::cout << m_name << " was destroyed!" << std::endl;
//}
// function to allow player to use an item to restore health
void Item::use(Player& player)
{
	std::cout << "Using " << m_name << ". Restored " << m_healAmount << " health." << std::endl;
	// using player take damage function to give health to player using "-" minus operator before damage
	player.takeDamage(- m_healAmount);
}
// getter functions
std::string Item::getName()
{
	// get item name
	return m_name;
}
