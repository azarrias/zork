#ifndef _WORLD_H_
#define _WORLD_H_

#include "globals.h"
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class Entity;
class Player;

class World {
private:
	unsigned int score;
	vector<Entity*> entities;
	Player* player;
	const time_t startTime;
public:
	World();
	~World();
	GameState parse(vector<string>& vect);
	void displayTime() const;
};

#endif
