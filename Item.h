#ifndef _ITEM_H_
#define _ITEM_H_

#include "Entity.h"

class Room;

enum ItemCategory
{
	WEAPON,
	DRINK,
	FOOD,
	CONTAINER
};

class Item : public Entity {
public:
	Item(const string& name, const string& description, Room* initRoom);
	virtual ~Item();
	ItemCategory category;
	Room* location;
};

#endif