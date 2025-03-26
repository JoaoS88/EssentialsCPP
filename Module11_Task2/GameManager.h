#pragma once
#include <string>
#include <memory>
#include <map>

class Player;
class Item;

class GameManager
{
private:
    // player pointer
    Player* player;
    // map to store registered items
    std::map<int, std::unique_ptr<Item>> registeredItems;

public:
    // constructor
    GameManager(const std::string& playerName);
    // destructor
    ~GameManager();

    void startGame();                                               // start the game loop              
    void showInventory() const;                                     // show inventory
    void addItemToInventory(int id, std::unique_ptr<Item> item);    // add item to inventory with id
    void removeItemFromInventory(int id);                           // remove item from inventory with id
    void useItemFromInventory(int id);                              // use item from inventory with id
    void registerItemToGame(int id, std::unique_ptr<Item> item);    // register item to the game
    void showRegisteredItems() const;                               // display registered items
    void displayMenu();                                             // display the main action menu

    // Actions
    void handleAddItemToInventory();                                // handle adding an item to inventory
    void handleRemoveItemFromInventory();                           // handle removing an item from inventory
    void handleUseItemFromInventory();                              // handle using an item from inventory
    void handleRegisterItem();                                      // handle registering a new item
    void handleShowRegisteredItems();                               // handle displaying registered items
    void handlePlayerAction();                                      // handle player action in game
};
