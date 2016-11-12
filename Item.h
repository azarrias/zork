#ifndef _ITEM_H_
#define _ITEM_H_

#include "Entity.h"

class Item : public Entity {
	Item(const string& name, const string& description);
	virtual ~Item();
};

#endif