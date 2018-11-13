#pragma once
class Item
{
	public: Item(int value, int priority);
			Item();
			bool Equals(Item other);
			int Value;
			int Priority;
};