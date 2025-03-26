#pragma once
#include <string>

enum class ItemType
{
	Weapon,
	Armour,
	Potion,
	Unknown
};

class Item
{
protected:
	// member variables
	std::string name;
	std::string description;
	ItemType type;
	int stat;

public:
	// constructor
	Item(const std::string& name, const std::string& description, ItemType type, int stat);
	// destructor
	virtual ~Item();
	virtual void outputItemDetails();
	virtual int getStatChange();
	ItemType getItemType();
};

class Weapon : public Item
{
private:
	// member variables
	int damage;
public:
	// constructor
	Weapon(const std::string& name, const std::string& description, int damage);
	int getStatChange() override;
	void outputItemDetails() override;
};

class Armour : public Item
{
private:
	// member variables
	int defense;
public:
	// constructor
	Armour(const std::string& name, const std::string& description, int defense);
	int getStatChange() override;
	void outputItemDetails() override;
};

class Potion : public Item
{
private:
	// member variables
	int health;
public:
	// constructor
	Potion(const std::string& name, const std::string& description, int health);
	int getStatChange() override;
	void outputItemDetails() override;
};

class Unknown : public Item
{
public:
	// constructor
	Unknown(const std::string& name, const std::string& description, int stat);
	int getStatChange() override;
};