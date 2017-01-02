#pragma once
#include "../../Engine/include/States/State.h"

class ChooseClass: public State{
	//sf::Sprite splash;
public:
	ChooseClass();
	~ChooseClass();

	void init() override;
	void destroy() override;

	void handleEvents(sf::Event event) override;
	void update() override;

	void pause() override;
	void resume() override;

	void draw(sf::RenderWindow *window) override;
};