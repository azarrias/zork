#include "NPC.h"
#include "Room.h"

NPC::NPC(const string& name, const string& description, Room* initRoom, unsigned char hitPoints)
	: Creature(name, description, initRoom, hitPoints)
{
	type = NPCHAR;
	location->container.push_back(this);
}

NPC::~NPC()
{}
