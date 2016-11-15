#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include "Item.h"

class Container : public Item {
public:
	Container(const string& name, const string& description, Room* initRoom);
	virtual ~Container();
	bool isClosed;
};

#endif