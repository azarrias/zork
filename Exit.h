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
	bool isDoor;
	bool isOpenDoor;
	Exit(const Direction& direction, Room* sourceRoom, Room* destRoom, bool isDoor, 
		bool isOpen = false, const string& description="");
	virtual ~Exit();
	void setKey(Item* key);
	void updateDoorDescription();
};

#endif
