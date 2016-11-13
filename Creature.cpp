#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* initRoom)
	: Entity(name, description), location(initRoom)
{
	type = CREATURE;
}

Creature::~Creature()
{}
