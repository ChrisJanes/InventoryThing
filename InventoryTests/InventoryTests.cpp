#include "pch.h"
#include "CppUnitTest.h"

#include "../InventoryThing/Inventory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InventoryTests
{
	TEST_CLASS(InventoryTests)
	{
	public:
		const int Items_To_Add = 2;
		const int First_Slot = 0;
		const int High_Slot = 60;
		const int Low_Slot = -1;
		TEST_METHOD(GetSlotItemCountWithItem)
		{
			Inventory inv;
			inv.add_item(std::make_shared<InventoryItem>(InventoryItem("Sword")));

			Assert::AreEqual((int)inv.get_count_in_slot(First_Slot), 1);
		}

		TEST_METHOD(GetSlotItemCountWithoutItem)
		{
			Inventory inv;

			Assert::AreEqual((int)inv.get_count_in_slot(First_Slot), 0);
		}

		TEST_METHOD(GetSlotItemCountWithBadSlot)
		{
			Inventory inv;

			Assert::AreEqual((int)inv.get_count_in_slot(High_Slot), 0);
			Assert::AreEqual((int)inv.get_count_in_slot(Low_Slot), 0);
		}

		TEST_METHOD(GetSlotItemWithItem)
		{
			Inventory inv;
			inv.add_item(std::make_shared<InventoryItem>(InventoryItem("Sword")));

			auto res = inv.get_item_in_slot(First_Slot);
			Assert::IsTrue(res.has_value());
			Assert::AreEqual(res.value()->get_name(), std::string("Sword"));
		}

		TEST_METHOD(GetSlotItemWithoutItem)
		{
			Inventory inv;

			auto res = inv.get_item_in_slot(First_Slot);
			Assert::IsFalse(res.has_value());
		}

		TEST_METHOD(GetSlotItemWithBadSlot)
		{
			Inventory inv;

			auto res = inv.get_item_in_slot(High_Slot);
			Assert::IsFalse(res.has_value());

			res = inv.get_item_in_slot(Low_Slot);
			Assert::IsFalse(res.has_value());
		}

		TEST_METHOD(AddItemDefault)
		{
			Inventory inv;
			inv.add_item(std::make_shared<InventoryItem>(InventoryItem("Sword")));

			Assert::AreEqual((int)inv.get_count_in_slot(First_Slot), 1);
		}

		TEST_METHOD(AddItemWithCount)
		{
			
			Inventory inv;
			inv.add_item(std::make_shared<InventoryItem>(InventoryItem("Sword")), Items_To_Add);

			Assert::AreEqual((int)inv.get_count_in_slot(First_Slot), Items_To_Add);
		}

		TEST_METHOD(AddItemToExistingSlotDefault)
		{
			Inventory inv;
			inv.add_item(std::make_shared<InventoryItem>(InventoryItem("Sword")));

			inv.add_item_to_existing_slot(First_Slot);

			Assert::AreEqual((int)inv.get_count_in_slot(First_Slot), Items_To_Add);
		}

		TEST_METHOD(AddItemToExistingSlotWithCount)
		{
			Inventory inv;
			inv.add_item(std::make_shared<InventoryItem>(InventoryItem("Sword")));

			inv.add_item_to_existing_slot(First_Slot, Items_To_Add);

			Assert::AreEqual((int)inv.get_count_in_slot(First_Slot), Items_To_Add+1);
		}
	};
}
