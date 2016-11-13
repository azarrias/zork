#include "Exit.h"
#include "Room.h"

Exit::Exit(const Direction& direction, Room* sourceRoom, Room* destRoom)
	: Entity("", ""), direction(direction), source(sourceRoom), 
	destination(destRoom)
{ 
	type = EXIT;
	sourceRoom->container.push_back(this);
	destRoom->container.push_back(this);
}

Exit::~Exit()
{}

