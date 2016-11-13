#ifndef _NPC_H_
#define _NCP_H_

#include "Creature.h"

class NPC : public Creature {
public:
	NPC(const string& name, const string& description, Room* initRoom, unsigned char hitPoints);
	virtual ~NPC();
};

#endif