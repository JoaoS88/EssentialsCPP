#include "Enemy.h"
#include "Player.h"
#include <iostream>

// enemy constructor
Enemy::Enemy(std::string name, int health, int attack, int defense)
	: m_name(name), m_health(health), m_attack(attack), m_defense(defense) {}
// can do constructor like this instead of a bunch of declarations and using = ;

// enemy destructor
//Enemy::~Enemy()
//{
//	std::cout << m_name << "has been destroyed." << std::endl;
//}
// function to allow enemy to attack the player
void Enemy::attackPlayer(Player& player)
{
	// set damage to enemy attack - player defense
	int damage = m_attack - player.getDefense();
	// check damage is not 0 or less
	if (damage > 0)
	{
		// make player take damage equal to the calculated damage value
		player.takeDamage(damage);
		// output message about attack
		std::cout << m_name << " attacks " << player.getName() << " for " << damage << " damage!" << std::endl;
	}
	// if damage is 0 or less
	else
	{
		// output message about attack
		std::cout << m_name << "'s attack was ineffective! " << std::endl;
	}
}
// function to allow enemy to take damage from player
void Enemy::takeDamage(int damage)
{
	// check if health is > 0
	if (m_health > 0)
	{
		// if so reduce health 
		m_health = m_health - damage;
		// outpout message for taking damage
		std::cout << m_name << " takes " << damage << " damage. Health: " << m_health << std::endl;
	}
	else
	{
		// else set health to 0 so doesnt go -ive
		m_health = 0;
	}
}
// getter functions
int Enemy::getHealth()
{
	// get enemy health
	return m_health;
}
std::string Enemy::getName()
{
	// get enemy name
	return m_name;
}
int Enemy::getDefense()
{
	// get enemy defense
	return m_defense;
}
