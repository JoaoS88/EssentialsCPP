#include <iostream>
#include "Player.h"
#include "InventoryManager.h"
#include "Item.h"

// constructor that initializes player's name and assigns inventory manager instance
Player::Player(const std::string& playerName) : name(playerName)
{
    inventoryManager = InventoryManager::getInventoryManagerInstance(); // initialize with singleton instance
}
// function to add an item to the player's inventory
void Player::addItem(int id, std::unique_ptr<Item> item)
{
    // registering item using InventoryManager
    inventoryManager->registerItem(id, std::move(item));
    std::cout << "Player " << name << " added item with ID " << id << " to their inventory.\n";
}
// function to remove an item from the player's inventory
void Player::removeItem(int id)
{
    // removing item using InventoryManager
    inventoryManager->removeItem(id);
    std::cout << "Player " << name << " removed item with ID " << id << " from their inventory.\n";
}
// function to display the player's inventory
void Player::displayInventory() const
{
    // displaying items using InventoryManager
    inventoryManager->displayItems();
}
// function to find item in player's inventory by ID
const Item* Player::findItemById(int id) const
{
    // finding item using InventoryManager
    return inventoryManager->findItemById(id);
}
// function to use an item from player's inventory
void Player::useItem(int id)
{
    // attempt to find the item by its ID
    auto item = findItemById(id);

    if (item)
    {
        // if item found, use it and remove it from inventory
        std::cout << "Player " << name << " used item with ID " << id << ".\n";
        removeItem(id);  // remove the item after it is used
    }
    else
    {
        // if item not found, notify player
        std::cout << "Item with ID " << id << " not found in " << name << "'s inventory.\n";
    }
}
// function to get the player name
std::string Player::getName()
{
    // return the name
    return name;
}
