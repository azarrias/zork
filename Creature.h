#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "Entity.h"

class Room;

class Creature : public Entity {
public:
	Room* location;
	Creature(const string& name, const string& description, Room* initRoom);
	virtual ~Creature();
};

#endif