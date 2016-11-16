#include "Exit.h"
#include "Room.h"

Exit::Exit(const Direction& direction, Room* sourceRoom, Room* destRoom, bool isDoor, bool isOpen, 
	const string& description)
	: Entity("", description), isDoor(isDoor), isOpenDoor(isOpen), direction(direction), source(sourceRoom),
	destination(destRoom), key(nullptr)
{
	type = EXIT;
	sourceRoom->container.push_back(this);
	destRoom->container.push_back(this);
	if (description.compare("") == 0) {
		if (isDoor == true) {
			updateDoorDescription();
		}
		else
			this->description = "There's an open path to the ";
	}
}

Exit::~Exit()
{}

void Exit::setKey(Item* keyItem) {
	this->key = keyItem;
}

void Exit::updateDoorDescription() {
	string openDoorStr = "An open door ";
	string closedDoorStr = "A closed door ";
	this->description = ((this->isOpenDoor) ? openDoorStr : closedDoorStr) + "leads to the ";
}