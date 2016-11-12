#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>

class Entity;

class World {
private:
	std::vector<Entity*> entities;
public:
	World();
	~World();
};

#endif
