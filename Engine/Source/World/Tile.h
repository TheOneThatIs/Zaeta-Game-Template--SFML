#pragma once

#include"World\Tiles\AllTiles.h"
#include"..\Util\SpriteManager.h"

class Tile{
protected:
	SpriteManager spriteManager;
	int width, height;
	bool collidable;
	bool teleporter;
	bool animated;
	int id;
public:
	Tile();
	~Tile();


	//Getters
	int getWidth();
	int getHeight();
	bool isCollidable();
	bool isTeleporter();
	bool isAnimated();

	//Setters
	void setProperties(int width, int height, bool isCollidable, bool isTeleporter, bool isAnimated, int id);
};