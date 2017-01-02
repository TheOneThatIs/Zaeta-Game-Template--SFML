#pragma once

#include "..\Util\SpriteManager.h"
#include "States\StateManager.h"

class State{

public:
	SpriteManager spriteManager;
	StateManager *manager;

	State();
	~State();

	virtual void init() = 0;
	virtual void destroy() = 0;

	virtual void handleEvents(sf::Event event) = 0;
	virtual void update() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void draw(sf::RenderWindow *window) = 0;

	void setManager (StateManager *manager);
};