#include "World.h"
#include "Room.h"
#include "Player.h"

World::World() {
	Room* cellNo4 = new Room("Cell no. 4", "Starting room");
	Player* player = new Player("Hero", "Badass", cellNo4);
};

World::~World() 
{};