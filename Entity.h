#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <string>
#include <list>

using namespace std;

class Entity {
private:
	string name;
	string description;
	list<Entity*> contains;
public:
	Entity(const string& name, const string& description);
	virtual ~Entity();
	//virtual void display() const = 0;
	//virtual void update() = 0;
};

#endif