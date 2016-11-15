#include "Exit.h"
#include "Room.h"

Exit::Exit(const string& description, const Direction& direction, Room* sourceRoom, Room* destRoom)
	: Entity("", description), direction(direction), source(sourceRoom), 
	destination(destRoom), key(nullptr)
{ 
	type = EXIT;
	sourceRoom->container.push_back(this);
	destRoom->container.push_back(this);
}

Exit::~Exit()
{}

void Exit::setKey(Item* keyItem) {
	this->key = keyItem;
}
