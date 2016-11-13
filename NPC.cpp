#include "NPC.h"

NPC::NPC(const string& name, const string& description, Room* initRoom, unsigned char hitPoints)
	: Creature(name, description, initRoom, hitPoints)
{
	type = EntityType::NPC;
}

NPC::~NPC()
{}
