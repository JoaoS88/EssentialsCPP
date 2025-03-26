#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"

// game class, controls the game actions and contains player and enemies
// has player of type Player and enemies vector of type Enemy
class Game
{
	private:
		// member variables
		Player m_player;
		std::vector<Enemy> m_enemies;

	public:
		// constructor
		Game(Player& player, std::vector<Enemy>& enemies);
		// destructor
		//~Game();
		// functions
		void run();

};