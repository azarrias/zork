#ifndef _ROOM_H_
#define _ROOM_H_

#include "Entity.h"

class Room : public Entity {
public:
	Room(const string& name, const string& description);
	virtual ~Room();
};

#endif
