#pragma once

#include<SFML\Graphics.hpp>
#include "SpriteManager.h"

using namespace sf;

class Animation{
private:
	SpriteManager spriteManager;
	sf::Sprite spritesheet;
	
	IntRect srcRect;
	IntRect frame;
	int interval;
	int currentTime, pollFrequency;
	int numFrames;
	bool isLooped, isAnimationFinished;

public:
	Animation::Animation();

	/* 
			***BUG***
	Must have at leat 3 frames
	**/
	Animation(String filePath, IntRect srcRect, int currentTime, int numFrames);
	~Animation();

	void draw(RenderWindow *window, int x, int y);
	void setLoop(bool isLooped);
	void update();
};