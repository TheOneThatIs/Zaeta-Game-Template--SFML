#pragma once

#include "States\State.h"
#include "UI\Button.h"

#include "Play.h"

class TitleScreen: public State {
	Button newGame;
	Button options;
	sf::Sprite titleSplash;
public:
	TitleScreen ();
	~TitleScreen ();

	void init () override;
	void destroy () override;

	void handleEvents (sf::Event event) override;
	void update () override;

	void pause () override;
	void resume () override;

	void draw (sf::RenderWindow *window) override;
};