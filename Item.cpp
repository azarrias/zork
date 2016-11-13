#include "Item.h"
#include "Room.h"

Item::Item(const string& name, const string& description, Room* initRoom)
	: Entity(name, description), location(initRoom)
{
	type = ITEM;
	location->container.push_back(this);
}

Item::~Item()
{}
