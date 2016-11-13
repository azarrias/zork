#ifndef _WORLD_H_
#define _WORLD_H_

#include "globals.h"
#include <vector>
#include <string>

using namespace std;

class Entity;
class Player;

class World {
private:
	unsigned int score;
	vector<Entity*> entities;
	Player* player;
public:
	World();
	~World();
	GameState parse(vector<string>& vect);
};

#endif
