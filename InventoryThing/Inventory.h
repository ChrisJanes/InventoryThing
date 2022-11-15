#pragma once

#include <vector>
#include <memory>
#include <functional>
#include <optional>
#include "InventoryItem.h"

/*
Make an inventory system that has a max number of item slots, but some items can have multiples
- i.e. I have 1 longsword, but I might have 60 sticks 
  (but that only takes up one slot in the inventory)

could use an unordered_map, but equally, it's a fixed size thing, so a vector makes more sense in
terms of retrieval speed...
*/

struct InventorySlot
{
	std::shared_ptr<InventoryItem> item;
	int count{-1};
};


class Inventory
{
public:
	const int Max_Slots = 6;

	Inventory() : backpack(Max_Slots) {

	}

	// retrieve item count in slot
	unsigned int get_count_in_slot(int slot) const;
	// retrieve item in slot
	std::optional<std::shared_ptr<InventoryItem>> get_item_in_slot(int slot) const;

	// add item(s) to slot
	void add_item_to_existing_slot(int slot, int count = 1);
	// drop item(s) from slot
	void drop_item_from_existing_slot(int slot, int count = 1);

	// add item to inventory
	bool add_item(std::shared_ptr<InventoryItem> item, int count = 1);

	std::vector<InventorySlot> get_all_items() const;
private:
	bool is_valid_slot(int slot) const;

	std::vector<InventorySlot> backpack;
};

