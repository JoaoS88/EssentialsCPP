#pragma once
#include <string>
#include <iostream>

// enemy class, represents an enemy in the game
// has a name, health, attack and defense
// is able to attack and take damage
class Enemy
{
	private:
		// member variables
		std::string m_name;
		int m_health;
		int m_attack;
		int m_defense;

	public:
		// constructor
		Enemy(std::string name, int health = 80, int attack = 15, int defense = 8);
		// destructor
		//~Enemy();

		// battle functions
		void attackPlayer(class Player& player);
		void takeDamage(int damage);

		// getter functions
		int getHealth();
		std::string getName();
		int getDefense();


};