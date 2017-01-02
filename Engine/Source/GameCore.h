#pragma once

#define TIME_STEP .03f

#include "Util\SpriteManager.h"
#include "States\StateManager.h"

using namespace sf;

class GameCore{
	int height, width;
	bool isfullscreen;

	SpriteManager spriteManager;
	StateManager manager;

public:
	GameCore();

	void init();
	void update ();
	void draw();
	void handleEvents ();
	void gameLoop ();
	void toggleFullscreen();
};