#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Enemy.h"
#include "Item.h"

// player class, represents a player in the game
// has name, health, attack, defense (like enemy) and an inventory
// is able to attack, take damage, use item and defend
class Player
{
	private:
		// member variables
		std::string m_name;
		int m_health;
		int m_attack;
		int m_defense;
		std::vector<class Item> m_inventory;

	public:
		// constructor
		Player(std::string name, int health, int attack, int defense, std::vector<Item>& inventory);
		// destructor
		//~Player();

		// battle functions
		void attackEnemy(Enemy& enemy);
		void defend();
		void takeDamage(int damage);
		void useItem(int itemIndex);
		void displayStats();

		// inventory functions
		void addItem(Item& item);
		void displayInventory(); 

		// getter functions
		int getHealth();
		std::string& getName();	
		int getDefense();
};