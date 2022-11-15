#include "Inventory.h"

#include <algorithm>

unsigned int Inventory::get_count_in_slot(int slot) const
{
    if (!is_valid_slot(slot)) return 0;

    return backpack[slot].count > -1 ? backpack[slot].count : 0;
}

std::optional<std::shared_ptr<InventoryItem>> Inventory::get_item_in_slot(int slot) const
{
    if (!is_valid_slot(slot)) return std::nullopt;

    if (backpack[slot].count == -1) return std::nullopt;

    return backpack[slot].item;
}

void Inventory::add_item_to_existing_slot(int slot, int count)
{
    if (!is_valid_slot(slot)) return;

    backpack[slot].count += count;
}

void Inventory::drop_item_from_existing_slot(int slot, int count)
{
    if (!is_valid_slot(slot)) return;

    // make life easier by not going below 0.
    backpack[slot].count = std::max(0, backpack[slot].count - count);

    // if we drop to 0, then we can clear the backpack slot.
    if (backpack[slot].count == 0)
    {
        backpack[slot].count = -1;
        backpack[slot].item = nullptr;
    }
}

bool Inventory::add_item(std::shared_ptr<InventoryItem> item, int count)
{
    for (int i = 0; i < Max_Slots; ++i)
    {
        if (backpack[i].count == -1)
        {
            backpack[i].item = item;
            backpack[i].count = count;
            return true;
        }
    }

    return false;
}

std::vector<InventorySlot> Inventory::get_all_items() const
{
    return backpack;
}

bool Inventory::is_valid_slot(int slot) const
{
    return (slot >= 0 && slot < Max_Slots);
}
