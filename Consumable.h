#ifndef _CONSUMABLE_H_
#define _CONSUMABLE_H_

#include "Item.h"

class Consumable : public Item {
public:
	Consumable(const string& name, const string& description, Room* initRoom,
		const unsigned char healDiceSides, const unsigned char healFixed);
	virtual ~Consumable();
	unsigned char healDiceSides;
	unsigned char healFixed;
	bool isDrink;	// For false values the consumable is food
};

#endif