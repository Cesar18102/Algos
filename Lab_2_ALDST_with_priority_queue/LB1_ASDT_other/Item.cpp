#include "Item.h"

Item::Item(int value, int priority)
{
	Value = value;
	Priority = priority;
}

Item::Item()
{

}

bool Item::Equals(Item other)
{
	return other.Priority == Priority && other.Value == Value;
}