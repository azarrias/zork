#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include "NPC.h"
#include "globals.h"
#include "Weapon.h"
#include "Creature.h"
#include "Container.h"
#include "Item.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

World::World() 
	: startTime(time(NULL)) {

	Room* cellNo1 = new Room("Cell no. 1", "");
	Room* cellNo2 = new Room("Cell no. 2", "There is another security bed in the center of this room.\nThe following phrase is written repeatedly all over the walls:\nThere is a small mailbox here. But as a matter of fact you can't see any mailbox in here.");
	Room* cellNo3 = new Room("Cell no. 3", "TBD");
	Room* cellNo4 = new Room("Cell no. 4", "The appearance of the room where you woke up gives you the goosebumps.\nIt looks like you might be confined in a jailhouse or mental institution.\nWhy or how that happened is a mystery to you.\nThere is a security bed in the center of the room.\nIt seems as if its safety straps have been forced.\nDid you force them?");
	Room* cellNo5 = new Room("Cell no. 5", "TBD");
	Room* cellNo6 = new Room("Cell no. 6", "There are some mortal remains stacked up in a corner.\nSome of the bones don't look human.");
	Room* cellNo7 = new Room("Cell no. 7", "TBD");
	Room* cellNo8 = new Room("Cell no. 8", "TBD");

	entities.push_back(cellNo1);
	entities.push_back(cellNo2);
	entities.push_back(cellNo3);
	entities.push_back(cellNo4);
	entities.push_back(cellNo5);
	entities.push_back(cellNo6);
	entities.push_back(cellNo7);
	entities.push_back(cellNo8);

	Room* corridor1 = new Room("Corridor", "This end of the corridor has a small window to the outside.\nIt's made of tempered safety glass so you shouldn't dream about that as a route escape.");
	Room* corridor2 = new Room("Corridor", "TBD");
	Room* corridor3 = new Room("Corridor", "TBD");
	Room* corridor4 = new Room("Corridor", "TBD");

	entities.push_back(corridor1);
	entities.push_back(corridor2);
	entities.push_back(corridor3);
	entities.push_back(corridor4);

	Room* maintenanceRoom = new Room("Maintenance Room", "TBD");
	Room* staffRoom = new Room("Staff Room", "TBD");
	Room* securityCabin = new Room("Security Cabin", "TBD");

	entities.push_back(maintenanceRoom);
	entities.push_back(staffRoom);
	entities.push_back(securityCabin);

	Room* lobby = new Room("Lobby", "TBD");
	Room* hallway = new Room("Hallway", "TBD");
	Room* office = new Room("Office", "TBD");
	Room* entrance = new Room("Entrance", "TBD");
	Room* infirmary = new Room("Infirmary", "TBD");

	entities.push_back(lobby);
	entities.push_back(hallway);
	entities.push_back(office);
	entities.push_back(entrance);
	entities.push_back(infirmary);

	Room* secretChamber = new Room("Secret Chamber", "TBD");
	Room* darkPassage = new Room("Dark Passage", "TBD");
	Room* tunnel1 = new Room("Tunnel", "TBD");
	Room* tunnel2 = new Room("Tunnel", "TBD");
	Room* tunnel3 = new Room("Tunnel", "TBD");

	entities.push_back(secretChamber);
	entities.push_back(darkPassage);
	entities.push_back(tunnel1);
	entities.push_back(tunnel2);
	entities.push_back(tunnel3);

	Exit* cellNo1_Corridor = new Exit(Direction::S, cellNo1, corridor1, true);
	Exit* cellNo2_Corridor = new Exit(Direction::N, cellNo2, corridor1, true);
	Exit* cellNo3_Corridor = new Exit(Direction::S, cellNo3, corridor2, true);
	Exit* cellNo4_Corridor = new Exit(Direction::N, cellNo4, corridor2, true);
	Exit* cellNo5_Corridor = new Exit(Direction::S, cellNo5, corridor3, true);
	Exit* cellNo6_Corridor = new Exit(Direction::N, cellNo6, corridor3, true);
	Exit* cellNo7_Corridor = new Exit(Direction::S, cellNo7, corridor4, true);
	Exit* cellNo8_Corridor = new Exit(Direction::N, cellNo8, corridor4, true);

	entities.push_back(cellNo1_Corridor);
	entities.push_back(cellNo2_Corridor);
	entities.push_back(cellNo3_Corridor);
	entities.push_back(cellNo4_Corridor);
	entities.push_back(cellNo5_Corridor);
	entities.push_back(cellNo6_Corridor);
	entities.push_back(cellNo7_Corridor);
	entities.push_back(cellNo8_Corridor);

	Exit* corridor1_Corridor2 = new Exit(Direction::E, corridor1, corridor2, false);
	Exit* corridor2_Corridor3 = new Exit(Direction::E, corridor2, corridor3, false);
	Exit* corridor3_Corridor4 = new Exit(Direction::E, corridor3, corridor4, false);

	entities.push_back(corridor1_Corridor2);
	entities.push_back(corridor2_Corridor3);
	entities.push_back(corridor3_Corridor4);

	Exit* corridor4_security = new Exit(Direction::E, corridor4, securityCabin, true);
	Exit* security_maintenance = new Exit(Direction::N, securityCabin, maintenanceRoom, true);
	Exit* security_staff = new Exit(Direction::S, securityCabin, staffRoom, true);

	entities.push_back(corridor4_security);
	entities.push_back(security_maintenance);
	entities.push_back(security_staff);

	Exit* security_lobby = new Exit(Direction::E, securityCabin, lobby, true);
	Exit* lobby_hallway = new Exit(Direction::U, lobby, hallway, false, false, "There is a Spiral staircase that goes ");
	Exit* hallway_office = new Exit(Direction::N, hallway, office, true);
	Exit* lobby_entrance = new Exit(Direction::E, lobby, entrance, true);
	Exit* lobby_infirmary = new Exit(Direction::S, lobby, infirmary, true);

	entities.push_back(security_lobby);
	entities.push_back(lobby_hallway);
	entities.push_back(hallway_office);
	entities.push_back(lobby_entrance);
	entities.push_back(lobby_infirmary);

	Exit* infirmary_secret = new Exit(Direction::S, infirmary, secretChamber, true);
	Exit* secret_passage = new Exit(Direction::W, secretChamber, darkPassage, true);
	Exit* passage_tunnel1 = new Exit(Direction::W, darkPassage, tunnel1, true);
	Exit* tunnel1_tunnel2 = new Exit(Direction::W, tunnel1, tunnel2, false);
	Exit* tunnel2_tunnel3 = new Exit(Direction::W, tunnel2, tunnel3, false);

	entities.push_back(infirmary_secret);
	entities.push_back(secret_passage);
	entities.push_back(passage_tunnel1);
	entities.push_back(tunnel1_tunnel2);
	entities.push_back(tunnel2_tunnel3);

	player = new Player("PLAYER", "You have a face that only a mother could love.", cellNo4);
	NPC* ork = new NPC("ORK", "The ORK is staring at you with a scowl.", cellNo1, 5);

	entities.push_back(player);
	entities.push_back(ork);

	Weapon* axe = new Weapon("AXE", "The AXE edge looks sharp.", cellNo1, 6, 1);
	Weapon* copperDagger = new Weapon("DAGGER", "The DAGGER is made of copper.", cellNo4, 4, 1);

	entities.push_back(axe);
	entities.push_back(copperDagger);

	ork->take("AXE");
	ork->equip("AXE");

	Container* chest = new Container("CHEST", "The CHEST is quite big...you wonder if it will be full of treasures.", cellNo4);

	score = 0;
};

