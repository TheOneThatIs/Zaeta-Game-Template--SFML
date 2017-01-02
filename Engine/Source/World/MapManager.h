#pragma once

#include<vector>

#include"Tile.h"
#include"Tile.h"

class MapManager{
	std::vector< std::vector<int> > tiles;
	Tile tile;
	int height, width;
public:
	MapManager();
	~MapManager();

	void update();
	void drawMap();

	bool saveMap(std::string mapPath);
	bool loadMap(std::string mapPath);

	void printMap(std::string mapPath);
	void printMap();
	std::vector<std::vector<int>>* getMap();
};