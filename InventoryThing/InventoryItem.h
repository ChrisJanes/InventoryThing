#pragma once

#include <string>

class InventoryItem
{
public:
	InventoryItem(std::string _name) : name{ _name } {}
	std::string get_name() const { return name; }

private:
	std::string name;
};