World::~World() 
{
	for (Entity* element : entities)
		delete element;

	entities.clear();
};

GameState World::parse(vector<string>& vect) {
	if (vect.size() == 0) return PLAY;
	// if present, discard the "optional" GO keyword
	if (vect.front().compare("GO") == 0)
		vect.erase(vect.begin());
	switch (vect.size()) {
		case 1:
		{
			if (vect.front().compare("Q") == 0 ||
				vect.front().compare("QUIT") == 0) {
				cout << stFgYellow << "Game closed.\n\n" << stBold << stFgBlue;
				return END;
			}
			else if (vect.front().compare("HELP") == 0) {
				// void displayHelp();
			}
			else if (vect.front().compare("INFO") == 0 ||
				vect.front().compare("ABOUT") == 0) {
				// void displayInfo();
			}
			else if (vect.front().compare("SAVE") == 0) {
				// void saveGame();
			}
			else if (vect.front().compare("RESTORE") == 0 ||
				vect.front().compare("LOAD") == 0) {
				// void loadGame();
			}
			else if (vect.front().compare("RESTART") == 0) {
				cout << stFgYellow << "Game restarted.\n\n" << stBold << stFgBlue;
				return START;
			}
			else if (vect.front().compare("L") == 0 ||
				vect.front().compare("LOOK") == 0) {
				player->look();
			}
			else if (vect.front().compare("SCORE") == 0) {
				cout << stFgYellow << "Your current score is " << score << ".\n";
				cout << stBold << stFgBlue;
			}
			else if (vect.front().compare("TIME") == 0) {
				cout << stFgYellow << "You have been playing this game for ";
				displayTime();
			}
			else if (vect.front().compare("STATUS") == 0 ||
				vect.front().compare("DIAGNOSE") == 0) {
				cout << stBold << stFgBlue << "You are " << player->getStatus() << ".\n";
			}
			else if (vect.front().compare("I") == 0 ||
				vect.front().compare("INVENTORY") == 0) {
				if (player->showInventory() == false) {
					cout << "You haven't got any items in your inventory.\n";
				}
			}
			else { // GO commands
				vector<string>::const_iterator it;
				it = find(validDirections.begin(), validDirections.cend(), vect.front());
				if (it != validDirections.cend()) {
					if(player->go(toDirection(vect.front())))
						player->look();
					else cout << stBold << stFgBlue << "There is no exit that way...\n";
				}
				else cout << stBold << stFgBlue << "That direction is invalid...\n";
			}
			break;
		}
		case 2:
		{
			if (vect.front().compare("TAKE") == 0 ||
				vect.front().compare("GET") == 0) {
				cout << stBold << stFgBlue;
				if (player->take(vect[1]))
					cout << "You take the " << vect[1] << ".\n";
				else cout << "You can't take that.\n";
			}
			if (vect.front().compare("DROP") == 0) {
				cout << stBold << stFgBlue;
				if (player->drop(vect[1]))
					cout << "You drop the " << vect[1] << " on the floor.\n";
				else cout << "You can't drop what you haven't got.\n";
			}
			if (vect.front().compare("EQUIP") == 0) {
				cout << stBold << stFgBlue;
				if (player->equip(vect[1])) 
					cout << "You equip the " << vect[1] << ".\n";
				else cout << "You can't equip that.\n";
			}
			if (vect.front().compare("ATTACK") == 0) {
				for (Entity* element : player->location->container) {
					if (element->type == NPCHAR && vect[1].compare(element->getName()) == 0) {
						player->attack((Creature*)element);
						if(((Creature*)element)->currentHitPoints > 0)
							((Creature*)element)->attack(player);
						break;
					}
				}
			}
			if (vect.front().compare("LOOK") == 0) {
				cout << stBold << stFgBlue;
				if (player->look(vect[1]) == false)
					cout << "What is it that you want to look?";
				cout << "\n";
			}
			break;
		}
		case 3:
		{
			if (vect.front().compare("PICK") == 0 &&
				vect[1].compare("UP") == 0) {
				cout << stBold << stFgBlue;
				if (player->take(vect[2]))
					cout << "You take the " << vect[2] << ".\n";
				else cout << "You can't take that.\n";
			}
			if (vect.front().compare("OPEN") == 0 && vect[2].compare("DOOR") == 0) {
				vector<string>::const_iterator it;
				it = find(validDirections.begin(), validDirections.cend(), vect[1]);
				if (it != validDirections.cend()) {
					if (player->open(toDirection(vect[1])))
						cout << "You open the " << vect[1] << " DOOR.\n";
					else cout << stBold << stFgBlue << "There is no door to be opened in that direction.\n";
				}
				else cout << stBold << stFgBlue << "That direction is invalid...\n";
			}
			if (vect.front().compare("CLOSE") == 0 && vect[2].compare("DOOR") == 0) {
				vector<string>::const_iterator it;
				it = find(validDirections.begin(), validDirections.cend(), vect[1]);
				if (it != validDirections.cend()) {
					if (player->close(toDirection(vect[1])))
						cout << "You close the " << vect[1] << " DOOR.\n";
					else cout << stBold << stFgBlue << "There is no door to be closed in that direction.\n";
				}
				else cout << stBold << stFgBlue << "That direction is invalid...\n";
			}
			break;
		}
		case 4:
		{
			if ((vect.front().compare("PUT") == 0 || vect.front().compare("DROP")) && 
				(vect[2].compare("IN") == 0 || vect[2].compare("INTO") == 0)) {
				cout << stBold << stFgBlue;
				if (player->put(vect[1], vect[3])) {
					cout << "You put the " << vect[1] << " in the " << vect[3] << ".\n";
				}
				else
					cout << "I'm afraid that's not possible.\n";
			}
			break;
		}
		default:
		{
			cout << stBold << stFgBlue << "I beg your pardon?\n";
		}
	}
	if (player->currentHitPoints <= 0) {
		cout << stFgYellow << "\nYou were playing this game for ";
		displayTime();
		cout << stFgYellow << "Your score was " << score << ".\n";
		cout << "Press ENTER key to restart...\n";
		cin.get();
		return START;
	}
	else return PLAY;
}

void World::displayTime() const {
	unsigned int seconds = (unsigned int)difftime(time(NULL), startTime);
	if (seconds >= 3600) {
		cout << seconds / 3600 << " hour(s) ";
	}
	if (seconds >= 60) {
		cout << seconds / 60 % 3600 << " minute(s) ";
	}
	cout << seconds % 60 << " seconds.\n";
}