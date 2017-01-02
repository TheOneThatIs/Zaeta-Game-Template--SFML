#include "Tile.h"



Tile::Tile(){}


Tile::~Tile(){}


//Getters
int Tile::getWidth(){
	return width;
}
int Tile::getHeight(){
	return height;
}
bool Tile::isCollidable(){
	return collidable;
}
bool Tile::isTeleporter(){
	return teleporter;
}
bool Tile::isAnimated(){
	return animated;
}

void Tile::setProperties(int width, int height, bool isCollidable, bool isTeleporter, bool isAnimated, int id){
	this->width = width;
	this->height = height;
	collidable = isCollidable;
	teleporter = isTeleporter;
	animated = isAnimated;
	this->id = id;
}