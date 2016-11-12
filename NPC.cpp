#include "NPC.h"

NPC::NPC(const string& name, const string& description, Room* initRoom)
	: Creature(name, description, initRoom)
{}

NPC::~NPC()
{}
