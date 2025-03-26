#include "Player.h"

// player constructor
Player::Player(std::string name, int health, int attack, int defense, std::vector<Item>& inventory)
	: m_name(name), m_health(health), m_attack(attack), m_defense(defense), m_inventory(inventory) {}

// player destructor
//Player::~Player()
//{
//	std::cout << m_name << "was destroyed!" << std::endl;
//}
// function to allow player to attack enemy
void Player::attackEnemy(Enemy& enemy)
{
	// same functionality as enemy attacking player function
	int damage = m_attack - enemy.getDefense();
	if (damage > 0)
	{
		enemy.takeDamage(damage);
		std::cout << m_name << " attacks " << enemy.getName() << " for " << damage << " damage!" << std::endl;
	}
	else
	{
		std::cout << m_name << "'s attack was ineffective!" << std::endl;
	}
}
// function to allow player to defend
void Player::defend()
{
	// output defending message
	std::cout << m_name << " is defending, reducing damage from the next attack." << std::endl;
	// increase defense temporarily
	m_defense += 5;
}
// function to allow player to take damage
void Player::takeDamage(int damage)
{
	// same functionality as enemy taking damage
	if (m_health > 0)
	{
		m_health = m_health - damage;
		std::cout << m_name << " takes " << damage << " damage. Health: " << m_health << std::endl;
	}
	else
	{
		m_health = 0;
	}
}
// function to allow player to use an item by index
void Player::useItem(int itemIndex)
{
	// validate choice of index
	if (itemIndex >= 0 && itemIndex < m_inventory.size()) 
	{
		// use item using index
		m_inventory[itemIndex].use(*this);
		// remove item used from inventory
		m_inventory.erase(m_inventory.begin() + itemIndex);
	}
	else 
	{
		// else output invalid message
		std::cout << "Invalid item selection!" << std::endl;
	}
}
// function to allow displaying player stats
void Player::displayStats()
{
	std::cout << "Player: " << m_name    << " | "
		      << "Health: " << m_health  << " | "
		      << "Attack: " << m_attack  << " | "
		      << "Defense: " << m_defense << std::endl;
}
// function to allow player to add item to their inventory
void Player::addItem(Item& item)
{
	// push item to back of vector
	m_inventory.push_back(item);
}
// function to allow displaying the contents of the inventory vector for the player
void Player::displayInventory()
{
	// output inventory
	std::cout << "Inventory: " << std::endl;
	// iterate through inventory vector
	for (size_t i = 0; i < m_inventory.size(); ++i)
	{
		// output names with index for items
		std::cout << i + 1 << ". " << m_inventory[i].getName() << std::endl;
	}
}
// getter functions
int Player::getHealth()
{
	// get health of player
	return m_health;
}
std::string& Player::getName()
{
	// get name of player
	return m_name;
}
int Player::getDefense()
{
	// get defense of player
	return m_defense;
}
