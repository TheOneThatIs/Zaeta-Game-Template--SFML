#pragma once

#include "States\State.h"

#include "UI\Button.h"
#include "Util\Animation.h"

#include"..\World\MapManager.h"


//#include "..\Events\EventManager.h"

class Play: public State{
    //EventManager eventManager;

	SpriteManager spriteManager;
	MapManager mapManager;

public:
	Play();
	~Play();

	void init() override;
	void destroy() override;

	void handleEvents(sf::Event event) override;
	void update() override;

	void pause() override;
	void resume() override;

	void draw(sf::RenderWindow *window) override;
};