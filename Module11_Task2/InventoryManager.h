#pragma once
#include <map>
#include <memory>
#include <unordered_map>

class Item;

class InventoryManager
{
private:

	// static pointer to single instance
	static InventoryManager* instance;
	// map to store items by Id
	std::unordered_map<int, std::unique_ptr<Item>> items;
	// private constructor - only instantialise inside context of class
	InventoryManager();

public:
	// public accessor - check if instance null , if so creates instance otherwise returns it
	static InventoryManager* getInventoryManagerInstance();
	void registerItem(int id, std::unique_ptr<Item> item);		// registers item, adding it to item map with unique id
	void removeItem(int id);									// removes an item from items map by id
	void displayItems() const;									// displays all items stored in items map
	const Item* findItemById(int id) const;						// searches for item in items map by its id and returns pointer to it
};