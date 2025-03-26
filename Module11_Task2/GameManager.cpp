#include <iostream>
#include <memory>
#include "GameManager.h"
#include "Item.h"
#include "Player.h"

// contructor
GameManager::GameManager(const std::string& playerName)
{
    player = new Player(playerName);
}
// destructor
GameManager::~GameManager()
{
    delete player;
}
// function to start the game (initialize anything necessary and start game loop)
void GameManager::startGame()
{
    std::cout << "Welcome to the Game, " << player->getName() << "!\n";
    handlePlayerAction();  // start processing player actions
}
// function to show player's current inventory
void GameManager::showInventory() const
{
    player->displayInventory();  // Delegate to Player class
}
// function to add item to player's inventory
void GameManager::addItemToInventory(int id, std::unique_ptr<Item> item)
{
    player->addItem(id, std::move(item));  // Delegate to Player class
}
// function to remove item from player's inventory
void GameManager::removeItemFromInventory(int id)
{
    player->removeItem(id);  // Delegate to Player class
}
// function to use item from player's inventory
void GameManager::useItemFromInventory(int id)
{
    player->useItem(id);  // Delegate to Player class
}
void GameManager::registerItemToGame(int id, std::unique_ptr<Item> item)
{
    // check if item id already exists
    if (registeredItems.find(id) != registeredItems.end())
    {
        std::cout << "Item ID " << id << " already exists. Registration failed.\n";
        return;
    }
    // else register item with new id
    registeredItems[id] = std::move(item);
    std::cout << "Item with ID " << id << " successfully registered to the game.\n";
}
// function to display registered items
void GameManager::showRegisteredItems() const
{
    // check if the inventory is empty
    if (registeredItems.empty())
    {
        std::cout << "No items registered in the game.\n";
        return;
    }
    // if not empty, output all items
    std::cout << "Registered Items:\n";
    for (const auto& pair : registeredItems)
    {
        // output the id of the item
        std::cout << "ID: " << pair.first << " | ";
        // output the details of the item
        pair.second->outputItemDetails();
        std::cout << "\n";
    }
}
// function for input validation (returns true if input is valid)
bool validateInput(int& input, const std::string& prompt, int min, int max)
{
    std::cout << prompt;
    if (!(std::cin >> input) || input < min || input > max)
    {
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}
// function to display the action menu
void GameManager::displayMenu()
{
    std::cout << "\nChoose an action:\n";
    std::cout << "\nPlayer Actions:\n";
    std::cout << "1. Show inventory\n";
    std::cout << "2. Add item to inventory\n";
    std::cout << "3. Remove item from inventory\n";
    std::cout << "4. Use item from inventory\n";
    std::cout << "5. Exit game\n";
    std::cout << "\nGame Actions:\n";
    std::cout << "6. Register a new item\n";
    std::cout << "7. Show registered items\n";
}
// handle adding an item to inventory
void GameManager::handleAddItemToInventory()
{
    showRegisteredItems();
    int id;
    std::cout << "Enter the ID of the item to add to inventory: ";
    if (!validateInput(id, "Item ID: ", 0, INT_MAX) || registeredItems.find(id) == registeredItems.end())
    {
        std::cout << "Invalid ID. Please select a registered item.\n";
        return;
    }

    // move the item from registered items to player inventory
    addItemToInventory(id, std::move(registeredItems[id]));
    registeredItems.erase(id);
}
// handle removing an item from inventory
void GameManager::handleRemoveItemFromInventory()
{
    showInventory();
    int id;
    std::cout << "Enter item ID to remove: ";
    if (!validateInput(id, "Item ID: ", 0, INT_MAX)) return;

    // remove item from inventory
    removeItemFromInventory(id);
}
// handle using an item from inventory
void GameManager::handleUseItemFromInventory()
{
    showInventory();
    int id;
    std::cout << "Enter item ID to use: ";
    if (!validateInput(id, "Item ID: ", 0, INT_MAX)) return;

    // use item from inventory
    useItemFromInventory(id);
}
// handle registering a new item to the game
void GameManager::handleRegisterItem()
{
    int id, type, stat;
    std::string name, description;

    // prompt for item id with validation
    std::cout << "Enter item ID: ";
    if (!validateInput(id, "Item ID: ", 0, INT_MAX)) return;

    // prompt for item type with validation
    std::cout << "Enter item type (1 for Weapon, 2 for Armour, 3 for Potion): ";
    if (!validateInput(type, "Item Type: ", 1, 3)) return;

    // clear newline for input of name and description
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter item name: ";
    std::getline(std::cin, name);
    std::cout << "Enter item description: ";
    std::getline(std::cin, description);

    // prompt for item stat with validation
    std::cout << "Enter item stat (damage for Weapon, defense for Armour, health for Potion): ";
    if (!validateInput(stat, "Item Stat: ", 0, INT_MAX)) return;

    // create appropriate item based on type
    std::unique_ptr<Item> item;
    if (type == 1)
        item = std::make_unique<Weapon>(name, description, stat);
    else if (type == 2)
        item = std::make_unique<Armour>(name, description, stat);
    else if (type == 3)
        item = std::make_unique<Potion>(name, description, stat);

    // register item to game's inventory
    registerItemToGame(id, std::move(item));
}
// handle showing registered items
void GameManager::handleShowRegisteredItems()
{
    showRegisteredItems();
}
// function to handle player's actions
void GameManager::handlePlayerAction()
{
    int action;
    while (true)
    {
        displayMenu();

        // validate menu action
        if (!validateInput(action, "Enter your choice: ", 1, 7)) continue;
        system("cls");

        switch (action)
        {
        case 1:
            showInventory();
            break;
        case 2:
            handleAddItemToInventory();
            break;
        case 3:
            handleRemoveItemFromInventory();
            break;
        case 4:
            handleUseItemFromInventory();
            break;
        case 5:
            std::cout << "Exiting game...\n";
            return;
        case 6:
            handleRegisterItem();
            break;
        case 7:
            handleShowRegisteredItems();
            break;
        default:
            std::cout << "Invalid action.\n";
            break;
        }
    }
}
