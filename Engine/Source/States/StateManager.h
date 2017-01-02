#pragma once

#include<SFML\Graphics.hpp>
#include<iostream>
#include<vector>

class State;

class StateManager{
public:
	std::vector<State*> stack;
	StateManager ();
	StateManager(StateManager *manager);
	~StateManager();

	void changeState(State *state);
	
	void popState();
	void pushState(State *state);

	void clear();
	void handleStateEvents(sf::Event event);
	void drawStates(sf::RenderWindow *window);
	void updateStates();
};