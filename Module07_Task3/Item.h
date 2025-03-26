#pragma once
#include <iostream>
#include <string>
#include "Player.h"

// item class, allows implementation of healing items and inventory system
// items have names and amount they heal
// items can be used during the game to heal the player
class Item
{
	private:
		// member variables
		std::string m_name;
		int m_healAmount;

	public:
		// constructor
		Item(std::string name, int healAmount);
		// destructor
		//~Item();

		// functions
		void use(Player& player);
		// getter function
		std::string getName();

};