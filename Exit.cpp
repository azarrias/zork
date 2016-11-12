#include "Exit.h"

Exit::Exit(const string& name, const string& description, const Direction& direction, 
	Room* sourceRoom, Room* destRoom)
	: Entity(name, description), direction(direction), source(sourceRoom), 
	destination(destRoom)
{}

Exit::~Exit()
{}

