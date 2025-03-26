#pragma once
#include <string>
#include <memory>

class InventoryManager;
class Item;

class Player
{
private:
    // memeber vairables 
    std::string name;                       // player name
    InventoryManager* inventoryManager;     // reference to singleton class

public:
    // constructor
    Player(const std::string& playerName);
    void addItem(int id, std::unique_ptr<Item> item);  // add item to player inventory
    void removeItem(int id);                           // remove item from player inventory
    void displayInventory() const;                     // display player inventory
    const Item* findItemById(int id) const;            // find item in player inventory
    void useItem(int id);                              // use an item
    std::string getName();                             // get the player name
};