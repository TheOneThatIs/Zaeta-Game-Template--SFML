#pragma once

#include"Tile.h"

class TileManager{
public:
	TileManager();
	~TileManager();

private:
	void update();
	void draw(const Tile &tile);

public:
	void lookUpID(int id);
};