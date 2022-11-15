#include <iostream>

#include "Inventory.h"

int main()
{
	Inventory inventory;

	inventory.add_item(std::make_shared<InventoryItem>(InventoryItem("Sword")));
	inventory.add_item(std::make_shared<InventoryItem>(InventoryItem("Stick")), 60);

	std::cout << inventory.get_item_in_slot(0)->get()->get_name() << ' ' << inventory.get_count_in_slot(0) << '\n';

	inventory.add_item_to_existing_slot(0, 1);
	
	if (inventory.get_item_in_slot(0)) std::cout << inventory.get_item_in_slot(0)->get()->get_name() << ' ' << inventory.get_count_in_slot(0) << '\n';

	inventory.drop_item_from_existing_slot(0, 2);

	if (inventory.get_item_in_slot(0)) std::cout << inventory.get_item_in_slot(0)->get()->get_name() << ' ' << inventory.get_count_in_slot(0) << '\n';

	if (inventory.get_item_in_slot(1)) std::cout << inventory.get_item_in_slot(1)->get()->get_name() << ' ' << inventory.get_count_in_slot(1) << '\n';
	if (inventory.get_item_in_slot(2)) std::cout << inventory.get_item_in_slot(2)->get()->get_name() << ' ' << inventory.get_count_in_slot(2) << '\n';
}