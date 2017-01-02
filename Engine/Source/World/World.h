#pragma once
#include"Map.h"

class World{
	Map currentMap;
	Map yourHouse;
public:
	World();
	World(Map currentMap);
	~World();
};