#include "States\StateManager.h"

#include "States\State.h"

StateManager::StateManager(){

}

StateManager::~StateManager(){

}

void updateStates(){

}

void drawStates(){

}

void StateManager::changeState(State *state){
	if(!stack.empty()){
		stack.back()->destroy();
		stack.pop_back();
	}
	stack.push_back(state);
	stack.back()->init();
	stack.back()->setManager(this);
}

void StateManager::popState(){
	if(!stack.empty()){
		stack.back()->destroy();
		stack.pop_back();
	}
}

/*
Pause the state you're in and go to a new state.
*/
void StateManager::pushState(State *state){
	if(!stack.empty())
		stack.back()->pause();

	stack.push_back(state);
	stack.back()->init();
	stack.back()->setManager(this);
}

void StateManager::clear(){
	if(!stack.empty()){
		stack.back()->destroy();
		stack.pop_back();
	}
}

void StateManager::handleStateEvents(sf::Event event){
	stack.back()->handleEvents(event);
}

void StateManager::drawStates(sf::RenderWindow *window){
	for(size_t i = 0; i < stack.size(); i++){
		stack[i]->draw(window);
	}
}

void StateManager::updateStates(){
	for(size_t i = 0; i < stack.size(); i++)
		stack[i]->update();
}