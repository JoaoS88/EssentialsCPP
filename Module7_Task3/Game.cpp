#include <iostream>
#include "Game.h"

// game constructor
Game::Game(Player& player, std::vector<Enemy>& enemies)
	: m_player(player), m_enemies(enemies) {}

// game destructor
//Game::~Game()
//{
//	std::cout << "Game ended, thanks for playing!" << std::endl;
//}
// function to run the game loop
void Game::run()
{
	// output welcome message and prompt for continuing from user
	std::cout << "Welcome to the Player v.s Enemies Game:" << std::endl;
	// prompt user to continue
	std::cout << "Press Enter to start..." << std::endl;
	std::cin.get(); 

	// game loop
	while (true)
	{
		// output player turn
		std::cout << "\n--- Player's Turn ---\n";
		// display info about player
		m_player.displayStats();
		m_player.displayInventory();
		// prompt for a choice from the player
		std::cout << "Choose an action:\n1. Attack\n2. Defend\n3. Use Item\n";
		int choice;
		std::cin >> choice;
		// switch case for the user input choice 1-3
		switch (choice)
		{
			// user picks 1
			case 1:
				// prompts user to pick an enemy to attack out of the available ones in the enemies vector
				std::cout << "Choose an enemy to attack:" << std::endl;
				// iterates through enemies vector
				for (size_t i = 0; i < m_enemies.size(); ++i) 
				{
					// checks if health of enemy in enemies vector is > 0 (theyre not dead already)
					if (m_enemies[i].getHealth() > 0) 
					{
						// outputs available enemies to choose from 
						std::cout << i + 1 << ". " 
							<< m_enemies[i].getName() << " (Health: " << m_enemies[i].getHealth() << ")" << std::endl;
					}
				}
				// take user input of which enemy they want to choose
				int enemyChoice;
				std::cin >> enemyChoice;
				// validate user choice
				if (enemyChoice >= 1 && enemyChoice <= m_enemies.size()) 
				{
					m_player.attackEnemy(m_enemies[enemyChoice - 1]);
				}
				// else output invalid choice
				else 
				{
					std::cout << "Invalid choice!" << std::endl;
				}
				break;

				// user picks 2
			case 2:
				// run player defend function to increase player defense, decreasing enemy attack
				m_player.defend();
				break;

				// user picks 3
			case 3:
				// display items in player inventory
				m_player.displayInventory();
				// prompt user to pick index of item they want to use
				std::cout << "Select an item to use:" << std::endl;
				int itemIndex;
				// call use function for the item the user picked
				std::cin >> itemIndex;
				m_player.useItem(itemIndex - 1);
				break;
		}

		// iterate through enemies vector
		for (auto& enemy : m_enemies) 
		{
			// validate enemy health is > 0 (theyre not dead already)
			if (enemy.getHealth() > 0) 
			{
				// if not dead then they attack player
				enemy.attackPlayer(m_player);
				// if player health goes to 0 or less, then player lost
				if (m_player.getHealth() <= 0) 
				{
					// output you have lost message
					std::cout << "You have fallen! Game Over!\n";
					// exit loop
					return;
				}
			}
		}

		bool allEnemiesDefeated = true;
		// checks enemies are dead or not
		for (auto& enemy : m_enemies) 
		{
			if (enemy.getHealth() > 0) 
			{
				allEnemiesDefeated = false;
				break;
			}
		}
		// if all enemies are dead 
		if (allEnemiesDefeated) 
		{
			// output message
			std::cout << "You have defeated all enemies! You win!\n";
			// exit
			return;
		}

	}

}
