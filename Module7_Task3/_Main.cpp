#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include <vector>
#include <iostream>

// main is in charge of running the program
// create all objects here and run game loop
int main() 
{
    // create items
    Item healthPotion("Lesser Health Potion", 30);      // restores 30 health
    Item strengthElixir("Stronger Health Potion", 50);  // restores 50 health

    // create player's inventory
    std::vector<Item> playerInventory;

    // create the player
    Player player("Hero", 100, 20, 10, playerInventory);

    // add items to player's inventory
    player.addItem(healthPotion);
    player.addItem(strengthElixir);

    // create enemies
    Enemy goblin("Goblin", 80, 15, 8);
    Enemy orc("Orc", 100, 20, 10);

    // store enemies in vector
    std::vector<Enemy> enemies = { goblin, orc };

    // create and initialize the game
    Game game(player, enemies);

    // run game loop
    game.run();

    // output game eneded
    std::cout << "Game ended, thanks for playing!" << std::endl;

    return 0;
}