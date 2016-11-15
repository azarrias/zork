#ifndef _EXIT_H_
#define _EXIT_H_

#include "Entity.h"
#include "globals.h"

using namespace std;

class Room;
class Item;

class Exit : public Entity {
public:
	Direction direction;
	Room* source;
	Room* destination;
	Item* key;
	Exit(const string& description, const Direction& direction, Room* sourceRoom, Room* destRoom);
	void setKey(Item* key);
	virtual ~Exit();
};

#endif
