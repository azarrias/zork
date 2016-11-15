#include "Container.h"

Container::Container(const string& name, const string& description, Room* initRoom)
	: Item(name, description, initRoom), isClosed(false)
{
	type = ITEM;
	category = CONTAINER;
}

Container::~Container()
{}
