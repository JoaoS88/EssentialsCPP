#include <iostream>
#include "InventoryManager.h"
#include "Item.h"

// defining InventoryManager instance
InventoryManager* InventoryManager::instance = nullptr;
// constructor 
InventoryManager::InventoryManager()
{
    // Initialize anything necessary for InventoryManager (e.g., the map for items)
    std::cout << "Inventory Manager created." << std::endl;
}
// function to get the instance of the inventory manager singleton
InventoryManager* InventoryManager::getInventoryManagerInstance()
{
    // check if the instance is null
    if (instance == nullptr)
    {
        // if null, create a new instance
        instance = new InventoryManager();
    }
    else
    {
        // if not null, return the existing instance
        return instance;
    }

}
// function to register an item in the inventory with a unique id
void InventoryManager::registerItem(int id, std::unique_ptr<Item> item)
{
    // add the item to the map and transfer ownership using std::move
    items[id] = std::move(item);
    std::cout << "Item with ID " << id << " registered successfully.\n";
}
// function to remove an item from the inventory by id
void InventoryManager::removeItem(int id)
{
    // find the item in the map by id
    auto it = items.find(id);
    // check if the item exists
    if (it != items.end())
    {
        // if found, erase the item from the map
        items.erase(it);
        std::cout << "Item with ID " << id << " removed successfully.\n";
    }
    else
    {
        // if not found, output a message
        std::cout << "Item with ID " << id << " was not found.\n";
    }
}
// function to display all items in the inventory
void InventoryManager::displayItems() const
{
    // check if the inventory is empty
    if (items.empty())
    {
        std::cout << "The inventory is empty.\n";
        return;
    }
    // if not empty, output all items
    std::cout << "Inventory Items:\n";
    // iterate through each item in the map
    for (const auto& pair : items)
    {
        // output the id of the item
        std::cout << "ID: " << pair.first << " | ";
        // output the details of the item
        pair.second->outputItemDetails();
        std::cout << "\n";
    }
}
// function to find an item in the inventory by id
const Item* InventoryManager::findItemById(int id) const
{
    // look for the item in the map by id
    auto it = items.find(id);
    // check if the item exists
    if (it != items.end())
    {
        // if found, return a pointer to the item
        return it->second.get();
    }
    // if not found, return nullptr
    return nullptr;
}
