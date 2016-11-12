#ifndef _EXIT_H_
#define _EXIT_H_

#include "Entity.h"
#include "globals.h"

using namespace std;

class Room;

class Exit : public Entity {
public:
	Direction direction;
	Room* source;
	Room* destination;
	Exit(const string& name, const string& description, const Direction& direction,
		Room* sourceRoom, Room* destRoom);
	virtual ~Exit();
};

#endif
