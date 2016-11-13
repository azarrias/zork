#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <string>
#include <list>
#include "globals.h"

using namespace std;

enum EntityType
{
	ENTITY,
	CREATURE,
	EXIT,
	ROOM,
	ITEM,
	NPC,
	PLAYER
};

class Entity {
protected:
	string name;
	string description;
public:
	EntityType type;
	list<Entity*> container;
	Entity(const string& name, const string& description);
	virtual ~Entity();
	const string getName() const;
	const string getDescription() const;
	virtual void look() const;
	//virtual void display() const = 0;
	//virtual void update() = 0;
};

#endif